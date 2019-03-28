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
#include <gtk/gtk.h>

#define MAXLENGTH   101
#define MAX_LINE 1024

using namespace std;
char username[MAX_LINE]={0};
GtkWidget *lb_username;
string all_string = "";
int request_flag = 0;

int get_score(ifstream &f)
{
	int len = 0;
	char a;
	int p = 0;
	string bestscore = "";
	int ans = 0;
	while (f.get(a))//字符读取不成功就终止
	{
		len++;
		all_string += a;//把每个字符传入all_string
	}

	//cout<<temp[len-44]<<endl;
	p = len-44;
	while(all_string[p]!=' ')
	{
		bestscore += all_string[p];
		p--;
	}
	reverse(bestscore.begin(),bestscore.end());
	//cout<<bestscore<<endl;
	ans = atoi(bestscore.c_str());
	return ans;
}


void Submit(GtkWidget *widget, gpointer data)
{
	
	const gchar *name = gtk_entry_get_text((GtkEntry *)lb_username);
	strcpy(username,name);
	gtk_entry_set_text((GtkEntry *)lb_username,"");
	gtk_main_quit();
}


void ui(int argc, char * argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window),100,100);
	g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window),"SNAKE~");
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);


	//-----------------------------------------------------------
	//3.创建一个水平布局容器hbox 
	GtkWidget *hbox = gtk_hbox_new(0,0);
	//将hbox添加到window 
	//gtk_container_add(GTK_CONTAINER(window), hbox);

	GtkWidget *vbox = gtk_vbox_new(0,0);
	//将hbox添加到window 
	//gtk_container_add(GTK_CONTAINER(window), hbox);


	//4.创建一个图片控件 
	GtkWidget *image = gtk_image_new_from_file("./snake.jpg");
	//将image_one添加到hbox 
	gtk_container_add(GTK_CONTAINER(vbox), image);

	//5.通过GdkPixbuf来写该图片大小 
	//5.1创建pixbuf，需要占用资源，使用完需要释放 
	//5.2修改图片大小 
	GdkPixbuf *src = gdk_pixbuf_new_from_file("./snake.jpg", NULL);
	GdkPixbuf *dst = gdk_pixbuf_scale_simple(src,600,400,GDK_INTERP_BILINEAR); 
	//5.3pixbuf使用完需要释放其中资源 
	g_object_unref(src); 
	g_object_unref(dst);



	//-----------------------------------------------------------
	GtkWidget *lb = gtk_label_new("Welcome ,plz input your nickname :");
	gtk_box_pack_start(GTK_BOX(hbox),lb,0,0,5);

	//-----------------------------------------------------------

	lb_username = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(hbox),lb_username,0,0,5);

	//-----------------------------------------------------------

	//创建一个button
	GtkWidget *button = gtk_button_new_with_label("OK!");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Submit),NULL);
	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window);

	//将button放入窗口中
	//gtk_container_add(GTK_CONTAINER(hbox), button);
	gtk_box_pack_start(GTK_BOX(hbox),button,0,0,1);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Submit),NULL);

	gtk_box_pack_start(GTK_BOX(vbox),GTK_WIDGET(hbox),FALSE,FALSE,0);
	gtk_container_add(GTK_CONTAINER(window),vbox);

	//gtk_widget_show(button);
	gtk_widget_show_all(window);
	gtk_main();
}

//*****************************************************************8

void upload(GtkWidget *widget, gpointer data)
{
	
	gtk_main_quit();
}


