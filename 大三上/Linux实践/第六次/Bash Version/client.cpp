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

using namespace std;

int get_score(ifstream &f)
{
	int len = 0;
	char a;
	int p = 0;
	string temp = "";
	string bestscore = "";
	int ans = 0;
	while (f.get(a))//字符读取不成功就终止
	{
		len++;
		temp += a;//把每个字符传入all_string
	}

	//cout<<temp[len-44]<<endl;
	p = len-44;
	while(temp[p]!=' ')
	{
		bestscore += temp[p];
		p--;
	}
	reverse(bestscore.begin(),bestscore.end());
	//cout<<bestscore<<endl;
	ans = atoi(bestscore.c_str());
	return ans;
}


int main(int argc, char ** argv)
{
	ifstream f;
	char s_score[MAX_LINE]; 
	char username[MAX_LINE];
	int bestscore = 0;
	int sockfd = 0;
	int n = 0;
	int j = 0;
	char cflag[1];
	int rec_len = 0;
	char recvbuf[MAX_LINE];
	char sendbuf[MAX_LINE];
	struct sockaddr_in servaddr;
	int p1 = 0;
	int p2 = 0;

	printf("********Welcome to play SNAKE~********\n");
	printf("********Plz input your name !*********\n");
	scanf("%s",username);

	system("~/Desktop/snake.sh");
	printf("\n");
	printf("\n");

	f.open("/home/liuhy/Desktop/result.txt", ios::in);
	if (!f.is_open())
	{
		printf("Warning! can't open this file!\n");
		exit(1);
	}
	
	
	bestscore = get_score(f);
	//cout<<bestscore<<endl;

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		printf("Scoket error!\n");
		exit(1);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);

	if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		printf("inet_pton error!");
		exit(1);
	}

	if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		printf("Connect error!\n");
		exit(1);
	}

	sprintf(s_score, "%d", bestscore);

	strcpy(sendbuf,s_score);
	strcat(sendbuf,username);
	sendbuf[strlen(sendbuf)] = '\0';
	//printf("%s\n",sendbuf);

	printf("Hi %s ! Your score is being sent to the server.\n",username);
	printf("waitting for response.");
	sleep(1);


	printf("\n");

	if( send(sockfd, sendbuf, strlen(sendbuf), 0) < 0)
	{
		printf("Send score error!\n");
		exit(1);
	}
	printf("Successfully sent, receiving information from the server.\n");
	if((rec_len = recv(sockfd, recvbuf, MAX_LINE,0)) == -1)
	{
		printf("Recv error\n");
		exit(1);
	}
	recvbuf[rec_len]  = '\0';
	printf("The information recv from sever : %s\n",recvbuf);
	memset(recvbuf, 0, sizeof(recvbuf));
	printf("Do you want to see the global leaderboard? [y/n]  ");
	scanf("%s",cflag);
	if(cflag[0] == 'y'|| cflag[0] == 'Y')
	{
		if( send(sockfd, cflag, strlen(cflag), 0) < 0)
		{
			printf("Send request error!\n");
			exit(1);
		}
		if((rec_len = recv(sockfd, recvbuf, MAX_LINE,0)) == -1)
		{
			printf("Recv error\n");
			exit(1);
		}
		recvbuf[rec_len]  = '\0';
		printf("%s\n",recvbuf);
	}
	else
	{
		if( send(sockfd, cflag, strlen(cflag), 0) < 0)
		{
			printf("Send request error!\n");
			exit(1);
		}
		if((rec_len = recv(sockfd, recvbuf, MAX_LINE,0)) == -1)
		{
			printf("Recv error\n");
			exit(1);
		}
		recvbuf[rec_len]  = '\0';
		printf("%s\n",recvbuf);
	}

	printf("**************GAME OVER***************\n");
	close(sockfd);

	f.close();

	exit(0);
}
