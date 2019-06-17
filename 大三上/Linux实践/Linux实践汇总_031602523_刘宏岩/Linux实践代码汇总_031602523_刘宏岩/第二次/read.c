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
    // 获取共享内存，返回一个id
    int shmid = shmget(key, 0, 0);
    if(-1 == shmid)
    {
        perror("shmget failed");
        exit(1);
    }
    // 映射共享内存，得到虚拟地址
    void *p = shmat(shmid, 0, 0);
    if((void*)-1 == p)
    {
        perror("shmat failed");
        exit(2);
    }
    // 读共享内存
    int x = *(int *)p;
    int y = *((int *)p + 1);
    printf("从共享内存中都取了:0x%x 和 0x%x \n", x, y);
    // 解除映射
    if(-1 == shmdt(p))
    {
        perror("shmdt failed");
        exit(3);
    }
    return 0;
}
