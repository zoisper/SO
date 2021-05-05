#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	if(mkfifo("fifo", 0666) == -1)
		perror("mkfifo");

	char string[20] = "Ola Mundo";
	
	int fifo = open("fifo", O_WRONLY);
	write(fifo, string, 20 );
	close(fifo);

	unlink("fifo");

	return 0;
}