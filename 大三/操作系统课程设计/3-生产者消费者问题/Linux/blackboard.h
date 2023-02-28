#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
// 4个缓冲区
const int buffer_size = 4;
// 信号量id
const int empty_id = 0;
const int full_id = 1;
const int mutex_id = 2;
// 缓冲区空间队列结构体：存放数据的数组和头尾指针、是否为空
struct shared_memory_buffer_data {
	int head;
	int tail;
	bool isEmpty;
	char buffer[buffer_size];
};
// 自定义一个用于初始化信号量的union semun
union semun {
	int val;
	struct semid_ds* buf;
	unsigned short* array;
};