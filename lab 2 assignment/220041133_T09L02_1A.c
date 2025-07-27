#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lin_src(char nams[101][21],int r,char targ[21]){

    // for (int i = 0; i < r; i++)
    // {
    //     printf("%d name is: %s\n",i+1,nams[i]);
    // } DEBUG


    for (int i = 0; i < r; i++)
    {
        if (!(strcmp(nams[i],targ)))
        {
            return i;
        }   
    }   

    return -1;
}

void alphaSort(char arr[101][21],int r){

    char temp[21];
    for(int i=0;i<r-1;i++)
    {
        for(int j=i+1;j<r;j++)
        {
            if(strcmp(arr[i],arr[j])>0)
            {
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp);
            }
        }
    }
}

static int bin_src(char nams[101][21],int r,char trg[21]){
    
    // printf("before sorting: \n");
    // for (int i = 0; i < r; i++)
    // {
    //     printf("%d name is: %s\n",i+1,nams[i]);
    // } DEBUG
    
    alphaSort(nams,r);
    // printf("after sorting: \n");
    // for (int i = 0; i < r; i++)
    // {
    //     printf("%d name is: %s\n",i+1,nams[i]);
    // } BEBUG

    int lo=0,hi=r-1,itr=0;
    static int ret[2];
    while(lo<=hi)
    {
        int m=(lo+hi)/2;
        if(strcmp(trg,nams[m])==0)
        {   
            // ret[0]=itr;
            // ret[1]=m;
            return m;
        }
        else if(strcmp(trg,nams[m])>0)
        {
            lo=m+1;
        }
        else
            hi=m-1;
        itr++;
    }
    return -1;
}

int main(){

    int n;
    char targ[21];
    scanf("%d %s",&n,targ);
    char names[n][21];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",names[i]);
    }

    int a=lin_src(names,n,targ);
    int b=bin_src(names,n,targ);

    if (a>-1)
    {
        //printf("Linear search found %s at position:%d  at iteration:%d",names[a],a+1,a+1);
        printf("Linear search found");
    }
    else printf("Linear search failed to find");


    if (b>-1)
    {
        //printf("Binary search found %s at position:%d  at iteration:%d",targ,b[1]+1,b[0]+1);
        printf("Binary search found");
    }
    else printf("Linear search failed to find");
    
}