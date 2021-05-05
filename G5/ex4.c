#include<unistd.h>


int main(){


	int fildes[2];
	
	pipe(fildes);

	if (fork() == 0)
	{

		close(fildes[0]);
		dup2(fildes[1],1);
		execlp("ls","ls", "/etc", NULL);
		_exit(0);

	}
	else
	{
		close(fildes[1]);
		dup2(fildes[0],0);

		execlp("wc", "wc", "-l", NULL);
	}




return 0;

}