#include<stdio.h>
#define ull unsigned long long

int main(){

    int t,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ull arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%llu",&arr[i]);
        }

        int sum=0;
        for (int i = 0; i < n; i++)
        {
            sum |=arr[i];
        }

        printf("%d\n",sum);
        
        
    }
    
}