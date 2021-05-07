#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    int i,j,divl,msgl;
    int flag=0;
    char msg[100], div[30],temp[30];
    printf("Enter the Message: ");
    scanf("%s",&msg);
    printf("Enter the Polynomial: ");
    scanf("%s",&div);
    divl=strlen(div);
    msgl=strlen(msg);
    for (i=0;i<(divl-1);i++) 
    {
    	msg[msgl+i] = '0';
    }

    for (i=0;i<divl;i++)
    {
    	temp[i]=msg[i];
    }
    // printf("%s\n",temp);
    
    do { 
        // printf("%c\n",temp[0]);
        if (temp[0] == '1') {
            for (j = 1; j < divl; j++) {
                // printf("XOR");
                if (temp[j] == div[j])
                    temp[j] = '0';
                else
                    temp[j] = '1';
            }
        }
        // printf("%s\n",temp);
    
        for (j = 0; j < divl - 1; j++)
        {        
            temp[j] = temp[j + 1];
        }
    
        temp[j] = msg[i++];
        // printf("%s\n",temp);
    } while (i <= msgl + divl - 1);

    for(i=0;i<strlen(temp);i++)
    {
        if(temp[i] == '1')
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        printf("No Error detected");
    }
    else{
        printf("Error detected\n");
    }

}


