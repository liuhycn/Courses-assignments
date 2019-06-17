#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLENGTH   101
#define MAX_LINE 1024
#define DEFAULT_PORT 8000

using namespace std;

struct score_list
{
	string name;
	int bestscore;
}s_list[MAX_LINE];

int in_list(string s,int n)
{
	for(int i=0;i<n;i++)
	{
		if(s_list[i].name == s)
		{
			return i;
		}
	}
	return -1;
}

int cmp( const void *p1 ,const void *p2)
{
	struct score_list *a= (struct score_list *)p1;
	struct score_list *b= (struct score_list *)p2;
	int result=0;
	if(a->bestscore > b->bestscore)
		return -1;
	else if(a->bestscore < b->bestscore)
		return 1;
	else
		return 0;
} 


void generateboard(char * str,int n)
{
	int i = 0;
	string temp = "";
	char ctemp[MAX_LINE];
	memset(str,0,sizeof(str));
	strcpy(str,"**************Leaderboard*************\n");
	for(i=0;i<n;i++)
	{
		ctemp[0] = (i+1) + '0';
		ctemp[1] = '.';
		ctemp[2] = '\0';
		strcat(str,ctemp);
		memset(ctemp,0,sizeof(ctemp));
		//printf("%s\n",str);
		strcat(str,(s_list[i].name+" : ").c_str());
		//printf("%s\n",str);
		sprintf(ctemp, "%d",s_list[i].bestscore);
		ctemp[strlen(ctemp)] = '\n';
		strcat(str,ctemp);
		//printf("%s\n",str);
	}
	memset(ctemp,0,sizeof(ctemp));
	strcpy(ctemp,"**************************************\n");
	strcat(str,ctemp);
}



int main()
{
	int socket_fd = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	int cnt = 0;
	int connect_fd = 0;
	int flag = 0;
	string s_score = "";
	string username = "";
	struct sockaddr_in servaddr;
	char buffer[MAX_LINE];
	char sendbuf[MAX_LINE];

	if( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
	{
		printf("create socket error!\n");  
		exit(1);
	}

	//init
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//系统自动获取本机的IP地址。  
	servaddr.sin_port = htons(DEFAULT_PORT);//设置的端口为DEFAULT_PORT  

	//将本地地址绑定到所创建的套接字上 
	if( bind(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
	{
		printf("Bind error!\n");
		exit(1);
	}

	//listen
	if( listen(socket_fd, 10) == -1)
	{
		printf("listen socket error!\n");
		exit(1);
	}
	printf("******Waiting for a new player's request******\n");

	while(1)
	{
		if( (connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL)) == -1)
		{
			printf("Accept error!\n");
			continue;
		}


			//接受客户端传过来的数据
		n = recv(connect_fd, buffer, MAX_LINE, 0);
		buffer[n] = '\0';
			//printf("recv msg from client: %s\n", buffer);


		while(buffer[i] >= '0' && buffer[i] <= '9')
		{
			s_score += buffer[i];
			i++;
		}
		while(i<strlen(buffer))
		{
			username += buffer[i];
			i++;
		}

		memset(buffer, 0, sizeof(buffer));
		printf("Successfully received scores from the client\n");
		printf("recv score : %s\n",s_score.c_str());
		printf("recv username : %s\n",username.c_str());

	
		flag = in_list(username,cnt);
		if( flag == -1 )
		{
			s_list[cnt].name = username;
			s_list[cnt].bestscore = atoi(s_score.c_str());
			cnt++;
		}
		else
		{
			if(atoi(s_score.c_str()) > s_list[flag].bestscore)
			{
				s_list[flag].bestscore = atoi(s_score.c_str());
				printf("Refresh your record!\n");
			}

		}

		qsort(s_list, cnt, sizeof(s_list[0]), cmp);

		i = 0;
		s_score = "";
		username = "";
		printf("There are %d records on the server side\n",cnt);


		if(!fork())
		{
			if(send(connect_fd, "Grade information has been received by the server!\n", 50,0) == -1)
			perror("Send error\n");
			exit(1);
		}

		n = recv(connect_fd, buffer, MAX_LINE, 0);
		buffer[n] = '\0';

		if(buffer[0] == 'y')
		{
			printf("The client is requesting a leaderboard.\n");
			printf("Send a leaderboard to the client.");
			sleep(1);
			printf("\n");
			if(!fork())
			{
				generateboard(sendbuf,cnt);
				if(send(connect_fd, sendbuf, strlen(sendbuf),0) == -1)
				perror("Send error\n");
				close(connect_fd);
				exit(1);
			}
		}

		else
		{
			printf("Send nothing to the client.\n");
			close(connect_fd);
		}

		printf("******Waiting for a new player's request******\n");
	}

	close(socket_fd);


	exit(0);
}