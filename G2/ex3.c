#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>


int main(){

	int i, status;
	pid_t pid;
	
	for(i = 0; i<10; i++){
		
		if((pid = fork()) == 0 ){
			//printf("filho - pid: %d\n", getpid());
			//printf("filho - pid pai : %d\n", getppid());
			_exit(i);

		}
		else{
			pid = wait(&status);
			printf("filho - pid: %d - ordem: %d\n", pid, WEXITSTATUS(status));

		}
	
	}
		
	return 0;
}