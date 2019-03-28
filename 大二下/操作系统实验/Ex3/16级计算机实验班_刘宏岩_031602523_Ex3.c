#include <stdio.h> 
#include <unistd.h> 
#include <sys/ipc.h>  
#include <sys/sem.h>  
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <sys/shm.h>
int *buf;
int val;
int shareid;
int in=0;
int out=0;
int empty,full,mutex1,mutex2;
int flag = 0;
int initSem(int Val) 
{
	int id = 0;				    //淇″彿閲忔爣璇?
	int flag = 0;				    //鍒濆鍖栨垚鍔熸爣蹇?
	id = semget(IPC_PRIVATE,1,IPC_CREAT|0666);  //鐢宠淇″彿閲?
	flag = semctl(id,0,SETVAL,Val);
	if(flag < 0)
	{
		printf("Sem inital failed");
		return -1;
	}
	else
	{
		printf("Sem inital successed with id%d\n",flag);
		return id;
	}
}
void pSem(int id)
{
	int flag = 0;
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	flag = semop(id,&sops,1);
	if(flag < 0)
	{
		printf("P operation failed\n");
	}
	else
	{
		printf("P operation successed\n");
	}
	return;
}
void vSem(int id)
{
	int flag = 0;
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	flag = semop(id,&sops,1);
	if(flag < 0)
	{
		printf("V operation failed\n");
	}
	else
	{
		printf("V operation successed\n");
	}
	return;
}
void freesem(int id)
{
	int flag = 0;
	flag = semctl(id,0,IPC_RMID);
	if(flag < 0)
	{
		printf("Sem free failed\n");
	}
	else
	{
		printf("Sem free successed\n");
	}
	return;
}
void init()
{
	printf("plz intput the size of storehouse ");
	scanf("%d",&val);
    	shareid=shmget(0,sizeof(int)*(val),IPC_CREAT|0666);//共享区标识 
    	buf=(int*)shmat(shareid,0,0);//将共享存储区映射到用户进程空间
    	empty=initSem(val);
    	full=initSem(0);
    	mutex1=initSem(1);//生产者互斥
    	mutex2=initSem(1);//消费者互斥
	printf("Initialization success!\n");
}
void pro(int flag)
{
	printf("P started with id %d\n",getpid());
	int set = buf[in];
	printf("empty's ");
	pSem(empty);
	printf("mutex1's ");
	pSem(mutex1);
	buf[in]=1;
    	in=(in+1)%val;
    	printf("P (id:%d) put an item to %d\n",getpid(),set);
	printf("mutex1's ");
    	vSem(mutex1);
	printf("full's ");
    	vSem(full);
}
void con(int flag)
{
    	printf("C started with id %d\n",getpid());
    	int set=buf[out];//从0开始取 
	printf("full's ");
    	pSem(full);
	printf("mutex2's ");
    	pSem(mutex2);
    	buf[out]=0;//取出一个物品
    	out=(out+1)%val;
    	printf("C (id:%d) put an item to %d\n",getpid(),set);
	printf("mutex2's ");
    	vSem(mutex2);
	printf("empty's ");
    	vSem(empty);
}
int main()
{
	init();
	while(1)
	{
		flag = fork();
		if(flag==0)//子进程 
     		{
       			if(rand()%2)//0，1  
         			pro(flag);
       			else
         			con(flag);
      			break;
      		}
     		else //父进程
       			sleep(rand()%3);
	}
	return 0;
}
