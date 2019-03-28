#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
/* -------------------------------------------------- */
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
	Page * page;
};
struct PCB
{
	Page * p;
	int pCount;
};
/* -------------------------------------------------- */
int size_mem = 0;
int size_pro = 0;
int size_page = 0;
int block_cnt = 0;
int logAddr = 0;
int phyAddr = 0;
bool * bmp = NULL;
PQNode * phead = NULL;
PQNode * pthis = NULL;							//当前队头 
PQNode * ptail = NULL;							//当前队尾 
PCB * pcb = NULL;
/* -------------------------------------------------- */
int calcu(int x, int y)
{
	if (x%y == 0)
	{
		return x / y;
	}
	else
	{
		return x / y + 1;
	}
}
/* -------------------------------------------------- */
void queueinit()
{
	int i = 0;
	phead = new PQNode;
	phead->next = NULL;
	phead->page = NULL;
	phead->pre = NULL;
	ptail = phead;
}
/* -------------------------------------------------- */
void SysInit()
{
	int i;
	printf("System initalization!\n");
	printf("Plz input the count of blocks :\n");
	scanf("%d", &block_cnt);
	printf("Plz input the size of each page :\n"); \
		scanf("%d", &size_page);
	size_mem = block_cnt * size_page;
	printf("The size of memery is : %d\n", size_mem);
	bmp = new bool[block_cnt];
	for (i = 0; i<block_cnt; i++)				//位视图  0空闲 
	{
		bmp[i] = false;
	}
	queueinit();
}
/* -------------------------------------------------- */
void NewProc()
{
	int cnt = 0;
	int i = 0;
	Page * temp = NULL;
	printf("Plz input the size of program :\n");
	scanf("%d", &size_pro);
	cnt = calcu(size_pro, size_page);
	pcb = new(PCB);
	temp = new Page[cnt];
	for (i = 0; i<cnt; i++)
	{
		temp[i].pNo = i;
		temp[i].bNo = -1;
		temp[i].P = 0;
		temp[i].A = 0;
	}
	pcb->p = temp;
	pcb->pCount = cnt;
}
/* -------------------------------------------------- */
int Relocate()
{
	int ans = 0;
	int n_page = 0;
	int w = 0;
	int flag = 0;
	int i = 0;
	PQNode * ptemp = NULL;
	n_page = calcu(logAddr, size_page);
	if ((pcb->p)[n_page - 1].P == 0)			//缺页中断 
	{
		pthis = new PQNode;
		pthis->page = &(pcb->p)[n_page - 1];
		for (flag = 0; flag < block_cnt; flag++)
		{
			if (bmp[flag] == false)
			{
				break;
			}
		}
		if (flag == block_cnt)					//没有空闲块 
		{
			(pthis->page)->bNo = (ptail->page)->bNo;	//取被踢页所在块号给新块装入
			(ptail->page)->P = 0;							//被踢块中断为置0
			printf("Kick out %d\n", (ptail->page)->pNo);
			ptail = ptail->pre;
			delete(ptail->next);
			ptemp = phead->next;							//新块放到队首
			phead->next = pthis;
			pthis->pre = phead;
			pthis->next = ptemp;
			ptemp->pre = pthis;
		}
		else									//找到空闲块 
		{
			if (phead->next == NULL)
			{
				(pcb->p)[n_page - 1].bNo = flag;	//记录块号
				bmp[flag] = true;
				ptail->next = pthis;
				pthis->pre = ptail;
				ptail = ptail->next;
			}
			else
			{
				(pcb->p)[n_page - 1].bNo = flag;	//记录块号
				bmp[flag] = true;
				ptemp = phead->next;
				phead->next = pthis;
				pthis->pre = phead;
				pthis->next = ptemp;
				ptemp->pre = pthis;
			}
		}
		(pcb->p)[n_page - 1].P = 1;
	}
	else										//没有发生缺页中断
	{
		PQNode * p1;
		PQNode * p2;
		pthis = phead->next;
		if ((pthis->page)->pNo != n_page - 1)
		{
			while (1)
			{
				if ((pthis->page)->pNo == n_page - 1)
				{
					break;
				}
				pthis = pthis->next;
			}
			if (pthis->next != NULL)
			{
				printf("1\n");
				p1 = pthis->pre;
				p2 = pthis->next;
				p1->next = p2;
				p2->pre = p1;
				ptemp = phead->next;							//MMU工作
				phead->next = pthis;
				pthis->pre = phead;
				pthis->next = ptemp;
				ptemp->pre = pthis;
			}
			else
			{
				ptemp = phead->next;
				phead->next = pthis;
				pthis->pre = phead;
				pthis->next = ptemp;
				ptemp->pre = pthis;
			}
		}
	}
	(pcb->p)[n_page - 1].A = 1;
	w = logAddr % size_page;
	if (w == 0)
	{
		w = size_page;
	}
	ans = (pcb->p)[n_page - 1].bNo * size_page;
	ans = ans + w;
	return ans;
}
/* -------------------------------------------------- */
int main()
{
	int cnt = 0;
	int cnt1 = 0;
	int i = 0;
	PQNode * p = phead;
	SysInit();
	NewProc();
	while (1)
	{
		printf("Plz intput the logical address you want visit: \n");
		scanf("%d", &logAddr);
		if (logAddr < 0 || logAddr > size_pro)
		{
			printf("Error!\n");
		}
		else
		{
			phyAddr = Relocate();
			printf("%d\n", phyAddr);
		}
		cnt++;
		p = phead->next;
	}
	return 0;
}
