#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
struct Page
{
	int pNo;
	int bNo;
	int P;
	int A;
};
struct PQNode
{
	PQNode * pre;
	PQNode * next;
	Page * pHead;
};
struct PCB
{
	PQNode * p;
	int pCount;
};

int size_mem = 0;
int size_pro = 0;
int size_page = 0;
int block_cnt= 0;
bool * bmp = NULL;
PQNode * p = NULL;

PQNode * queueinit(int n)
{
	PQNode * phead = NULL;
	PQNode * pthis = NULL;
	PQNode * ptail = NULL;
	
}

void SysInit()
{
	int i;
	printf("System initalization!\n");
	printf("Plz input the count of each block :\n");
	scanf("%d",&block_cnt);
	printf("Plz input the size of each page :\n");\
	scanf("%d",&size_page);
	size_mem = block_cnt * size_page;
	printf("The size of memery is : %d\n",size_mem);
	bmp = new bool[block_cnt];
	for(i=0;i<block_cnt;i++)
	{
		b[i] = false;
	}
}
/* -------------------------------------------------- */ 
PCB * NewProc()
{
	int cnt = 0;
	printf("Plz input the size of program :\n");
	scanf("%d",&size_pro);
	cnt = (int)ceil(size_pro/size_page);
	PCB * pcb = new(PCB);
	pcb -> pHead = queueinit(cnt);
	pcb -> pCount = cnt;
	return p;
}















