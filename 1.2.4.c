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
printf("\nChild PRocess");
printf("\nProcess ID = %d\n", getpid());
printf("\nParent Process id = %d\n", getppid());
}

else{
printf("\nParent Process");
printf("\nProcess ID = %d\n", getpid());
printf("\nParent Process id =%d\n", getppid());
}
return (0);
}