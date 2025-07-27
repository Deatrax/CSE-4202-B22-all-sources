#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    // FILE *fp=fopen("func.c","w");
    // fprintf(fp,"int *func(){\n");
    
    // for (int i = 0; i < n; i++)
    // {   
    //     int a;
    //     scanf("%d",&a);
    //     fprintf(fp,"\nstatic int x%d=");
    // }

    int num=0;
    for (int i = 0; i < n; i++)
    {   
        int x;
        scanf("%d",&x);
        num=(num*10+x);
    }
    printf("yout input was: %d\n",num);

    int pNos,probs=0;
    scanf("%d",&pNos);
    for (int i = 0; i < pNos; i++)
    {   
        int x,y,z,a,b,t1=num,t2=num;
        scanf("%d %d %d",&x,&y,&z);
        
        for (int i = 0; i < y; i++)
        {
            a=t1%10;
            t1=t1/10;
        }

        for (int i = 0; i < y; i++)
        {
            b=t2%10;
            t2=t2/10;
        }

        switch (x)
        {
        case 1: 
            if (!a^b)
            {
                
            }
        
            break;
        
        default:
            break;
        }
        
    }

    
}