#include<stdio.h>


//  THIS WAS DONE USING LINEAR SEARCH BUT NOT BINARY SEARCH


int main(){

    int nums[100];
    int in,i=0,diff=__INT_MAX__;
    
    while (1)
    {   
        scanf("%d",&in);
        if (in==-1)
        {
            break;
        }
        //printf("Taking input %d into %d index\n",in,i);
        nums[i]=in;
        
        if (i>1)
        {
            if (diff>(nums[i]-nums[i-1]))
            {
                diff=(nums[i]-nums[i-1]);
            }
            //printf("Difference is %d. it was checked between %d=%d and %d=%d\n",diff,i,nums[i],i-1,nums[i-1]);
        }
        i++;
    }

    for (int a = 1; a < i; a++)
    {
        if (nums[a]!=(nums[a-1]+diff))
        {
            printf("%d",(nums[a-1]+diff));
            return 0;
        }
        
    }


    printf("-1");
    return 0;



    
}