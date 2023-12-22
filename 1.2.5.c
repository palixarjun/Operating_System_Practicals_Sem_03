#include<stdio.h>
#include<sys/types.h>
int main(){
pid_t pid;
pid = fork();
if(pid<0)
{
printf("\nChild cannot be produced");
}

else if(pid ==0)
{
printf("\nI am Child Process");
}

else{
wait();
printf("\nI am Parent Process");
}
return (0);
}