#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>  
#include <errno.h>

int main()
{

	int fd[2];
	int pid;
	int flag;

	flag = pipe(fd);

	if (flag<0)
	{
		perror("pipe error!");
		exit(1);
		/* code */
	}

	flag = fork();

	if (flag<0)
	{
		perror("fork error!");
		exit(1);
		/* code */
	}

	if (flag==0)//子进程
	{
		printf("child process begin to write!\n");
		close(fd[0]);//关闭读
		char * child = "hello parents \n I'm child!";
		write(fd[1],child,strlen(child)+1);

		/* code */
	}
	else//父进程
	{
		printf("parent process begin to read!\n");
		close(fd[1]);
		char msg[100];
		ssize_t r = read(fd[0],msg,sizeof(msg));
		printf("%s\n,msg");
	}

	return 0;
}