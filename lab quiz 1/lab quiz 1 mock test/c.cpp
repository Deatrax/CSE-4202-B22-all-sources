#include<stdio.h>
#include<stdlib.h>

int main(){

    double a,b,c;
    int t;
    scanf("%d",&t);
    for (int i = 1; i <=t; i++)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        double res= c/(a+b);
        if (res>1)
        {
            printf("Case %d: %g\n",i,res);
            //printf("\n");
        }
        else{
            printf("Case %d: NO\n",i);
            //printf("\n");
        }
        
    }
    
}