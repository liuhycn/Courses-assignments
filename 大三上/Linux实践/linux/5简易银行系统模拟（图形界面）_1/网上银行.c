#include<gtk/gtk.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	char uname[]="mel";
	char psword[]="123456";
	double a,b,c,d;
	int get;	
	static GtkWidget* entry1;
	static GtkWidget* entry2;
	static GtkWidget* entry3;
	static GtkWidget* entry4;
	static GtkWidget* entry5;
	static GtkWidget* entry6;
	static GtkWidget* entry7;
	static GtkWidget *ourgif;
	gchar *b0 = "确定";
void on_button_clicked(GtkWidget* button,gpointer data)
{
		g_printf("              您将离开主页面.\n");
g_print("--------------------------------------------------------\n");
}
void on_button0_clicked (GtkWidget* button,gpointer data)
{
	GtkWidget* window1;
	GtkWidget* dialog ;
	GtkMessageType type ;
	//获取2个输入框的信息
	 const gchar *username = gtk_entry_get_text(GTK_ENTRY(entry1));
	 const gchar *password = gtk_entry_get_text(GTK_ENTRY(entry2));
	//输出2个输入框的信息
g_print("--------------------------------------------------------\n");
g_print("                       用户登录                          \n");
g_print("--------------------------------------------------------\n");
	g_print("              用户名是:%s",username);
	g_print("\n");
	g_print("              密码是:%s",password);
	g_print("\n");
	if(strcmp(uname,username)==0 && strcmp(psword,password)==0)
	{
		get=1;
		printf("              login success!\n");
		dialog=gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL |GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"登录成功！");
	
	
		gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	}
	else
	{
		get=0;		
		printf("              lofin fail!\n");
		dialog=gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL |GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"登录失败！");
	

		gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	}
