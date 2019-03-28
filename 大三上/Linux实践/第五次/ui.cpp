#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <unordered_map>
#include <math.h>
#define random() (rand()%100000)

using namespace std;

string combine(string str1, string str2, char k)
{
	string combination;
	combination = str1 + k + str2;
	return combination;
}
string int_string(int number)
{
	int temp = abs(number);
	std::stringstream ss;
	std::string str;
	ss<<temp;
	ss>>str;
	return str;
}
int randomNunber()
{
	int a = random() % 10 + 1;
	return a;
}
char randomOperation()
{
	int j;
	char symbol[1];
	j = random() % 3;
	switch (j) {
	case 0:
		symbol[0] = '+';
		break;
	case 1:
		symbol[0] = '-';
		break;
	case 2:
		symbol[0] = '*';
		break;
	}
	return symbol[0];
}

string generateExpression()
{
	int num1, num2, change, count;
	char symbol;
	string str_num1, str_num2, Equation, t;
	num1 = randomNunber();
	num2 = randomNunber();
	count = random() % 6 + 2;
	symbol = randomOperation();
	str_num1 = int_string(num1);
	str_num2 = int_string(num2);
	Equation = combine(str_num1, str_num2, symbol);          //随机数与随机的符号结合 
	for (count; count>2; count--) {
		symbol = randomOperation();
		str_num1 = Equation;
		change = random() % 2;
		if (change == 0) {
			str_num1 = '(' + str_num1 + ')';
		}
		num2 = random() % 10 + 1;
		str_num2 = int_string(num2);
		change = random() % 2;
		if (change == 0) {
			t = str_num1;
			str_num1 = str_num2;
			str_num2 = t;
		}
		Equation = combine(str_num1, str_num2, symbol);
	}
	//		cout << Equation << "=" << endl;
	//string Equation2 = Equation + '=';
	//formula = Equation2;
	return Equation;
}
char priority(char pre, char post)
{
    if (pre == '+')
    {
        if (post == '+') return '>';
        else if (post == '-') return '>';
        else if (post == '*') return '<';
        else if (post == '/') return '<';
        else if (post == '(') return '<';
        else if (post == ')') return '>';
    }
    else if (pre == '-')
    {
        if (post == '-') return '>';
        else if (post == '+') return '>';
        else if (post == '*') return '<';
        else if (post == '/') return '<';
        else if (post == '(') return '<';
        else if (post == ')') return '>';
    }
    else if (pre == '*')
    {
        if (post == '*') return '>';
        else if (post == '/') return '>';
        else if (post == '+') return '>';
        else if (post == '-') return '>';
        else if (post == '(') return '<';
        else if (post == ')') return '>';
    }
    else if (pre == '/')
    {
        if (post == '/') return '>';
        else if (post == '*') return '>';
        else if (post == '+') return '>';
        else if (post == '-') return '>';
        else if (post == '(') return '<';
        else if (post == ')') return '>';
    }
    else if (pre == '(')
    {
        if (post == '*') return '<';
        else if (post == '/') return '<';
        else if (post == '+') return '<';
        else if (post == '-') return '<';
        else if (post == '(') return '<';
        else if (post == ')') return '=';
    }
}

int caculate(int Operand1, int Operand2, char Operator) ;
int calculateResult(string str) {                        //用于计算计算生成算式的值
    vector< int > Operands;                              //运算数栈
    vector< char > Operators;                              //运算符栈
    int OperandTemp = 0;
    char LastOperator = 0;                                 //记录上一次所遇到的符号
    for (int i = 0; i < str.size(); i++) {                 //此循环用于去括号
        char ch = str[i];
        if ('0' <= ch && ch <= '9') {
            OperandTemp = OperandTemp * 10 + ch - '0';
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
            if (ch != '(' && LastOperator != ')') {         //结合本次和上次所遇见的符号来判断是否需要将当前存储的运算数压入栈
                Operands.push_back(OperandTemp);
                OperandTemp = 0;
            }
            char Opt2 = ch;
            for (; Operators.size() > 0;) {
                char Opt1 = Operators.back();
                char CompareRet = priority(Opt1,Opt2);   //用当前符号与栈顶符号来对算式简化
                if (CompareRet == '>') {                    //当前的符号的优先级小于栈顶符号时就可以将栈顶符号计算掉并将结果压入栈
                    int Operand2 = Operands.back();
                    Operands.pop_back();
                    int Operand1 = Operands.back();
                    Operands.pop_back();
                    Operators.pop_back();
                    int Ret = caculate(Operand1, Operand2, Opt1);
                    Operands.push_back(Ret);
                }
                else if (CompareRet == '<') {                //当前的符号优先级大于栈顶符号不能进行运算所以跳出循环来存储当前符号
                    break;
                }
                else if (CompareRet == '=') {                //这个是“（”，“） ”结合的情况 所以移除“（”并退出循环
                    Operators.pop_back();
                    break;
                }
            }
            if (Opt2 != ')') {
                Operators.push_back(Opt2);
            }
            LastOperator = Opt2;
        }
    }
    if (LastOperator != ')') {                               //接下来就是计算一个不含括号的算式了
        Operands.push_back(OperandTemp);
    }
    for (; Operators.size() > 0;) {
        int Operand2 = Operands.back();
        Operands.pop_back();
        int Operand1 = Operands.back();
        Operands.pop_back();
        char Opt = Operators.back();
        Operators.pop_back();
        int Ret = caculate(Operand1, Operand2, Opt);
        Operands.push_back(Ret);
    }
    return Operands.back();                                                 //返回结果
}
int caculate(int Operand1, int Operand2, char Operator) {        //计算函数
    int result = 0;
    if (Operator == '+') {
        result = Operand1 + Operand2;
    }
    if (Operator == '-') {
        result = Operand1 - Operand2;
    }
    if (Operator == '*') {
        result = Operand1*Operand2;
    }
    if (Operator == '/') {
        result = Operand1 / Operand2;
    }
    return result;

}

