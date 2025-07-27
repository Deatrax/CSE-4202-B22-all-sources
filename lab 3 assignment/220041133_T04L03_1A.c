#include<stdio.h>


void bsort(int *pt,int n){
    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (pt[j]>pt[j+1])
            {
                int temp=pt[j];
                pt[j]=pt[j+1];
                pt[j+1]=temp;
                swaps++;
            }
        }
        if (!swaps)
        {
            break;
        }
    }
}


int main(){

    int n;
    scanf("%d",&n);
    int n1[n], n2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&n1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&n2[i]);
    }

    bsort(n1,n);
    bsort(n2,n);

    for (int i = 0; i < n; i++)
    {
        if (n1[i]!=n2[i])
        {
            printf("DIFFERENT");
            return 0;
        }
        
    }
    printf("SAME");
    
    
}