void report_ui(int argc, char * argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget *window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window1),100,100);
	g_signal_connect(G_OBJECT(window1),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window1),"SCORE REPORT");
	gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window1),10);

	
	//-----------------------------------------------------------
	//3.创建一个水平布局容器hbox 
	GtkWidget *vbox = gtk_vbox_new(0,0);
	//将hbox添加到window 
	
	/*
	//4.创建一个图片控件 
	GtkWidget *image = gtk_image_new_from_file("./snake.jpg");
	//将image_one添加到hbox 
	gtk_container_add(GTK_CONTAINER(hbox), image);

	//5.通过GdkPixbuf来写该图片大小 
	//5.1创建pixbuf，需要占用资源，使用完需要释放 
	//5.2修改图片大小 
	GdkPixbuf *src = gdk_pixbuf_new_from_file("./snake.jpg", NULL);
	GdkPixbuf *dst = gdk_pixbuf_scale_simple(src,500,400,GDK_INTERP_BILINEAR); 
	//5.3pixbuf使用完需要释放其中资源 
	g_object_unref(src); 
	g_object_unref(dst); 
	*/

	//-----------------------------------------------------------
	GtkWidget *lb = gtk_label_new(all_string.c_str());
	gtk_box_pack_start(GTK_BOX(vbox),lb,0,0,0);

	//-----------------------------------------------------------
	/*
	lb_username = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(hbox),lb_username,1,0,5);
	*/
	//-----------------------------------------------------------

	//创建一个button
	GtkWidget *button = gtk_button_new_with_label("Upload to sever !");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(upload),NULL);
	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window1);

	//将button放入窗口中
	//gtk_container_add(GTK_CONTAINER(hbox), button);
	gtk_box_pack_start(GTK_BOX(vbox),button,0,0,5);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(upload),NULL);

	gtk_container_add(GTK_CONTAINER(window1), vbox);

	//gtk_widget_show(button);
	gtk_widget_show_all(window1);
	gtk_main();
}



//*****************************************************************8


void request_lb(GtkWidget *widget, gpointer data)
{
	
	request_flag = 1;
	gtk_main_quit();
}
void quit_snake(GtkWidget *widget, gpointer data)
{
	request_flag = 0;
	gtk_main_quit();
}

void request_ui(int argc, char * argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget *window2=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window2),300,100);
	g_signal_connect(G_OBJECT(window2),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window2),"SNAKE~");
	gtk_window_set_position(GTK_WINDOW(window2),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window2),10);


	//-----------------------------------------------------------
	//3.创建一个水平布局容器hbox 
	GtkWidget *hbox1 = gtk_hbox_new(0,0);
	GtkWidget *hbox2 = gtk_hbox_new(1,0);

	GtkWidget *vbox = gtk_vbox_new(0,0);
	//将hbox添加到window 
	//gtk_container_add(GTK_CONTAINER(window2), hbox);

	//4.创建一个图片控件 
	GtkWidget *image = gtk_image_new_from_file("./error.png");
	//将image_one添加到hbox 
	gtk_container_add(GTK_CONTAINER(hbox1), image);

	//5.通过GdkPixbuf来写该图片大小 
	//5.1创建pixbuf，需要占用资源，使用完需要释放 
	//5.2修改图片大小 
	GdkPixbuf *src = gdk_pixbuf_new_from_file("./error.png", NULL);
	GdkPixbuf *dst = gdk_pixbuf_scale_simple(src,300,200,GDK_INTERP_BILINEAR); 
	//5.3pixbuf使用完需要释放其中资源 
	g_object_unref(src); 
	g_object_unref(dst); 

	//-----------------------------------------------------------
	GtkWidget *lb = gtk_label_new("Successful upload !\n\nDo you want to see the global leaderboard?");
	gtk_box_pack_start(GTK_BOX(hbox1),lb,0,0,5);

	//-----------------------------------------------------------


	//-----------------------------------------------------------

	//创建一个button
	GtkWidget *button1 = gtk_button_new_with_label("YES!");
	g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(request_lb),NULL);
	g_signal_connect_swapped(G_OBJECT(button1),"clicked",G_CALLBACK(gtk_widget_destroy),window2);


	GtkWidget *button2 = gtk_button_new_with_label("NO!");
	g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(quit_snake),NULL);
	g_signal_connect_swapped(G_OBJECT(button2),"clicked",G_CALLBACK(gtk_widget_destroy),window2);


	//将button放入窗口中
	//gtk_container_add(GTK_CONTAINER(hbox), button);
	gtk_box_pack_start(GTK_BOX(hbox2),button1,0,0,5);
	gtk_box_pack_start(GTK_BOX(hbox2),button2,0,0,5);
	g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(request_lb),NULL);
	g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(quit_snake),NULL);


	gtk_box_pack_start(GTK_BOX(vbox),GTK_WIDGET(hbox1),FALSE,FALSE,0);
	gtk_box_pack_start(GTK_BOX(vbox),GTK_WIDGET(hbox2),FALSE,FALSE,0);
	gtk_container_add(GTK_CONTAINER(window2),vbox);  
	//gtk_widget_show(button);
	gtk_widget_show_all(window2);
	gtk_main();
}