GtkWidget *lb_problem;
GtkWidget *lb_correct;
GtkWidget *lb_wrong;
GtkWidget *lb_ans;

int correctNum = 0;
int wrongNum = 0;
string lastProb = "";

void refreshProblem()
{
	
}

void onBtnSubmit(GtkWidget *widget, gpointer data)
{
	if(lastProb == "")
	{
		lastProb = generateExpression();
		cout << lastProb << endl;
		gtk_label_set_text((GtkLabel*)lb_problem,lastProb.c_str());
		
		//ans = calculateResult(s);
		gtk_entry_set_text((GtkEntry *)lb_ans,"");
	}
	else
	{
		const gchar *myans = gtk_entry_get_text((GtkEntry *)lb_ans);
		if(atoi(myans) == calculateResult(lastProb))
		{
			gtk_label_set_text((GtkLabel*)lb_correct,int_string(++correctNum).c_str());
			cout << "Yes" << endl;
		}
		else
		{
			gtk_label_set_text((GtkLabel*)lb_wrong,int_string(++wrongNum).c_str());
			cout << "No" << endl;			
		}
		gtk_entry_set_text((GtkEntry *)lb_ans,"");
		lastProb = generateExpression();
		cout << lastProb << endl;
		gtk_label_set_text((GtkLabel*)lb_problem,lastProb.c_str());
		const char *myAns = gtk_entry_get_text((GtkEntry *)lb_ans);
	}
	
}

void onBtnClear(GtkWidget *widget, gpointer data)
{
	lastProb = "";
	gtk_entry_set_text((GtkEntry *)lb_ans,"");
	gtk_label_set_text((GtkLabel*)lb_problem,"按提交按钮获得最新题目！");
	correctNum = 0;
	wrongNum = 0;
	gtk_label_set_text((GtkLabel*)lb_correct,"0");
	gtk_label_set_text((GtkLabel*)lb_wrong,"0");
}

void UI(int argc, char *argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	gtk_window_set_default_size(GTK_WINDOW(window),200,50);
	g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window),"口算心算天天练");	
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	
	//-----------------------------------------------------
	GtkWidget *hb = gtk_hbox_new(0,0);
	gtk_container_add(GTK_CONTAINER(window),hb);
	
	//-----------------------------------------------------
	GtkWidget *vbox = gtk_vbox_new(0,0);
	gtk_container_add(GTK_CONTAINER(hb),vbox);
	//-----------------------------------------------------
	GtkWidget *hbox1 = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(vbox),hbox1,FALSE,FALSE,5);
	
	GtkWidget *lb4 = gtk_label_new("题目:");
	gtk_box_pack_start(GTK_BOX(hbox1),lb4,1,0,5);
	
	lb_problem = gtk_label_new("按提交按钮获得最新题目！");
	gtk_box_pack_start(GTK_BOX(hbox1),lb_problem,1,0,5);
	
	GtkWidget *hbox11 = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(vbox),hbox11,FALSE,FALSE,5);
	
	GtkWidget *lb2 = gtk_label_new("正确数:");
	gtk_box_pack_start(GTK_BOX(hbox11),lb2,1,0,5);
	
	lb_correct = gtk_label_new("0");
	gtk_box_pack_start(GTK_BOX(hbox11),lb_correct,1,0,5);
	//-----------------------------------------------------
	GtkWidget *vb3 = gtk_vbox_new(0,0);
	gtk_container_add(GTK_CONTAINER(hb),vb3);
	
	GtkWidget *hb4 = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(vb3),hb4,FALSE,FALSE,5);
	
	GtkWidget *lb = gtk_label_new("\t您的答案:");
	gtk_box_pack_start(GTK_BOX(hb4),lb,1,0,5);
	
	lb_ans = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(hb4),lb_ans,1,0,5);
	
	GtkWidget *hbox2 = gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(vb3),hbox2,FALSE,FALSE,5);
	
	GtkWidget *lb3 = gtk_label_new("错误数:");
	gtk_box_pack_start(GTK_BOX(hbox2),lb3,1,0,5);
	
	lb_wrong = gtk_label_new("0");
	gtk_box_pack_start(GTK_BOX(hbox2),lb_wrong,1,0,5);
	
	//-----------------------------------------------------
	GtkWidget *vb = gtk_vbox_new(0,0);
	gtk_container_add(GTK_CONTAINER(hb),vb);
	
	GtkWidget *btn_submit = gtk_button_new_with_label("提交");
	gtk_box_pack_start(GTK_BOX(vb),btn_submit,1,0,5);
	g_signal_connect(G_OBJECT(btn_submit),"clicked",G_CALLBACK(onBtnSubmit),NULL);

	GtkWidget *btn_clear = gtk_button_new_with_label("清屏");
	gtk_box_pack_start(GTK_BOX(vb),btn_clear,1,0,5);
	g_signal_connect(G_OBJECT(btn_clear),"clicked",G_CALLBACK(onBtnClear),NULL);
	
	
	//-----------------------------------------------------
	gtk_widget_show_all(window);//显示所有窗体
	gtk_main();
}

int main(int argc, char *argv[])
{
	srand(time(0));
	
	UI(argc,argv);
	
	double ans = 0;
	string s = "";
	s = generateExpression();
	cout << "所产生的算式为" << s << endl;
	ans = calculateResult(s);
	cout << "结果为" << ans << endl;
	return 0;
}

