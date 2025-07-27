#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){

    const int ini_size=10;
    char *arr=(char*)malloc(10*sizeof(char));
    char a;
    int i=0, 
        size=0, 
        flag=0,
        cnt=0,
        idx=0;

    while (1)
    {
        scanf("%c",&a);
        
        if((i-1)<ini_size)
        arr[i]=a;
        else{
            //printf("reallocing...\n");
            size++;
            arr=(char*)realloc(arr,(size+ini_size)*sizeof(char));
            arr[i]=a;
        }

        if (a=='.')
        {   
            arr[i+1]='\0';
            break;
        }
        i++;
    }
    // for (int j = 0; j <=i; j++)
    // {
    //     printf("%c",arr[j]);
    // }

    char *out=(char*)malloc(ini_size*sizeof(char));
    size=0;
    for (int j = 1; j <=i; j++)
    {   
        if(arr[j]=='I') continue;

        if (isalnum(arr[j]) && !flag)
        {
            if (isupper(arr[j]))
            {   
                cnt++;
                flag=1;
            }
            else continue;
            
        }

        if (idx-1<ini_size)
        {
            NULL;
        }
        else{

            size++;
            out=(char*)realloc(out,(size+ini_size)*sizeof(char));
        }
        
        if (arr[j]=='.')
        {
            out[idx]='\0';
            idx++;
            break;
        }
        else if ((arr[j]==' ' || ispunct(arr[j]) || !isalnum(arr[j])) && flag)
        {   
            out[idx]='\n';
            flag=0;
            idx++;
        } 
        else if (flag)
        {   
            //printf("wrinting %c to out\n",arr[j]);
            out[idx]=arr[j];
            idx++;
        }
        
        
        
    }
    
    printf("%d\n%s",cnt,out);

    
    
    
    
    
}