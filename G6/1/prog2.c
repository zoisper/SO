#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	

	char string[20];
	
	int fifo = open("fifo", O_RDONLY);
	while(read(fifo, string, 20 ) >0)
		printf("%s\n", string);
	
	close(fifo);

	return 0;
}