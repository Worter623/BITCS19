#include <windows.h>
#include <tchar.h>

// 共享内存大小 2048 字节
const int shared_memory_size = 2048;
// 共享缓冲文件名
TCHAR file_name[] = TEXT("Buffer");
// 4个缓冲区
const int buffer_size = 4;
// 3个生产者
const int producer_process_headid = 1;
const int producer_process_tailid = 3;
// 4个消费者
const int consumer_process_headid = 4;
const int consumer_process_tailid = 7;
// 进程数一共是7
const int process_total = 7;
// 信号量名
TCHAR sem_empty[] = TEXT("Empty");
TCHAR sem_full[] = TEXT("Full");
TCHAR sem_mutex[] = TEXT("Mutex");
// 生产者，消费者的程序名
TCHAR producer_exe_name[] = TEXT("producer.exe");
TCHAR consumer_exe_name[] = TEXT("consumer.exe");
// 生产者消费者子进程、线程的句柄集合
HANDLE created_process_handles[process_total + 1];
HANDLE created_thread_handles[process_total + 1];
// 缓冲区空间队列结构体：存放数据的数组和头尾指针、是否为空
struct shared_memory_buffer_data{
	int head;
	int tail;
	bool isEmpty;
	char buffer[buffer_size];
};
// 共享主存区结构体
struct shared_memory{
	shared_memory_buffer_data space;
	HANDLE semaphore_full;
	HANDLE semaphore_empty;
	HANDLE semaphore_mutex;
};
