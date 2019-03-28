#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#define MSGKEY 75
typedef struct Node
{
	int flag;//1:help,2:check login,3:using for a/b/c,4:assess,5 conInfo,6;ending
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
};
char assess[5][10]={"perfect","good","normal","bad","terrible"};
void welcome()
{   
	puts("============================================");
	printf("\n");
    puts("                  WELCOME!                  ");
    puts("   Enter '1' : help   Enter '2': user login ");
    puts("============================================");
	printf("\n");
};
void servey()
{	
	struct msgform msg;
	int msgqid;
	int summoney,shopmoney,outmoney,inmoney;
	msgqid=msgget(MSGKEY,0777);
	msg.node.flag=3;
	msgsnd(msgqid,&msg,sizeof(msg.node),0);

	summoney=msg.node.summoney;
	shopmoney=msg.node.shopmoney;
	outmoney=msg.node.outmoney;
	inmoney=msg.node.inmoney;
	puts("============================================");
	puts("        STAR USING         ");
	printf("\n");
	puts("============================================");
	printf("\n");
	//printf("Your remaining sum is %d :,summoney");
	printf(" a : shopping use.\n");
	printf(" b : you want to draw your money out.\n");
	printf(" c : you want to save your money.\n");
	puts("============================================");   
	printf("\n");
}
void ending()
{
 struct msgform msg;
		 int msgqid;
	   	 msgqid = msgget(MSGKEY, 0777);
		 msg.node.flag=6;
                 msgsnd(msgqid,&msg,sizeof(msg.node),0);
	puts("============================================");
    puts("       **    **                       ");
    puts("     ****  *****                     "); 
    puts("    **************                   "); 
    puts("     ************                   "); 
    puts("      **********          ");
    puts("       *******        ");
    puts("         ****            ");
    puts("           **                ");
    puts("            *                     ");
    puts("              *                   ");
    puts("                *                    ");
    puts("                  *                  ");
    puts("                    *                ");
    puts("                      *              ");
    puts("                        *            ");
  printf("                          * 　　　　　 "); 
    puts("                            *        ");
	puts("            THANK YOU FOR COMING!            ");
	puts("============================================");
}
void wait()
{
	puts("============================================");
}
void clogin()
{

	char name[20],psword[20];
	int count=0;
	struct msgform msg;
	int msgqid;
	msgqid=msgget(MSGKEY,0777);
	msg.node.flag=2;
	msg.mtype=1;
	while(1)
	{
printf("                 login              \n");
puts("============================================");
		puts("please enter your username:");
		scanf("%s",name);
		puts("please enter your password:");
		scanf("%s",psword);
		strcpy(msg.node.username,name);
		strcpy(msg.node.password,psword);
		msgsnd(msgqid,&msg,sizeof(msg.node),0);
		msgrcv(msgqid, &msg, sizeof(msg.node), 1, 0);
      		  int ifright;
		ifright=msg.node.ifright;
	if(ifright == 0){
			puts("incorrect username or password,pease check again");
			if(++count >= 3)	
				wait();
		}
		else 
		{
			puts("login success!");
puts("============================================");
			break;
		}
	}
	servey();
}
void cassess()
{ 
	puts("============================================");
        puts("                comment                     ");
	puts("============================================");
	puts("you think the system is :");
	puts(" 1 :perfect  2 :good  3 :normal  4 :bad  5 :terrible ");
	puts("please enter the number 1~5 to comment :");
	int assess;
	scanf("%d",&assess);
    struct msgform msg;					
    int msgqid;
	msgqid = msgget(MSGKEY, 0777);
	msg.node.flag=4;
	msg.mtype=1;
	msg.node.comment=assess;
	msgsnd(msgqid,&msg,sizeof(msg.node),0);
}
main()
{

MPAGE: welcome();
	   char str[10];
	   scanf("%s",str);
	 if(str[0]=='1')   // help
	 {
           struct msgform msg;
    	   int msgqid;
	       msgqid=msgget(MSGKEY,0777);	//创建消息队列
	       msg.node.flag=1;
		   strcpy(msg.node.mtext,str);
		   msg.mtype=1;
		   msgsnd(msgqid,&msg,sizeof(msg.node),0);
		   msgrcv(msgqid,&msg,sizeof(msg.node),1,0);
		   printf("%s\n",msg.node.mtext);
		   printf("Enter r return to the main page\n");
		   char s[2];
		   while(s[0]!='r')
   		   {
 		   	scanf("%s",s);
 		   }
puts("============================================");
		   goto MPAGE;
    
	 }

  	if(str[0] == '2')
	{
		 clogin();
SERVEY: servey();
	     char op[3][3];
		 int number[3];
		 int kind=0;
		 int summoney=0;
		 int amoney=0;
		 int cmoney=0;
		 int bmoney=0;
		 struct msgform msg;
		 int msgqid;
	   	 msgqid = msgget(MSGKEY, 0777);
		 msg.node.flag=5;
puts("            using\n");
		 while(1)
		 {

puts("============================================");
             printf("please enter a letter to chose servey,or you can enter 'q' to exit :");
CHOSE:            scanf("%s",op[kind]);
			 if(op[kind][0]!='a' && op[kind][0]!='b' && op[kind][0]!='c' && op[kind][0]!='q')
{
				 printf("ERROR! Please check and try again");
			 goto CHOSE;
		 }
		 if(op[kind][0]=='q')
		 {
			 msg.node.check[0]='q';
			 break;
		 }
		 if(op[kind][0]=='a')
		 {
			 msg.node.check[1]='a';
     				printf("you want to use money for shopping is :\n");
             scanf("%d",&number[kind]);
			amoney=number[kind];
			 msg.node.shopmoney=amoney;
		 }
		 if(op[kind][0]=='b')
		 {
			 msg.node.check[2]='b';
			 	printf("you want to draw out :\n");
			 scanf("%d",&number[kind]);
			bmoney=number[kind];
			 msg.node.outmoney=bmoney;
		 }

		 if(op[kind][0]=='c')
		 {
			 msg.node.check[3]='c';
				printf("you want to save money :\n");
			 scanf("%d",&number[kind]);
			cmoney=number[kind];
             msg.node.inmoney=cmoney;
		 }
		kind++;
		 msg.node.summoney=msg.node.inmoney-msg.node.shopmoney-msg.node.outmoney;
	 }
	printf("the remain you have is :%d\n",msg.node.summoney);
	if(msg.node.summoney<=0)
	printf("you need to save more money quickly,or you will be impose a fine!\n");
	puts("============================================");
    	int l;
	puts("            ensure");

	msg.mtype=1;
	msgsnd(msgqid,&msg,sizeof(msg.node),0);
	printf("please enter 'y' to make sure the check is right :\n");
     char end[2];
	 while(1)
	 {
		 scanf("%s",end);
			 if(end[0]=='Y' || end[0]=='y')
			 {
puts("============================================");
				 cassess();
				 ending();
				 sleep(3);
				 goto MPAGE;
			 }
	 }
		 goto SERVEY;
	}
	else goto MPAGE;	

}
