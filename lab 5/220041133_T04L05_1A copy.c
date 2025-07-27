#include<stdio.h>
#include<string.h>

int main(){

    char inp[2000];
    char delim;
    fgets(inp, 2000,stdin);
    fflush(stdin);
    scanf("%c",&delim);

    printf("given string is: %s\ngiven delimiter is:%c\n",inp,delim);

    printf("stage 1\n");

    int cnt=0;
    for (int i = 0; inp[i]!=NULL; i++)
    {
        if (inp[i]==delim)
        {
            cnt++;
        }
        
    }
    printf("Number of tokens found: %d",cnt);
    printf("stage 2\n");

    char tokens[cnt][1000];
    int j=0;
    for (int i = 0; i < cnt; i++)
    {   
        int idx=0;
        for (; inp[j]!=delim; j++)
        {   
            sprintf(&tokens[i][idx],"%c",inp[j]);
            //tokens[i][idx]=inp[j];
            idx++;
        }
        sprintf(&tokens[i][idx],"%c",'\n');
        
    }

    printf("stage 3\n");
    
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n",tokens[i]);
    }
    
    
    
}