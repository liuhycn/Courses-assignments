//实现进程的软中断通信
/*按Ctrl+c键,可发送SIGINT信号给当前进程*/
/*使用系统调用fork（）创建两个子程序，再用系统调用signal（）注册父进程和子进程分别对待从键盘上来的中断信号（SIGINT信号）的行为；当有中断信号后，父进程用系统调用Kill（）向两个子进程发出信号，子进程收到信号后分别输出
Child Processll is Killed by Parent!
Child Processl2 is Killed by Parent!
父进程等待两个子进程终止后，输出如下的信息后终止：
Parent process is Killed!
*/


#include<stdio.h>
#include<signal.h>
#include <stdlib.h>

int wait_mark;

void waiting()
{
	while(wait_mark==1);
}
void  stop()
{
	wait_mark=0;
}
          
int main()
{
	int p1,p2;
	while((p1=fork())==-1);//创建子进程1如出错会进入循环
	if(p1==0)
	{
                   wait_mark=1;
                   signal(SIGINT,SIG_IGN);//注册SIGINT信号发生后的行为（忽略）
                   signal(16,stop);//注册16号信号发生后的处理函数
                   waiting();
                   printf("Child Process 1 is Killed by Parent!\n");
                   exit(0);
	}
	else
	{
                   while((p2=fork())==-1);//创建子进程2如出错会进入循环
                   if(p2==0)
                   {
                      wait_mark=1;
                      signal(SIGINT,SIG_IGN);//注册SIGINT信号发生后的行为（忽略）      
                      signal(17,stop);//注册17号信号发生后的处理函数
                      waiting();

                      printf("Child Process 2 is Killed by Parent!\n");

                      exit(0);
                    }
                   else
                   {
                      wait_mark=1;
                      signal(SIGINT,stop);//注册SIGINT信号发生后的处理函数
                      waiting();
                      kill(p1,16);//发送16号信号给p1
                      kill(p2,17);//发送17号信号给p1
                      wait(0);
                      wait(0);
                      printf("Parent Process is Killed!\n");
                      exit(0);
                   }
           }
}
           

