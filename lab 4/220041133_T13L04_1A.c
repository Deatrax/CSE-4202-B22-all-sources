#include<stdio.h>
#include<string.h>

int main(){

    char str[101];
    int bad=0, good=0, ovr=0; 
    scanf("%s",str);

    for (int i = 0; i < strlen(str); i++)
    {
        switch (str[i])
        {
        case 'N':
            bad++;
            break;
        
        case 'W':
            bad++;
            break;
        
        case 'D':
            bad++;
            break;

        default:
            good++;
            break;
        }

        if (good==6)
        {
            ovr++;
            good=0;
        }
        
    }

   
    if (ovr>1 && good>1)
    {
        printf("%d OVERS %d BALLS",ovr,good);
    }

    else if (ovr==1 && good>1)
    {
        printf("%d OVER %d BALLS",ovr,good);
    }

    else if(ovr>1 && good==1)
    {
        printf("%d OVERS %d BALL",ovr,good);
    }

    else if(ovr==1 && good==1)
    {
       printf("%d OVER %d BALL",ovr,good);
    }

    else if(ovr==0 && good==1)
    {
       printf("%d BALL",good);
    }

    else if(ovr==1 && good==0)
    {
       printf("%d OVER",ovr);
    }
    
    else if(ovr>1 && good==0)
    {
       printf("%d OVERS",ovr);
    }

    else if(ovr==0 && good>1)
    {
       printf("%d BALLS",good);
    }
}