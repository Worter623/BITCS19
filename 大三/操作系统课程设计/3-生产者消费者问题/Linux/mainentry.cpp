#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <iostream>
#include "blackboard.h"
using namespace std;
//生成随机时间
int setDelay(int pid)
{
	srand(time(NULL) + pid);
	return rand() % 3 + 1;
}
//生成随机首字母
char setCharacter(int pid)
{
	srand(time(NULL) + pid);
	char t[] = { 'G','X','Y' };
	return t[rand() % 3];
}
//P操作
void P(int sem_id, int sem_count) {
	struct sembuf sem_buffer;
	sem_buffer.sem_num = sem_count;
	sem_buffer.sem_op = -1;
	sem_buffer.sem_flg = 0;
	semop(sem_id, &sem_buffer, 1);
}
//V操作
void V(int sem_id, int sem_count) {
	struct sembuf sem_buffer;
	sem_buffer.sem_num = sem_count;
	sem_buffer.sem_op = 1;
	sem_buffer.sem_flg = 0;
	semop(sem_id, &sem_buffer, 1);
}
//打印缓冲区内容
void PrintBuffer(struct shared_memory_buffer_data* p_shared_memory)
{
	if (p_shared_memory->isEmpty == true)
		cout << "-";
	else {
		int current_tail = p_shared_memory->tail;
		int i = (current_tail - 1 >= p_shared_memory->head) ? (current_tail - 1) : (current_tail - 1 + buffer_size);
		for (i; i >= p_shared_memory->head; i--)
		{
			cout << p_shared_memory->buffer[i % buffer_size];
		}
	}
	cout << endl;
}
//生产者函数
void Produce(int shared_memory_id, int sem_id, int producer_id,shared_memory_buffer_data* p_shared_memory)
{
	pid_t current_pid = getpid();
	sleep(setDelay(current_pid));
	char character = setCharacter(current_pid);
	//P(empty),P(mutex)
	P(sem_id, empty_id);
	P(sem_id, mutex_id);
	//write
	p_shared_memory->buffer[p_shared_memory->tail] = character;
	p_shared_memory->tail = (p_shared_memory->tail + 1) % buffer_size;
	p_shared_memory->isEmpty = false;
	//打印
	cout << "Producer number " << producer_id << " put " << character ;
	cout << "  buffer:";
	PrintBuffer(p_shared_memory);
	//V(mutex),V(full)
	V(sem_id, mutex_id);
	V(sem_id, full_id);
}
//消费者函数
void Consume(int shared_memory_id, int sem_id, int consumer_id,shared_memory_buffer_data* p_shared_memory)
{
	pid_t current_pid = getpid();
	sleep(setDelay(current_pid));
	//P(full),P(mutex)
	P(sem_id, full_id);
	P(sem_id, mutex_id);
	//read
	char character = p_shared_memory->buffer[p_shared_memory->head];
	p_shared_memory->head = (p_shared_memory->head + 1) % buffer_size;
	if (p_shared_memory->head == p_shared_memory->tail)
		p_shared_memory->isEmpty = true;
	//打印
	cout << "-----consumer number " << consumer_id << " took " << character;
	cout << "  buffer:";
	PrintBuffer(p_shared_memory);
	//V(mutex),V(empty)
	V(sem_id, mutex_id);
	V(sem_id, empty_id);
}
int main()
{
	int shared_memory_id;
	int sem_id = -1;
	union semun sem_union;
	//创建共享缓冲区
	struct shared_memory_buffer_data* p_shared_memory;
	if ((shared_memory_id = shmget(IPC_PRIVATE, buffer_size, IPC_CREAT | 0600)) < 0) {
		cout << "shmget failed" << endl;
		return 0;
	}
	if ((p_shared_memory = (struct shared_memory_buffer_data*)shmat(shared_memory_id, NULL, 0)) == (void*)-1) {
		cout << "shmat failed" << endl;
		return 0;
	}
	//初始化共享内存区
	p_shared_memory->head = 0;
	p_shared_memory->tail = 0;
	p_shared_memory->isEmpty = true;
	//创建信号量并初始化
	if ((sem_id = semget(IPC_PRIVATE, 3, 0600)) == -1) {
		cout << "semget failed" << endl;
		return 0;
	}
	sem_union.val = buffer_size;
	if (semctl(sem_id, empty_id, SETVAL, sem_union) == -1)
	{
		cout << "initialize empty semaphore failed" << endl;
		return 0;
	}
	sem_union.val = 0;
	if (semctl(sem_id, full_id, SETVAL, sem_union) == -1)
	{
		cout << "initialize full semaphore failed" << endl;
		return 0;
	}
	sem_union.val = 1;
	if (semctl(sem_id, mutex_id, SETVAL, sem_union) == -1)
	{
		cout << "initialize mutex semaphore failed" << endl;
		return 0;
	}
	//创建生产者进程
	for (int i = 0; i < 3; i++)
	{
		pid_t producer_pid = fork();
		if (producer_pid < 0)
		{
			cout << "initialize producer process " << i << " failed" << endl;
			return 0;
		}
		else if (producer_pid == 0) {
			cout << "PRODUCER number " << i + 1 << " born  PID:" << getpid() << endl;
			for (int j = 0; j < 4; j++)
				Produce(shared_memory_id,sem_id, i + 1, p_shared_memory);
			return 0;
		}
	}
	//创建消费者进程
	for (int i = 4; i < 8; i++)
	{
		pid_t consumer_pid = fork();
		if (consumer_pid < 0)
		{
			cout << "initialize consumer process " << i << " failed" << endl;
			return 0;
		}
		else if (consumer_pid == 0) {
			cout << "CONSUMER number " << i << " born  PID:" << getpid() << endl;
			for (int j = 0; j < 3; j++)
				Consume(shared_memory_id,sem_id, i, p_shared_memory);
			return 0;
		}
	}
	//等待子进程返回
	while (wait(0) > 0);
	shmdt(p_shared_memory);
	return 0;
}