g_print("--------------------------------------------------------\n");	
	
}
void on_button1_clicked(GtkWidget* button,gpointer data)
{	
	double all=0;
	char sum[32];
	const gchar *name=gtk_entry_get_text(GTK_ENTRY(entry6));
	const gchar *money=gtk_entry_get_text(GTK_ENTRY(entry7));
	const gchar *summoney1=gtk_entry_get_text(GTK_ENTRY(entry5));
	gtk_entry_set_text(GTK_ENTRY(entry7) ,money);
     	c=atof(money);  
	gtk_entry_set_text(GTK_ENTRY(entry5) ,summoney1);
     	d=atof(summoney1); 
	all=d-c;

	gcvt(all,32,sum);
	gtk_entry_set_text(GTK_ENTRY(entry5),sum);
g_print("                      转账操作\n");
g_print("--------------------------------------------------------\n");
	g_printf("              转账收款人：%s\n",name);
	g_printf("              转账金额：%0.2lf\n",c);
	g_printf("              账户余额：%0.2lf\n",all);
	if(all<=0)
	g_printf("       您的账户目前余额为负，请尽快存钱！否则您的帐号会被冻结！\n");
g_print("--------------------------------------------------------\n");
}
void on_button3_clicked(GtkWidget* button,gpointer data)
{
	g_printf("              退出使用\n");
}
GtkWidget* create_button1(void)
{
	GtkWidget *box;
	GtkWidget *image;
	GtkWidget *label;	
	GtkWidget *button;	
	//char *title = "确定";
	image = gtk_image_new_from_file("a5.PNG");
	label = gtk_label_new("确定");//(title);
	//不均匀排放，间隔为2个像素
	box = gtk_vbox_new(FALSE,2);
	//设定容器边框的宽度
	gtk_container_set_border_width(GTK_CONTAINER(box),5);	
	gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,3);
	gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,3);
	gtk_widget_show(image);
	gtk_widget_show(label);

	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(button),box);
	gtk_widget_show(box);
	return button;
}
GtkWidget* create_button2(void)
{
	GtkWidget *box;
	GtkWidget *image;
	GtkWidget *label;	
	GtkWidget *button;	
	//char *title = "确定";
	image = gtk_image_new_from_file("a3.PNG");
	label = gtk_label_new("确定");//(title);
	//不均匀排放，间隔为2个像素
	box = gtk_vbox_new(FALSE,2);
	//设定容器边框的宽度
	gtk_container_set_border_width(GTK_CONTAINER(box),5);	
	gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,3);
	gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,3);
	gtk_widget_show(image);
	gtk_widget_show(label);

	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(button),box);
	gtk_widget_show(box);
	return button;
}
void on_button2_clicked(GtkWidget* button,gpointer data)
{
	double sum=0;
	char summoney[32];
	const gchar *outmoney=gtk_entry_get_text(GTK_ENTRY(entry3));
	const gchar *inmoney=gtk_entry_get_text(GTK_ENTRY(entry4));
    	gtk_entry_set_text(GTK_ENTRY(entry3) , outmoney);
     	a=atof(outmoney);  
	gtk_entry_set_text(GTK_ENTRY(entry4) , inmoney);
     	b=atof(inmoney);
	sum=b-a;

	gcvt(sum,32,summoney);
	gtk_entry_set_text(GTK_ENTRY(entry5),summoney);
g_print("                       主页面操作                       \n");
g_print("--------------------------------------------------------\n");
	g_printf("              支出：%0.2lf\n",a);
	g_printf("              收入：%0.2lf\n",b);
	g_printf("              账户余额：%0.2lf\n",sum);
if(sum<=0)
	g_printf("         您的账户目前余额为负，请尽快存钱！否则您的帐号会被冻结！\n");
g_print("--------------------------------------------------------\n");
}
void on_button4_clicked(GtkWidget* button,gpointer data)
{
g_print("--------------------------------------------------------\n");
	g_printf("	  感谢您对此次服务的评价!\n");    
}
void on_button5_clicked(GtkWidget* button,gpointer data)
{
g_print("                     评价页面                           \n");
g_print("--------------------------------------------------------\n");
        g_print("        您对此次使用的评价是： %s",(gchar *)data);
	g_print("\n");
g_print("--------------------------------------------------------\n");
}
GtkWidget* create_button5(void)
{
	GtkWidget *box;
	GtkWidget *image;
	GtkWidget *label;	
	GtkWidget *button;	
	//char *title = "满意";
	image = gtk_image_new_from_file("happy.png");
	label = gtk_label_new("满意");//(title);
	//不均匀排放，间隔为2个像素
	box = gtk_vbox_new(FALSE,2);
	//设定容器边框的宽度
	gtk_container_set_border_width(GTK_CONTAINER(box),1);	
	gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,1);
	gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,1);
	gtk_widget_show(image);
	gtk_widget_show(label);

	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(button),box);
	gtk_widget_show(box);
	return button;
}
GtkWidget* create_button6(void)
{
	GtkWidget *box;
	GtkWidget *image;
	GtkWidget *label;	
	GtkWidget *button;	
	//char *title = "一般";
	image = gtk_image_new_from_file("soso.png");
	label = gtk_label_new("一般");//(title);
	box = gtk_hbox_new(FALSE,2);
	//设定容器边框的宽度
	gtk_container_set_border_width(GTK_CONTAINER(box),1);	
	gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,1);
	gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,1);
	gtk_widget_show(image);
	gtk_widget_show(label);

	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(button),box);
	gtk_widget_show(box);
	return button;
}
GtkWidget* create_button7(void)
{
	GtkWidget *box;
	GtkWidget *image;
	GtkWidget *label;	
	GtkWidget *button;	
	//char *title = "一般";
	image = gtk_image_new_from_file("sad.png");
	label = gtk_label_new("不满意");//(title);
	//不均匀排放，间隔为2个像素
	box = gtk_vbox_new(FALSE,2);
	//设定容器边框的宽度
	gtk_container_set_border_width(GTK_CONTAINER(box),1);	
	gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,1);
	gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,1);
	gtk_widget_show(image);
	gtk_widget_show(label);

	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(button),box);
	gtk_widget_show(box);
	return button;
}
int main(int argc,char* argv[])
{
	//定义多个窗口控件指针变量
	GtkWidget* window0;
	GtkWidget* vbox;
	GtkWidget *image2;
	GtkWidget* vbutton;
	//初始化
	gtk_init(&argc,&argv);

	window0 = gtk_window_new(GTK_WINDOW_POPUP);
	//连接信号"delete_event",使得窗口关闭时发生
	g_signal_connect(G_OBJECT(window0),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	//设置窗口标题	
	gtk_window_set_title(GTK_WINDOW(window0),"Splash窗口");
	//设定窗口的位置,让窗口总在最前端
	gtk_window_set_position(GTK_WINDOW (window0),GTK_WIN_POS_CENTER);	
	//创建盒子
	vbox = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window0),vbox);
	//创建图像
	image2 = gtk_image_new_from_file("a6.PNG");
	gtk_box_pack_start(GTK_BOX(vbox),image2,TRUE,TRUE,0);
	//创建按钮 
	vbutton = gtk_button_new_with_label("请点击进入！");
	gtk_box_pack_start(GTK_BOX(vbox),vbutton,FALSE,FALSE,0);
	g_signal_connect(G_OBJECT(vbutton),"clicked",G_CALLBACK  (gtk_main_quit),NULL);
	gtk_widget_show_all(window0);
	gtk_main();
	gtk_widget_hide(window0);

	GtkWidget* window1;
	GtkWidget* box;
	GtkWidget* box1;
	GtkWidget* box2;
	GtkWidget* label1;
	GtkWidget* label2;
	GtkWidget* sep;
	GtkWidget* button0;
	gtk_init(&argc,&argv);

	window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window1),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window1),"登录窗口");
	gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window1),20);
	box = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window1),box);
	box1 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box),box1,FALSE,FALSE,5);
	box2 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box),box2,FALSE,FALSE,5);
	sep = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(box),sep,FALSE,FALSE,5);
	//创建一个“用户名”标签
	label1 = gtk_label_new("用户名:");
	//创建一个输入框
	entry1 = gtk_entry_new();
	//按从前到后顺序在一个横向盒子中排列这个标签和输入框
	gtk_box_pack_start(GTK_BOX(box1),label1,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(box1),entry1,FALSE,FALSE,5);
	//创建一个“密码”标签
	label2= gtk_label_new("密码:");
	entry2 = gtk_entry_new();
	//单行输入控件的显示属性，FALSE表示显示的内容全部是＊
	gtk_entry_set_visibility(GTK_ENTRY(entry2),FALSE);
	gtk_box_pack_start(GTK_BOX(box1),label2,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(box1),entry2,FALSE,FALSE,5);
	//创建一个“确认”按钮
	button0 = gtk_button_new_with_label("确认");
	g_signal_connect(G_OBJECT(button0),"clicked",G_CALLBACK(on_button0_clicked),NULL);
		g_signal_connect_swapped(G_OBJECT(button0),"clicked",G_CALLBACK(gtk_widget_destroy),window1);
	//将按钮放在盒子中
		gtk_box_pack_start(GTK_BOX(box),button0,FALSE,FALSE,5);
		gtk_widget_show_all(window1);
		gtk_main();
