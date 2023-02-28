#include <windows.h>
#include <iostream>
#include <time.h>
#include "blackboard.h"
using namespace std;

// 格式化打印时间
void printTime(SYSTEMTIME time)
{
	cout << time.wYear << "年" << time.wMonth << "月" << time.wDay << "日" << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "毫秒" << endl;
}
//生成随机时间
int setDelay()
{
	srand(time(NULL) + GetCurrentProcessId());
	return rand() % 3 + 1;
}
//生成随机首字母
char setCharacter()
{
	srand(time(NULL) + GetCurrentProcessId());
	char t[] = { 'G','X','Y' };
	return t[rand() % 3];
}
int main()
{
	char producer_character;
	SYSTEMTIME current_time;
	HANDLE producer_shared_file_handle;
	LPVOID producer_map_view_of_file;
	//读取共享映射文件
	producer_shared_file_handle = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, file_name);
	if (producer_shared_file_handle == NULL)
	{
		cout << "OpenFileMapping错误  " << GetLastError() << endl;
		return 0;
	}
	producer_map_view_of_file = MapViewOfFile(producer_shared_file_handle, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (producer_map_view_of_file == NULL)
	{
		cout << "MapViewOfFile错误  " << GetLastError() << endl;
		CloseHandle(producer_shared_file_handle);
		return 0;
	}
	//获取共享缓冲区信息
	shared_memory* producer_shared_memory = (struct shared_memory*)producer_map_view_of_file;
	HANDLE producer_empty = OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE, sem_empty);
	HANDLE producer_full = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, sem_full);
	HANDLE producer_mutex = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, sem_mutex);
	//生产4次
	for (int i = 0; i < 4; i++)
	{
		int delay=setDelay() * 1000;
		Sleep(delay);
		//P(empty),P(mutex)
		WaitForSingleObject(producer_empty, INFINITE);
		WaitForSingleObject(producer_mutex, INFINITE);
		//write
		producer_character = setCharacter();
		int current_tail = producer_shared_memory->space.tail;
		producer_shared_memory->space.buffer[current_tail] = producer_character;
		producer_shared_memory->space.tail = (current_tail + 1) % buffer_size;
		producer_shared_memory->space.isEmpty = false;
		GetSystemTime(&current_time);
		cout << "生产者" << GetCurrentProcessId() << "号往缓冲区里写入字母" << producer_character << "于";
		printTime(current_time);
		cout << "缓冲区中内容为";
		current_tail = producer_shared_memory->space.tail;
		if (producer_shared_memory->space.isEmpty == true)
			cout << "空" << endl;
		else{
			int j = (current_tail - 1 >= producer_shared_memory->space.head) ? (current_tail - 1):(current_tail - 1 + buffer_size);
			for (j; j >= producer_shared_memory->space.head; j--)
			{
				cout << producer_shared_memory->space.buffer[j % buffer_size];
			}
			cout << endl;
		}
		//V(mutex),V(full)
		ReleaseSemaphore(producer_mutex,1,NULL);
		ReleaseSemaphore(producer_full, 1,NULL);
	}
	//关闭文件映射视图和共享主存句柄
	UnmapViewOfFile(producer_map_view_of_file);
	producer_shared_memory = NULL;
	CloseHandle(producer_shared_file_handle);
	return 0;
}
