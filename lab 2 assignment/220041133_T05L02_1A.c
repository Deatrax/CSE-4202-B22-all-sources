#include<stdio.h>

int findElem(int a[], int n)
{
    int lo=0,hi=n-1,m;
    while(lo<=hi)
    {
        m=(lo+hi)/2;
        if(a[m]!=m)
        {
            if(m==0 || a[m-1]==m-1)
                return m;
            else{
                hi=m-1;
            }
        }
        else{
            lo=m+1;
        }
    }
    return lo;
}


int main ()
{
    int n,b;

    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    b=findElem(a,n);

    printf("%d",b);
    return 0;
}