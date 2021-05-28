#include<stdio.h>

struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];

int main()
{
    int dmat[20][20];
    int n,i,j,k,count=0;
    printf("\nEnter the no. of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix\n");
    for(i=0;i<n;i++)
    {    for(j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            // printf("\n%d\n",rt[i].dist[j]);
            rt[i].from[j]=j;
        }
    }
    printf("\nThe Cost Matrix is:\n");
    for(i=0;i<n;i++)
    {   
        for(j=0;j<n;j++)
            printf("%d\t",rt[i].dist[j]);
        printf("\n");
    }

    do
    {
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0);
    for(i=0;i<n;i++)
    {
        printf("\n\nRoute table for node %d:\n",i+1);
        printf("\nNode  \t Distance \t Next Hop");
        for(j=0;j<n;j++)
        {
            printf("\n%d \t %d \t\t %d ",j+1,rt[i].dist[j],rt[i].from[j]+1);
        }
    }
    printf("\n\n");
}