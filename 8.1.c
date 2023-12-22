#include<sys/ipc.h> 
#include<sys/shm.h> 
 #include<stdio.h>
int main()
{
// ftok to generate unique key 
key_t key = ftok("shmfile",65);
// shmget returns an identifier in shmid 
int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
printf("\n Shared Memory Id=%d\n",shmid);
// shmat to attach to shared memory
char *str = (char*) shmat (shmid, (void *)0,0);
printf("\nWrite Data :"); 
scanf("%[^\n] %*c",str);
printf("Data written in memory: %s\n", str); 

//detach from shared memory
shmdt (str);
printf("\n Memory Segment %d Detached\n",shmid);
return 0;
}
