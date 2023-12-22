#include<stdio.h>

int main()
{
int page[50],i,n,f,ps,off,pno;
int ch=1;
printf("Aryan Thakur And Arjun Pali \n\n");
printf("\nEnter the no of page in memory :");
scanf("%d",&n);
printf("\nEnter page size :");
scanf("%d",&ps);
printf("\nEnter no of frames :");
scanf("%d",&f); for(i=0;i<n;i++)
page[i]=-1;
printf("\nEnter the page table \n:");
printf("\n(enter the frame no. as -1 if the page is not present in the frame) :\n\n");
printf("\nPageNo\t\tFrameNo\n------\t----------");
for(i=0;i<n;i++)
{
printf("\n%d\t\t",i);
scanf("%d",&page[i]);
}
while(ch==1)
{
printf("\n\nEnter the logic address(i.e. page no & offset):");
scanf("%d%d",&pno,&off);
if (pno >= n){
printf("Page is not available !");
printf("\n Do you want to continue press 1...\n");
scanf("%d",&ch);
}
else{

if(page[pno]==-1)
printf("\n\nThe required page is not available in any of frame !");
else
printf("\n\nPhysical Address(i.e, Frame No & offset): %d,%d\n",page[pno],off);
printf("\n Do you want to continue press 1...\n");
scanf("%d",&ch);}
}
return 1;
}
