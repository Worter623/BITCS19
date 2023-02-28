#include <windows.h>
#include <iostream>
#include "blackboard.h"
using namespace std;

// 格式化打印时间
void printTime(SYSTEMTIME time)
{
	cout << time.wYear << "年" << time.wMonth << "月" << time.wDay << "日" << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "毫秒" << endl;
}
// 创建进程
bool CreateProcess(int process_id)
{
	bool create_process_ok;
	SYSTEMTIME c_time;
	STARTUPINFO si;   //存储新进程启动信息的指针
	PROCESS_INFORMATION pi;  //存储新进程信息（句柄）
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	memset(&pi, 0, sizeof(PROCESS_INFORMATION));

	if (process_id >= producer_process_headid && process_id <= producer_process_tailid)
	{//创建生产者
		create_process_ok = CreateProcess(producer_exe_name, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		if (!create_process_ok)
		{
			cout << "生产者" << process_id << "创建错误  " << GetLastError() << endl;
			return false;
		}
		GetSystemTime(&c_time);
		cout << "生产者" << process_id << "号PID为"<<GetProcessId(pi.hProcess)<<"创建成功于";
		printTime(c_time);
	}
	else {//创建消费者
		create_process_ok = CreateProcess(consumer_exe_name, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		if (!create_process_ok)
		{
			cout << "消费者" << process_id << "创建错误  " << GetLastError() << endl;
			return false;
		}
		GetSystemTime(&c_time);
		cout << "消费者" << process_id << "号PID为"<<GetProcessId(pi.hProcess)<<"创建成功于";
		printTime(c_time);
	}
	created_process_handles[process_id] = pi.hProcess;
	created_thread_handles[process_id] = pi.hThread;
	return true;
}

int main()
{
	int i = 1;
	SYSTEMTIME current_time;
	HANDLE shared_file_handle;
	LPVOID map_view_of_file;

	//程序开始 打印
	GetSystemTime(&current_time);
	cout << "主程序开始于 : ";
	printTime(current_time);

	//在进程中创建一个文件映射对象，模拟共享内存区
	shared_file_handle = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, shared_memory_size, file_name);
	if (shared_file_handle == NULL)
	{
		cout << "CreateFileMapping错误  " << GetLastError() << endl;
		return 0;
	}
	//在文件映射上创建物理映射，映射到这个程序的物理地址空间，返回映射视图文件的开始地址值
	map_view_of_file = MapViewOfFile(shared_file_handle, FILE_MAP_ALL_ACCESS, 0, 0, shared_memory_size);
	if (map_view_of_file == NULL)
	{
		cout << "MapViewOfFile错误  " << GetLastError() << endl;
		CloseHandle(shared_file_handle);
		return 0;
	}
	//映射视图文件的开始地址值设置为共享缓冲区的开始地址 初始化共享缓冲区
	shared_memory* p_shared_memory = (struct shared_memory*)map_view_of_file;
	p_shared_memory->space.head = 0;
	p_shared_memory->space.tail = 0;
	p_shared_memory->space.isEmpty = true;
	HANDLE semaphore_empty = CreateSemaphore(NULL, buffer_size, buffer_size, sem_empty);
	HANDLE semaphore_full = CreateSemaphore(NULL, 0, buffer_size, sem_full);
	HANDLE semaphore_mutex = CreateSemaphore(NULL, 1, 1, sem_mutex);
	//创建进程
	while (i < process_total + 1) {
		bool ok = CreateProcess(i++);
		if (!ok)
		{
			CloseHandle(shared_file_handle);
			return 0;
		}
	}
	//等待子进程返回
	for (int j = 1; j < process_total + 1; j++) {
		WaitForSingleObject(created_process_handles[j], INFINITE);
		CloseHandle(created_process_handles[j]);
		CloseHandle(created_thread_handles[j]);
	}
	//关闭文件映射上的视图的占用
	UnmapViewOfFile(map_view_of_file);
	p_shared_memory = NULL;
	CloseHandle(shared_file_handle);
	GetSystemTime(&current_time);
	cout << "主程序结束于 : ";
	printTime(current_time);
	return 0;
}
