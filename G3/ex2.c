#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>


int main(){
	int ret;


	char *exec_args[] = {"ls","-l", NULL};

	//ret = execl("/bin/ls","ls","-l", NULL);

	//ret = execlp("ls","ls","-l", NULL );

	//ret = execv("/bin/ls", exec_args);

	if (fork() ==0){
		ret = execvp("ls", exec_args);
		perror("Erro de exec");
		_exit(ret);
	}

	else 
		wait(NULL);

	return 0;

}