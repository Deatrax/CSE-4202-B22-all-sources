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

// void parr(int *p,int n){

//     printf("Current sequence: ");
//     for (int i = 0; i < n; i++)
//     {
//         printf(" %d",p[i]);
//     }
//     printf("\n\n");
// }

int main(){

    int n,k;
    
    scanf("%d %d",&n,&k);
    int pts[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&pts[i]);
    }

    //parr(pts,n);
    bsort(pts,n);
    //parr(pts,n);


    for (int i = 0; i < n; i++)
    {
        pts[i]=pts[i]+k;
    }

    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if (pts[i]<=5)
        {
            cnt++;
        }
        
    }

    printf("%d",cnt/3);
    
    
}