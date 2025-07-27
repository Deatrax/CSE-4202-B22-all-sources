#include<stdio.h>


void bsort(float *pt,int n){
    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (pt[j]<pt[j+1])
            {
                float temp=pt[j];
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

void parr(float *p,int n){

    //printf("Current sequence: ");
    for (int i = 0; i < n; i++)
    {
        printf("%g ",p[i]);
    }
    printf("\n\n");
}

int main(){

    int n;
    scanf("%d",&n);
    float nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&nums[i]);
    }

    //parr(nums,n);
    bsort(nums,n);
    //parr(nums,n);

    for (int i = 0; i < n-1; i++)
    {
        if (nums[i]==nums[i+1])
        {
            printf("No");
            return 0;
        }
        
    }

    printf("Yes\n");
    parr(nums,n);
    
    
}