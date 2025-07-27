#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

int main(){

    int x;
    scanf("%d",&x);
    int left=0;
    int right=0;

    int stat=0;
    int flag=1;
    int cnt=0;
    while(cnt<33){
        if (flag)
        {
            do
            {   
                x=x<<1;
                stat=x&(1<<31);
                printf("stat is %d\n",stat);
                cnt++;
            }while (stat!=1 && cnt<32);
            if (stat)
            {   
                flag=0;
                left++;
            }
            
        }
        else{

            do
            {   
                x=x>>1;
                stat=x&1;
                printf("stat is %d\n",stat);
                cnt++;
            }while (stat!=1 && cnt<32);
            if (stat)
            {   
                flag=1;
                right++;
            }
        }
    
    stat=0;

    }
    printf("left:%d right:%d",left,right);
    
    
}