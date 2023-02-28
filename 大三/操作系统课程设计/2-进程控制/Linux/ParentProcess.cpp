#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char const* argv[])
{
	struct timeval childpStart, childpEnd;
	pid_t pid = fork();
	if (pid < 0) {
		printf("Failed to create child process");
		return 0;
	}
	else if (pid == 0) {
		if (execv(argv[1], NULL) < 0)
		{
			printf("Failed to open child process");
			return 0;
		}
	}
	else
	{
		gettimeofday(&childpStart, NULL);
		wait(0);
		gettimeofday(&childpEnd, NULL);
		printf("子进程开始于%ld秒%ld毫秒\n", childpStart.tv_sec, childpStart.tv_usec);
		printf("子进程结束于%ld秒%ld毫秒\n", childpEnd.tv_sec, childpEnd.tv_usec);
		float timecost = (childpEnd.tv_sec - childpStart.tv_sec) * 1000 + (childpEnd.tv_usec - childpStart.tv_usec) / 1000;
		printf("子进程运行了%f毫秒\n",timecost);
	}
	return 0;
}
