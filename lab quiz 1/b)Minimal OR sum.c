#include<stdio.h>
#define ull unsigned long long

void prt(ull *a, int n){

    printf("\nThe array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%llu ",a[i]);
    }
    printf("\n");
    
}

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

        //prt(arr,n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j< n; j++)
            {   
                if (i==j)
                {
                    continue;
                }
                if (arr[i]==arr[j])
                {
                    arr[i]=0;
                }
                
                
                ull x=arr[i]^arr[j];
                //printf("XOR of %llu and %llu is: %llu\n",arr[i],arr[j],x);
                if (x<arr[i] && x<arr[j])
                {
                    if (arr[i]>arr[j])
                    {
                        arr[i]=x;
                    }
                    else{
                        arr[j]=x;
                    }
                    
                }
                
            }
            
        }

        //prt(arr,n);
        
        ull sum=0;
        for (int i = 0; i < n; i++)
        {
            sum+=arr[i];
        }

        printf("%d\n",sum);        
        
    }
    
}