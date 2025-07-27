#include<stdio.h>
#include<math.h>


void calc(int *a,int *s,int n){

    int i=0;
    for ( ; i < n; i++)
    {
        s[i]=a[i];
    }

    

    
}
int main(){

    int n;
    scanf("%d",&n);
    int arr[n];
    int siz= pow(2,n)-1;
    int sums[siz];
    //printf("size is %d",siz);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    calc(arr,sums,n);


    
}