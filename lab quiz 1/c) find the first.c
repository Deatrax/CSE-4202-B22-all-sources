#include<stdio.h>
#define ll long long

int lsrc(ll *a,int n,int targ){
    
    for (int i = 0; i < n; i++)
    {
        if (a[i]==targ)
        {
            return i;
        }
        
    }
    return -1;

}

int main(){

    int n,q,t;
    scanf("%d %d",&n,&q);
    ll ar1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&ar1[i]);
    }

    while (q--)
    {
        scanf("%d",&t);
        int x=lsrc(ar1,n,t);
        printf("%d\n",x);
    }
    
    
}