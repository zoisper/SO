#include<unistd.h>
#include<fcntl.h>


#define MAXBUFFER 10000

int main()
{

	ssize_t res;
	char buff;


	while ((res=read(0, &buff, 1)) != 0)
		write(1, &buff, 1);
	

	
	return 0;


}