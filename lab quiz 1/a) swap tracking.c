#include<stdio.h>


int bsort(int *a, int n){

    int tswaps=0,swaps=0;
    for (int i = 0; i < n; i++)
    {
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swaps++;
                tswaps++;
            }
            
        }
        if (!swaps)
        {
            break;
        }
        
        
    }

    return tswaps;
    
}

void print(int *a,int n){

    printf("%d",a[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d",a[i]);
    }
    
}


int main(){

    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    // printf("Got array: ");
    // print(arr,n);
    // printf("\n");
    int x=bsort(arr,n);

    //printf("After sort array: ");
    print(arr,n);
    printf("\n%d\n",x);
}