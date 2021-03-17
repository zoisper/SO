#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int i = 0, status;

	if( (pid = fork()) == 0)
	{
		printf("filho - pid: %d\n", getpid());
		printf("filho - pid pai: %d\n", getppid());

	}

	else
	{
		sleep(2);

		printf("pai - pid do filho: %d\n", pid);
		printf("pai - pid: %d\n", getpid());
		printf("pai - pid pai: %d\n", getppid());

	}

	return 0;
}
