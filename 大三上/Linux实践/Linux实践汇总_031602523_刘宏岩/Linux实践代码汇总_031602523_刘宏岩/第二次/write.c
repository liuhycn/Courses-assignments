#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main() 
{
	// 生成一个key
	key_t key = ftok("./", 66);
	// 创建共享内存，返回一个id
	int shmid = shmget(key, 8, IPC_CREAT|0666|IPC_EXCL);
	if(-1 == shmid)
	{
        perror("shmget failed");
		exit(1); 
	}
	// 映射共享内存，得到虚拟地址
	void *p = shmat(shmid, 0, 0); if((void*)-1 == p)
	{
        perror("shmat failed");
		exit(2);
 	}
	// 写共享内存
	int *pp = p;
	*pp = 0x12345678;
	*(pp + 1) = 0xffffffff;
	// 解除映射
	if(-1 == shmdt(p)) 
	{
        perror("shmdt failed");
		exit(3); 
	}
	printf("解除映射成功，点击回车销毁共享内存\n"); getchar();
	// 销毁共享内存
	if(-1 == shmctl(shmid, IPC_RMID, NULL)) 
	{
        perror("shmctl failed");
		exit(4); 
	}
	return 0; 
}