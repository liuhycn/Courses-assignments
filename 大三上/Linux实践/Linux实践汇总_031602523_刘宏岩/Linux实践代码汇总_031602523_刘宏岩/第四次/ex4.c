#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#define BUFFER_SIZE 102400
int main(int argc,char * argv[])
{
	int fd=-1;
	int fw=-1;
	struct stat statbuff;
	int size,write_count;
	char buffer[BUFFER_SIZE];
	int read_bytes;
	if((fd=open(argv[1],O_RDWR))>0)
	{
		printf("File1 open success!!\n");
	}
	if(( fw=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))>0)
	{
		printf("File2 establish sucess!!\n");
	}
	stat(argv[1],&statbuff);
	size=statbuff.st_size;
	write(fw,"liuhy",5);
	read_bytes=read(fd,buffer,size/2);
	printf("The size is:%d\n",size);
	write_count=write(fw,buffer,size/2);
	write(fw,"031602523",9);
	read(fd,buffer,size/2);
	write(fw,buffer,size/2);
	write(fw,"hahahaha",8);
	close(fw);
	close(fd);
	exit(0);
}