//用户登录成功后跳转
if(get==1)
{
	GtkWidget* window2;
	GtkWidget* box3;
	GtkWidget* box4;
	GtkWidget* box5;
	GtkWidget* box6;
	GtkWidget* label3;
	GtkWidget* label4;
	GtkWidget* label5;
	GtkWidget* label6;
	GtkWidget* label7;
	GtkWidget* button1;
	GtkWidget* button;
	GtkWidget* button2;
	GtkWidget* sep1;
	gtk_init(&argc,&argv);
	window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window2),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window2),"欢迎登录网上银行");
	gtk_window_set_position(GTK_WINDOW(window2),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window2),20);
	box3 = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window2),box3);
	box4 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box3),box4,FALSE,FALSE,5);
	box5 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box3),box5,FALSE,FALSE,5);
box6 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box3),box6,FALSE,FALSE,5);
	sep1 = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(box3),sep1,FALSE,FALSE,5);
	//创建一个“支出”标签
	label3 = gtk_label_new("支出:");
	//创建一个输入框
	entry3 = gtk_entry_new();
	//按从前到后顺序在一个横向盒子中排列这个标签和输入框
	gtk_box_pack_start(GTK_BOX(box4),label3,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(box4),entry3,FALSE,FALSE,5);
	//创建一个“收入”标签
	label4= gtk_label_new("收入:");
	entry4 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(box4),label4,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(box4),entry4,FALSE,FALSE,5);
	//创建一个“账户余额”标签
	label5= gtk_label_new("账户余额:");
	entry5 = gtk_entry_new();	
	gtk_box_pack_start(GTK_BOX(box4),label5,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(box4),entry5,FALSE,FALSE,5);
	button2 = create_button2();
	g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(on_button2_clicked),(gpointer)b0);
	gtk_box_pack_start(GTK_BOX(box4),button2,FALSE,FALSE,1);
	//创建一个“转账收款人”标签
	label6= gtk_label_new("转账收款人:");
	entry6 = gtk_entry_new();	
	gtk_box_pack_start(GTK_BOX(box5),label6,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(box5),entry6,FALSE,FALSE,5);
	//创建一个“转账金额”标签
	label7= gtk_label_new("转账金额:");
	entry7 = gtk_entry_new();	
	gtk_box_pack_start(GTK_BOX(box5),label7,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(box5),entry7,FALSE,FALSE,5);
	button1 = create_button1();
	g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(on_button1_clicked),(gpointer)b0);
	gtk_box_pack_start(GTK_BOX(box5),button1,FALSE,FALSE,1);
	//创建一个“退出”按钮
	button = gtk_button_new_with_label("退出");
	//调用回调函数，显示信息
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_button_clicked),NULL);
	//点击"确认"按钮，调用回调函数，退出程序
	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window2);
	//将按钮放在盒子中
	gtk_box_pack_start(GTK_BOX(box3),button,FALSE,FALSE,5);	
	gtk_widget_show_all(window2);
	gtk_main();

	GtkWidget* window4;
	GtkWidget* box10;
	GtkWidget* box11;
	GtkWidget* box12;
	GtkWidget* box13;
        GtkWidget* box14;  
	GtkWidget* label8;
	GtkWidget* sep3;

	GtkWidget *button4;	
	GtkWidget *button5;
	GtkWidget *button6;
	GtkWidget *button7;

	gchar *b1 = "满意";
	gchar *b2 = "一般";
	gchar *b3 = "不满意";
	
	gtk_init(&argc,&argv);
	window4 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window4),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window4),"评价窗口");
	gtk_window_set_position(GTK_WINDOW(window4),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window4),100);
	box10 = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window4),box10);
	box11 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box10),box11,FALSE,FALSE,5);
	box12 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box10),box12,FALSE,FALSE,5);
	box13 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box10),box13,FALSE,FALSE,5);
	box14 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box10),box14,FALSE,FALSE,5);
	sep3 = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(box10),sep3,FALSE,FALSE,5);
	//创建评价标签
	label8 = gtk_label_new("您对此次使用的评价是:"); 
