#include<stdio.h>
#include<string.h>

int main(){

    char inp[2000];
    char delim;
    fgets(inp, 2000,stdin);
    fflush(stdin);
    scanf("%c",&delim);

    int cnt=0;
    for (int i = 0; inp[i]!=NULL; i++)
    {
        if (inp[i]==delim)
        {
            cnt++;
        }
        
    }
    printf("Number of tokens found: %d\n",cnt+1);
    char out[cnt+1][100];
    int idx1=0,idx2=0;
    int len=strlen(inp);
    for (int i = 0; i < len; i++)
    {
        if (inp[i]==delim && inp[i+1]!=delim)
        {   
            out[idx1][idx2]='\0';
            idx1++;
            idx2=0;
        }

        else if (inp[i]!=delim)
        {
            out[idx1][idx2]=inp[i];
            idx2++;
        }
        
                                        
    }
    out[idx1][idx2]='\0';
    for (int i = 0; i <=cnt; i++)
    {
        printf("out.%d: %s\n",i,out[i]);
    }
    
}