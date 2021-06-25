#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
char res[100]; 


void main() { 
    int n,i,len[20]; 
    char frm[100],l[100]; 
    char flag[10];
    strcpy(flag,"11011\0");
    // printf(strlen(flag));
    // int flagl = 5;
    int flagl = strlen(flag);
    // printf(flagl);
    // printf(flag);
    strcat(res,flag);
    printf("Enter the number of frames\n"); 
    scanf("%d",&n); 
    for(i=0;i<n;i++) 
    { 
        printf("Enter the frame %d\n",i+1); 
        scanf("%s",&frm); 
        // printf(strlen(frm));
        len[i]=strlen(frm); 
        // printf("%d",len[i]);
        printf("Length of the frame is %d\n", len[i]);
        strcat(res,frm);
        strcat(res,flag);
        // printf(res);
    } 
    printf("The message is %s\n",res); 
    
    int j;
    int f1=0; 
    // printf(res[0]);
    printf("Frame Recieved\n"); 
    for(i=0;i<n;i++) 
    { 
         for(j=0;j<len[i];j++)
         {
             printf("%c",res[f1 + j + flagl]);
         }
         printf("\n");
        f1 = f1 + j + flagl;
         

    } 
    return 0; 
}