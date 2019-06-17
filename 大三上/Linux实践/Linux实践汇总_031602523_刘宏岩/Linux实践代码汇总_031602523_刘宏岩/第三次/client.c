#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
 
int main(int agrc, char *argv[])
{
	struct sockaddr_in server_addr;
	int server_len = 0;
	int sockfd = -1;
	int result = 0;
	char c = 'A';
	//取第一个参数的第一个字符
	if(agrc > 1)
		c = argv[1][0];
	//创建数据报套接字
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	//设置服务器IP端口
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(9739);
	server_len = sizeof(server_addr);
	//向服务器发送数据
	sendto(sockfd, &c, sizeof(char), 0, 
		(struct sockaddr*)&server_addr, server_len);
	//接收服务器处理后发送过来的数据，由于不关心数据来源，所以把后两个参数设为0
	recvfrom(sockfd, &c, sizeof(char), 0, 0, 0);
	printf("char from server = %c\n", c);
	//关闭套接字
	close(sockfd);
	exit(0); 
}