void lb_ui(int argc, char * argv[],char * str)
{
	gtk_init(&argc,&argv);
	GtkWidget *window3=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window3),100,100);
	g_signal_connect(G_OBJECT(window3),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window3),"SCORE REPORT");
	gtk_window_set_position(GTK_WINDOW(window3),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window3),10);

	
	//-----------------------------------------------------------
	//3.创建一个水平布局容器hbox 
	GtkWidget *vbox = gtk_vbox_new(0,0);
	//将hbox添加到window 
	gtk_container_add(GTK_CONTAINER(window3), vbox);
	/*
	//4.创建一个图片控件 
	GtkWidget *image = gtk_image_new_from_file("./snake.jpg");
	//将image_one添加到hbox 
	gtk_container_add(GTK_CONTAINER(hbox), image);

	//5.通过GdkPixbuf来写该图片大小 
	//5.1创建pixbuf，需要占用资源，使用完需要释放 
	//5.2修改图片大小 
	GdkPixbuf *src = gdk_pixbuf_new_from_file("./snake.jpg", NULL);
	GdkPixbuf *dst = gdk_pixbuf_scale_simple(src,500,400,GDK_INTERP_BILINEAR); 
	//5.3pixbuf使用完需要释放其中资源 
	g_object_unref(src); 
	g_object_unref(dst); 
	*/

	//-----------------------------------------------------------
	GtkWidget *lb = gtk_label_new(str);
	gtk_box_pack_start(GTK_BOX(vbox),lb,1,0,5);

	//-----------------------------------------------------------
	/*
	lb_username = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(hbox),lb_username,1,0,5);
	*/
	//-----------------------------------------------------------

	//创建一个button
	GtkWidget *button = gtk_button_new_with_label("I Konw !");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(upload),NULL);
	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window3);

	//将button放入窗口中
	//gtk_container_add(GTK_CONTAINER(hbox), button);
	gtk_box_pack_start(GTK_BOX(vbox),button,1,0,5);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(upload),NULL);


	//gtk_widget_show(button);
	gtk_widget_show_all(window3);
	gtk_main();
}





int main(int argc, char ** argv)
{
	ifstream f;
	char s_score[MAX_LINE]; 
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

//	printf("********Welcome to play SNAKE~********\n");
//	printf("********Plz input your name !*********\n");

	ui(argc,argv);


	system("./snake.sh");
	printf("\n");
	printf("\n");

	f.open("./result.txt", ios::in);
	if (!f.is_open())
	{
		printf("Warning! can't open this file!\n");
		exit(1);
	}
	
	
	bestscore = get_score(f);
	//cout<<bestscore<<endl;

	report_ui(argc,argv);


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

	//printf("Hi %s ! Your score is being sent to the server.\n",username);
	//printf("waitting for response.");
	//sleep(1);


	printf("\n");

	if( send(sockfd, sendbuf, strlen(sendbuf), 0) < 0)
	{
		printf("Send score error!\n");
		exit(1);
	}
	//printf("Successfully sent, receiving information from the server.\n");
	if((rec_len = recv(sockfd, recvbuf, MAX_LINE,0)) == -1)
	{
		printf("Recv error\n");
		exit(1);
	}
	recvbuf[rec_len]  = '\0';
	printf("The information recv from sever : %s\n",recvbuf);
	memset(recvbuf, 0, sizeof(recvbuf));
	//printf("Do you want to see the global leaderboard? [y/n]  ");


	request_ui(argc,argv);

	//printf("111111\n");

	//scanf("%s",cflag);
	if(request_flag == 1)
	{
		if( send(sockfd, "y", 1, 0) < 0)
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
		lb_ui(argc,argv,recvbuf);
		//printf("%s\n",recvbuf);
	}
	else
	{
		if( send(sockfd, "n", 1, 0) < 0)
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
