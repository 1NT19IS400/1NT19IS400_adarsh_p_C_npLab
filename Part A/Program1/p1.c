#include<stdio.h>
void sender(int num_of_frames,int frame[num_of_frames]){
	int i;
	int n;
	int total_bits=0;
	for(i=0;i<num_of_frames;i++)
	{
		int count=0;
		n=frame[i];
		while(n!=0)
		{
				
			n=n/10;
			count++;
		}
		printf("\nNumber of bits in %d frame is %d",i+1,count);
		total_bits+=count;
		count=0;	
	}
	printf("\nThe total number of bits is %d",total_bits);
	receiver(num_of_frames,frame);
}
void receiver(int nof,int fr[nof])
{
	int j;
	for(j=0;j<nof;j++)
	{
		printf("\nFrame %d is %d",j+1,fr[j]);
	}
}
void main(){
	int no_of_fr;
	int frame[no_of_fr];
	int i;
	printf("Enter the number of frames ");
	scanf("%d",&no_of_fr);
	printf("Enter the pattern for each frame");
	for(i=0;i<no_of_fr;i++)
	{
		scanf("%d",&frame[i]);
	}
	sender(no_of_fr,frame);
}