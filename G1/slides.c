#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main ()
{

int fd1;
ssize_t res;
char buffer[8];

fd1 = open("slides.txt", O_CREAT | O_RDWR, 0600);

res = write(fd1,"abcde", 5);
res = write(fd1, "fgh",3);

lseek(fd1, 0, SEEK_SET);

res = read(fd1,&buffer, 8);

printf("%zd\n", res);

close(fd1);

return 0;

}