#include<stdio.H>
#include<conio.H>
#include<string.h>
void main()
{
    int ipfrm[50],opfrm[50], dfrm[50];
    int i,j,k,count,n;
    char frm[20];
    printf("Enter the Frame:");
    scanf("%s",&frm); 
    // printf("\nEntered Frame is %s\n",frm);
    n = strlen(frm);
    for(i=0;i<strlen(frm);i++)
    {
        ipfrm[i] = 0;
        ipfrm[i] = ipfrm[i] * 10 + (frm[i] - 48);
    }
    
    // for(i=0;i<n;i++)
    //     printf("%d",a[i]);
    // scanf("%d",&a[i]);
    for(j=0;j<8;j++)
    {
        if(j==0||j==7)
            opfrm[j] = 0;
        else
            opfrm[j] = 1;
    }
    i=0;
    count=1;
    // j=0;
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
    // printf("j %d",j);
     for(i=0;i<8;j++,i++)
    {
        if(i==0||i==7)
            opfrm[j] = 0;
        else
            opfrm[j] = 1;
    }
    printf("\nAfter stuffing the frame is:");
    for(i=0;i<j ;i++)
        printf("%d",opfrm[i]);
    count=0;
    // printf("\nDecoding the frame\n");
    for(i=8,k=0;i<j-8;i++)
    {
        // printf("\nPosition is %d value is %d",i,opfrm[i]);
        if(opfrm[i] == 1)
        {
            dfrm[k] = opfrm[i];
            k++;
            count++;
        }
        else if(opfrm[i] == 0)
        {
            // printf("\ncount is %d",count);
            if(count == 5)
            {
                // printf("\nSKIPPINg");
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