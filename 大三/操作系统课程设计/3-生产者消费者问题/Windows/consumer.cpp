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
int main()
{
	char consumer_character;
	SYSTEMTIME current_time;
	HANDLE consumer_shared_file_handle;
	LPVOID consumer_map_view_of_file;
	//读取共享映射文件
	consumer_shared_file_handle = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, file_name);
	if (consumer_shared_file_handle == NULL)
	{
		cout << "OpenFileMapping错误  " << GetLastError() << endl;
		return 0;
	}
	consumer_map_view_of_file = MapViewOfFile(consumer_shared_file_handle, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (consumer_map_view_of_file == NULL)
	{
		cout << "MapViewOfFile错误  " << GetLastError() << endl;
		CloseHandle(consumer_shared_file_handle);
		return 0;
	}

	//获取共享缓冲区信息
	shared_memory* consumer_shared_memory = (struct shared_memory*)consumer_map_view_of_file;
	HANDLE consumer_empty = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, sem_empty);
	HANDLE consumer_full = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, sem_full);
	HANDLE consumer_mutex = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, sem_mutex);
	//消费3次
	for (int i = 0; i < 3; i++)
	{
		Sleep(setDelay() * 1000);
		//P(full),P(mutex)
		WaitForSingleObject(consumer_full, INFINITE);
		WaitForSingleObject(consumer_mutex, INFINITE);
		//read
		consumer_character = consumer_shared_memory->space.buffer[consumer_shared_memory->space.head];
		consumer_shared_memory->space.head = (consumer_shared_memory->space.head + 1) % buffer_size;
		if (consumer_shared_memory->space.head == consumer_shared_memory->space.tail)
			consumer_shared_memory->space.isEmpty = true;
		GetSystemTime(&current_time);
		cout << "消费者" << GetCurrentProcessId() << "号从缓冲区里取出字母" << consumer_character << "于";
		printTime(current_time);
		cout << "缓冲区中内容为";
		if (consumer_shared_memory->space.isEmpty == true)
			cout << "空" << endl;
		else {
			int j = (consumer_shared_memory->space.tail - 1 >= consumer_shared_memory->space.head) ? (consumer_shared_memory->space.tail - 1) : (consumer_shared_memory->space.tail - 1 + buffer_size);
			for (j; j >= consumer_shared_memory->space.head; j--)
			{
				cout << consumer_shared_memory->space.buffer[j % buffer_size];
			}
			cout << endl;
		}
		//V(mutex),V(empty)
		ReleaseSemaphore(consumer_mutex, 1, NULL);
		ReleaseSemaphore(consumer_empty, 1, NULL);
	}
	//关闭文件映射视图和共享主存句柄
	UnmapViewOfFile(consumer_map_view_of_file);
	consumer_shared_memory = NULL;
	CloseHandle(consumer_shared_file_handle);
	return 0;
}
