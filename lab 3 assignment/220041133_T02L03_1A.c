#include<stdio.h>

typedef struct student
{
    char name[200];
    int ds;
    int net;
    int ml;
    int ttl;
}studn;

void prt(studn *p,int n){

    printf("Position data sequence: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. Name: %s\tDS: %d Net: %d ML: %d Total: %d\n",i+1,p[i].name,p[i].ds,p[i].net,p[i].ml,p[i].ttl);
    }
    
}


void bsort(studn *p,int n){

    
    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (p[j].ttl<p[j+1].ttl)
            {
                studn temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                swaps++;
            }
            else if (p[j].ttl==p[j+1].ttl && p[j].ml<p[j+1].ml)
            {
                studn temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                swaps++;
            }
            else if (p[j].ttl==p[j+1].ttl && p[j].ml==p[j+1].ml && p[j].ds<p[j+1].ds)
            {
                studn temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
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

    studn stu[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d",stu[i].name,&stu[i].ds,&stu[i].net,&stu[i].ml);
    }
    
    for (int  i = 0; i < n; i++)//TOTAL MARKS
    {
        stu[i].ttl=stu[i].ds+stu[i].ml+stu[i].net;
    }
    
    //prt(stu,n);

    bsort(stu,n);

    prt(stu,n);
}