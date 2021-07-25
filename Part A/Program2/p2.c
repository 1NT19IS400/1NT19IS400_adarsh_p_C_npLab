#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int ipfrm[50],opfrm[50], dfrm[50];
    int i,j,k,count,n;
    char frm[20];
    printf("Enter the Frame:");
    scanf("%s",&frm); 
    n = strlen(frm);
    for(i=0;i<strlen(frm);i++)
    {
        ipfrm[i] = 0;
        ipfrm[i] = ipfrm[i] * 10 + (frm[i] - 48);
    }
    for(j=0;j<8;j++)
    {
        if(j==0||j==7)
            opfrm[j] = 0;
        else
            opfrm[j] = 1;
    }
    i=0;
    count=1;

    while(i<n)
    {
        if(ipfrm[i]==1)
        {
            opfrm[j]=ipfrm[i];
            for(k=i+1;ipfrm[k]==1&&k<n&&count<5;k++)
            {
                j++;
                opfrm[j]=ipfrm[k];
                count++;
                if(count==5)
                {
                    j++;
                    opfrm[j]=0;
                    count = 0;
                }
                i=k;
            }
        }
        else
        {
            opfrm[j]=ipfrm[i];
        }
        i++;
        j++;
    }
     for(i=0;i<8;j++,i++)
    {
        if(i==0||i==7)
            opfrm[j] = 0;
        else
            opfrm[j] = 1;
    }
    printf("\nFrame after stuffing:");
    for(i=0;i<j ;i++)
        printf("%d",opfrm[i]);
    count=0;
    for(i=8,k=0;i<j-8;i++)
    {
          if(opfrm[i] == 1)
        {
            dfrm[k] = opfrm[i];
            k++;
            count++;
        }
        else if(opfrm[i] == 0)
        {
            
            if(count == 5)
            {
                
                dfrm[k] = opfrm[++i];
                k++;
                count = 0;
            }
            else
            {
                dfrm[k] = opfrm[i];
                k++;
                count = 0;
            }
        }
    }
    printf("\nFrame after Unstuffing:\n");
    for(i=0;i<k;i++)
        printf("%d",dfrm[i]);
}