#include<stdio.h>
void main(){
int buffer[5 ], bufsize, in, out,produce, consume, choice=1;
in = 0; out=0; bufsize=10; 
printf("Aryan Thakur and Arjun Pali \n\n\n");
while (choice<3 && choice > 0){
	printf("\n1. Produce\t2. Consume\t3.Exit");
	printf("\nEnter your choice :");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			if (in >= 5){
			printf("\nBuffer is full !");}
			else{
			printf("\n Enter the value :");
			scanf("%d", &produce);
			buffer[in] = produce;
			in = (in + 1);
			}
			break;
		case 2:
			if(in==out)
			printf("\nBuffer is empty !");
			else {
			consume = buffer[out];
			printf("\nThe consumed value is %d", consume);
			out = (out + 1);}
			break;
		case 3:
			break;
			}}}
