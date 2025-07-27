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
    
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        int a,b,c,s1,s2,x1,x2;
        scanf("%d %d %d",&a,&b,&c);
        switch (a)
        {
        case 1:
            s1=1<<(n-b-1); //GETTING MASK
            s2=1<<(n-c-1);
            x1=x&s1;
            x2=x&s2; //GETTING BIT STATE

            x1=x1>>(n-b-1);
            x2=x2>>(n-c-1); //MOVING THEM TO UNIT PLACE

            if (x1==1 && x2==1)
            {
                x=x^(1<<(n-b-1));
                x=x^(1<<(n-c-1));
            }
            break;

        case 2:
            s1=1<<(n-b-1);
            s2=1<<(n-c-1);
            x1=x&s1;
            x2=x&s2;

            x1=x1>>(n-b-1);
            x2=x2>>(n-c-1);

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
            break;
        
        case 3:
            s1=1<<(n-b-1);
            s2=1<<(n-c-1);
            x1=x&s1;
            x2=x&s2;

            x1=x1>>(n-b-1);
            x2=x2>>(n-c-1);

            if (x2==0 && !x1)
            {
                x=x^(1<<(n-b-1));
            }

            if (x2==1 && x1)
            {
                x=x^(1<<(n-c-1));
            }
            break;
        }
    }

    binout(x,n);
    bitcnt(x,n);
}