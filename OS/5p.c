#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<unistd.h>

int main()
{
	const int size=4096;
	char *name="OS";
	char *message_0="Hello";
	char *message_1="world";

	int fd;
	char *ptr;
	fd=shm_open(name,O_CREAT|O_RDWR,0666);
	ftruncate(fd,size);
	ptr = (char*)mmap(0,size,PROT_WRITE,MAP_SHARED,fd,0);
	sprintf(ptr,"%s",message_0);
	ptr+=strlen(message_0);
	sprintf(ptr,"%s",message_1);
	ptr+=strlen(message_1);
	return 0;
}
