#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	int res = 0;
	int i_fd = open(argv[1], O_CREAT | O_RDONLY);
	int o_fd = open(argv[2], O_CREAT | O_WRONLY, 0666);
	int e_fd = open("erro.txt", O_CREAT | O_WRONLY, 0666);

	res = dup2(i_fd,0);
	res = dup2(o_fd,1);
	res = dup2(e_fd,2);


	close(i_fd);
	close(o_fd);
	close(e_fd);
	
	execlp(argv[3], argv[3], NULL);

	


	return 0;
}