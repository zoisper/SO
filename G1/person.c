#include "person.h"
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define filename "xyz"



int new_person (char* name, int age)
{
	int res;
	Person p;
	
	strcpy(p.name,name);
	p.age = age;
	
	int fd = open(filename, O_CREAT | O_APPEND| O_WRONLY, 0600);


	//lseek(fd, 0, SEEK_END); //nao necessario por causa do append
	res = write(fd, &p, sizeof(Person));
	
	if(res<0)
	{
		perror("Error creating person");
		return -1;
	}
	close(fd);
}

int person_change_age (char* name, int age)
{
	Person p;
	int bytes_read, res;
	int fd = open(filename, O_RDWR, 0600);
	if (fd<0)
	{
		perror("Error creating person");
		return -1;
	}
	
	
	while((bytes_read = read(fd, &p, sizeof(Person)))>0)
	{
		if (strcmp(p.nome, nome) ==0)
		{
			p.age = age;
			res = lseek(fd, -sizeof(Person), SEEK_CUR)
			if(res<0)
			{
				perror("Error creating person");
				return -1;
			}

			res = write(fd, &p, sizeof(Person));
			
			if(res<0)
			{
				perror("Error creating person");
				return -1;
			}

			colse(fd);
			return 1;

		}
	}

}

int new_person_v2 (char* name, int age)
{
	int res;
	Person p;
	
	strcpy(p.name,name);
	p.age = age;
	
	int fd = open(filename, O_CREAT | O_APPEND| O_WRONLY, 0600);


	//lseek(fd, 0, SEEK_END); //nao necessario por causa do append
	res = write(fd, &p, sizeof(Person));
	
	if(res<0)
	{
		perror("Error creating person");
		return -1;
	}

	int seek_res = lseek(fd, -sizeof(Person), SEEK_CUR);
	if (seek_res <0)
	{
		perror("Error lseek");
		return -1;
	}
	close(fd);
	return seek_res/sizeof(Person);
}

int person_change_age_v2 (long pos, int age)
{
	Person p;
	int bytes_read, res;
	int fd = open(filename, O_RDWR, 0600);
	if (fd<0)
	{
		perror("Error creating person");
		return -1;
	}

	res = lseek(fd, (pos-1)*sizeof(Person),SEEK_SET);
	if(res<0)
	{
		perror("Error lseek");
		return -1;
	}
	
	res = read(fd, &p, sizeof(Person));

	if(res<0)
	{
		perror("Error reading person");
		return -1;
	}
	p.age = age;
	
	res = lseek(fd, -sizeof(Person), SEEK_CUR);
	if(res<0)
	{
		perror("Error lseek");
		return -1;
	}

	res = write(fd, &p, sizeof(Person));
			
	if(res<0)
	{
		perror("Error write");
		return -1;
	}
	colse(fd);
	return 0;
}