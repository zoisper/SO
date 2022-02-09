#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>

// O processo pai deve escrever no STDOUT o que fli esctito pelo processo filho
int main(){
	int ret;

	char *exec_args[] = {"ls","-l", NULL};

	//ret = execl("/bin/ls","ls","-l", NULL);

	//ret = execlp("ls","ls","-l", NULL );

	//ret = execv("/bin/ls", exec_args);

	ret = execvp("ls", exec_args);



	perror("Erro");
	return 0;

}