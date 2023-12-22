#include<stdio.h>
struct process
{
int pid;
int btime;
int wtime;
int ttime;
int ptime;
}p[10];
int main()
{
int i,j,k,n,ttur,twat,temp,ptemp,pptemp;
float awat,atur;
printf("Enter no. of process:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Burst time for process P%d (in ms) :",(i+1));
scanf("%d",&p[i].btime);
printf("Priority time for process P%d (in ms) :",(i+1));
scanf("%d",&p[i].ptime);
p[i].pid=i+1;
}
printf("\n");
printf("\n Process \t Burst Time \t Priority");
for(i=0;i<n;i++)
{
printf("\n%3d\t\t%d\t\t%d",p[i].pid,p[i].btime,p[i].ptime);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(p[i].ptime>p[j].ptime)
{
temp=p[i].btime;
p[i].btime=p[j].btime;
p[j].btime=temp;

pptemp=p[i].ptime;
p[i].ptime=p[j].ptime;
p[j].ptime=pptemp;
ptemp=p[i].pid;
p[i].pid=p[j].pid;
p[j].pid=ptemp;
}
}
}
p[0].wtime=0;
for(i=0;i<n;i++)
{
p[i+1].wtime=p[i].wtime+p[i].btime;
p[i].ttime=p[i].wtime+p[i].btime;
}
ttur=twat=0;
for(i=0;i<n;i++)
{
ttur+=p[i].ttime;
twat+=p[i].wtime;
}
awat=(float)twat/n;
atur=(float)ttur/n;
printf("\n PRIORITY BASED Scheduling\n");
for(i=0;i<48;i++)
printf("-");
printf("\n Process B-Time Priority T-Time W-Time\n");
for(i=0;i<48;i++)
printf("-");
for(i=0;i<n;i++)
printf("\n%d\t%4d\t%4d\t%3d\t%2d",p[i].pid,p[i].btime,p[i].ptime,p[i].ttime,p[i]
.wtime);
printf("\n");
for(i=0;i<48;i++)
printf("-");
printf("\n\nGANTT Chart\n");
printf("-");
for(i=0;i<(p[n-1].ttime+2*n);i++)
printf("-");
printf("\n");

printf("|");
for(i=0;i<n;i++)
{
k=p[i].btime/2;
for(j=0;j<k;j++)
printf(" ");
printf("P%d",p[i].pid);
for(j=k+1;j<p[i].btime;j++)
printf(" ");
printf("|");
}
printf("\n");
printf("-");
for(i=0;i<(p[n-1].ttime+2*n);i++)
printf("-");
printf("\n");
printf("0");
for(i=0;i<n;i++)
{
for(j=0;j<p[i].btime;j++)
printf(" ");
printf("%2d",p[i].ttime);
}
printf("\n\nAverage waiting time: %5.2fms",awat);
printf("\nAverage turn around time; %5.2fms\n",atur);
return 0;
}