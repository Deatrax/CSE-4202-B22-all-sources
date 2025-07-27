#include<stdio.h>


void binout(int o,int N){

    for (int i = N-1; i >=0; i--)
    {   
        printf("%d ",1&(o>>i));
    }
    printf("\n");
}

void bitcnt(int o, int N){

    int cnt=0;
    for (int i = N-1; i >=0; i--)
    {   
        if(1&(o>>i))
            cnt++;
    }
    printf("%d\n",cnt);
}


int main(){

    int n,x=0;
    scanf("%d",&n);
    for (int  i = n-1; i >=0; i--)
    {
        int a;
        scanf("%d",&a);
        x|=(a<<i);
    }
    // for (int i = n-1; i >=0; i--)
    // {   
    //     printf("%d",1&(x>>i));
    // } CHECK
    
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        int a,b,c,s1,s2,x1,x2;
        scanf("%d %d %d",&a,&b,&c);
        printf("iteration: %d, type: %d, position: %d %d\n",i,a,b,c); //DEBUG
        switch (a)
        {
        case 1:
            s1=1<<(n-b-1);
            s2=1<<(n-c-1);
            x1=x&s1;
            x2=x&s2;

            x1=x1>>(n-b-1);
            x2=x2>>(n-c-1);

            if (x1==1 && x2==1)
            {
                x=x^(1<<(n-b-1));
                x=x^(1<<(n-c-1));
            }
            binout(x,n);
            break;

        case 2:
            s1=1<<(n-b-1);
            s2=1<<(n-c-1);
            x1=x&s1;
            x2=x&s2;

            x1=x1>>(n-b-1);
            x2=x2>>(n-c-1);
            //printf("got states: %d %d",x1,x2 );

            if (!(x1==1 && x2==1))
            {   
                if (x1)
                {
                    x=x^(1<<(n-b-1));
                }
                
                if (x2)
                {
                    x=x^(1<<(n-c-1));
                }
            }
            binout(x,n);
            break;
        
        case 3:
            s1=1<<(n-b-1);
            s2=1<<(n-c-1);
            x1=x&s1;
            x2=x&s2;

            x1=x1>>(n-b-1);
            x2=x2>>(n-c-1);

            if (x2==0)
            {
                if (!x1)
                {
                    x=x^(1<<(n-b-1));
                }
                
            }

            if (x2==1)
            {
                if (x1)
                {
                    x=x^(1<<(n-c-1));
                }
                
            }
            binout(x,n);
            break;
        }
    }

    binout(x,n);
    bitcnt(x,n);
    
}



// PLEASE IGNORE THIS
// int d=(1<<(n-b-1))^(1<<(n-c-1));
//             for (int i = n-1; i >=0; i--)
//             {   
//                 printf("%d",1&(d>>i));
//             }
//             break;