#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#define MSGKEY 75
#define MSFKE
typedef struct Node
{
	int flag;//1:help,2:check,3:using for a/b/c,4:assess,5 conInfo
	char mtext[5001];
	char username[20];
	char password[20];
	int inmoney,outmoney,shopmoney;
int summoney;
	int amoney,bmoney,cmoney;
	int ifright;
	int comment;
	int comArray[5];
	char check[3];
}Node;
struct msgform
{
	long mtype;
	Node node;
}msg;
int assess[5]={0};
char username[]="xumf";
char password[]="123456";
int msgqid;
char help[5001];
void helpmessage()
{
	char fn[]="help.dat";
	FILE *fd;
	fd=fopen(fn,"r");
	if(fd==NULL)
	{
		printf("ERROR!\n");
		return;
	}
	int i=fread(help,1,5001,fd);
	help[i]=0;
	fclose(fd);
}
main()
{
    int j;
    extern cleanup();
	for(j=0;j<20;++j)
		signal(j,cleanup);
    msgqid = msgget(MSGKEY, 0777|IPC_CREAT);
	for(;;)
	{
         msgrcv(msgqid, &msg, sizeof(msg.node), 1, 0);
		 if(msg.node.flag==1)
		 {
	puts("============================================");
	puts("            用户请求帮助\n");
	puts("============================================");
			 printf("the client is asking for help!\n");
	puts("============================================");
			 helpmessage();
			 strcpy(msg.node.mtext,help);
			 msg.mtype=1;
			 msgsnd(msgqid,&msg,sizeof(msg.node),0);
		 }
		 else if(msg.node.flag==2)
		 {
	puts("============================================");
	puts("            用户正在登录\n");
	puts("============================================");
			 printf("the client is trying to login!\n");
			 msg.mtype=1;
			 if(strcmp(msg.node.username,username)!=0)
			 {
				 msg.node.ifright=0;
				 printf("login fail! username error.\n");
	puts("============================================");
			 }
			 else if(strcmp(msg.node.password,password)!=0)
			 {
				 msg.node.ifright=0;
				 printf("login fail! password error.\n");
	puts("============================================");
			 }
			else 
			
			{msg.node.ifright = 1;puts("login sucess");}
			msgsnd(msgqid, &msg, sizeof(msg.node), 0);
		}
		 else if(msg.node.flag==3)
		 {
	puts("============================================");
	puts("            用户正在使用中\n");
	puts("============================================");
			 printf("the client is make his/her choice for servey.\n");
        puts("============================================");
		 }
		 else if(msg.node.flag==4)
		 {
puts("============================================");
puts("            用户正在评价\n");
puts("============================================");
			 printf("the client gave us a comment.\n");
puts("============================================");
			 assess[0]++;
			 assess[msg.node.comment]++;
		 }
		 else if(msg.node.flag==5)
		 {
puts("============================================");
puts("            用户此时的信息\n");
puts("============================================");
			 printf("the client's information of his/her .\n");
			 int shm,om,im,sm;
			 sm=msg.node.summoney;
			 shm=msg.node.shopmoney;
			 im=msg.node.inmoney;
			 om=msg.node.outmoney;
             printf("the client's summoney is :%d yuan\n",sm);
			 printf("the client's shopmoney is :%d yuan\n",shm);
			 printf("the client's outmoney is :%d yuan\n",om);
			 printf("the client's inmoney is :%d yuan\n",im);
	puts("============================================");
		 }
		else if(msg.node.flag==6)
	{
	puts("============================================");
	puts("            用户正在退出\n");
	puts("============================================");
			printf("the client is leaving.\n");
	puts("============================================");	}
}
}
cleanup(){
	msgctl(msgqid, IPC_RMID, 0);
	exit(0);
}
