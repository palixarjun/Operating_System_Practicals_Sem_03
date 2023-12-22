#include<stdio.h>
void main()
{
int ms,r,os, bs, nob, ts,ef=0,n,mp [10], tif=0, rb,us=0, tf,i,j,p=0,x; 
printf("Enter the total memory available(in bytes) ");
scanf("%d",&ts);
printf("\n Enter the memory for operating system ");
scanf("%d",&os);
ms=ts-os;
printf("\n Enter the block size(in bytes) ");
scanf("%d",&bs);
nob=ms/bs; 
rb=ms-nob*bs;
printf("\nTotal memoryl Os memory block size] No.of block created] Total allocated memory Wastage of Memory\n"); 
printf("%12d %10d %11d %20d %23d %18d \n", ts, os, bs, nob, (bs* nob), rb);
printf("\n Enter no of Processor...");
scanf("%d",&n);
for(i=0;i<n;i++)
        {
            printf("\nEnter memory required for processor %d (in bytes)...",i+1);
            scanf("%d",&mp[i]);
     	}
printf("\n\n Process memory Available memory required] Allocated | Internal fragmentation External Fragmentation"); 
for(i=0;i<n&&p<nob; i++)
       {
	printf("\n%8d%17d % 16d", i+1, bs, mp[i]);
	if(mp[i]>bs)
               {
printf("	NO\t\t....|");
ef=ef+bs; 
printf("%23d", bs);
}
else
{
printf("	YES%22d\t\t...", bs-mp[i]);
us=us+mp[i]; 
tif=bs-mp[i];
p++;
            }
              } 
              if(i<n)
                                     printf("\n Memory is full, Remaining process cannot be allocated\n");
                                     }