gtk_box_pack_start(GTK_BOX(box11),label8,FALSE,FALSE,5);
	//创建带图片的评价按钮
	button5 = create_button5();
	g_signal_connect(G_OBJECT(button5),"clicked",G_CALLBACK(on_button5_clicked),(gpointer)b1);
	gtk_box_pack_start(GTK_BOX(box12),button5,FALSE,FALSE,1);	
	button6 = create_button6();
	g_signal_connect(G_OBJECT(button6),"clicked",G_CALLBACK(on_button5_clicked),(gpointer)b2);
	gtk_box_pack_start(GTK_BOX(box12),button6,FALSE,FALSE,1);	
	button7 = create_button7();
	g_signal_connect(G_OBJECT(button7),"clicked",G_CALLBACK(on_button5_clicked),(gpointer)b3);
	gtk_box_pack_start(GTK_BOX(box12),button7,FALSE,FALSE,1);
	//创建一个“确认”按钮
	button4 = gtk_button_new_with_label("发布");
	//调用回调函数，显示信息
	g_signal_connect(G_OBJECT(button4),"clicked",G_CALLBACK(on_button4_clicked),NULL);
	//点击"确认"按钮，调用回调函数，退出程序
	g_signal_connect_swapped(G_OBJECT(button4),"clicked",G_CALLBACK(gtk_widget_destroy),window4);
	//将按钮放在盒子中
	gtk_box_pack_start(GTK_BOX(box10),button4,FALSE,FALSE,5);
	//显示所用控件
	gtk_widget_show_all(window4);
	gtk_main();

	GtkWidget* window3;
	GtkWidget* box7;
	GtkWidget* box8;
	GtkWidget* box9;
	GtkWidget* button3;
	GtkWidget *image1;
	GtkWidget* sep2;
	gtk_init(&argc,&argv);
	window3 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window3),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window3),"结束页面");
	gtk_window_set_position(GTK_WINDOW (window3),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window3),10);
	box7 = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window3),box7);
	box8 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box7),box8,FALSE,FALSE,5);
	box9 = gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(box7),box9,FALSE,FALSE,5);
	sep2 = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(box7),sep2,FALSE,FALSE,5);
	//创建动态图像
	image1 = gtk_image_new_from_file("s1.gif");
	gtk_box_pack_start(GTK_BOX(box8),image1,FALSE,FALSE,5);
	//创建关闭按钮
	button3 = gtk_button_new_with_label("关闭");	
	g_signal_connect(G_OBJECT(button3),"clicked",G_CALLBACK  (gtk_main_quit),NULL);
	g_signal_connect_swapped(G_OBJECT(button3),"clicked",G_CALLBACK(gtk_widget_destroy),window3);
	gtk_box_pack_start(GTK_BOX(box9),button3,FALSE,FALSE,5);

	gtk_widget_show_all(window3);
	gtk_main();
}
return FALSE;

}
 
