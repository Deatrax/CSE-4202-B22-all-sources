#include<stdio.h>
#include<string.h>

//GLOBAL VARIABLES

int n;

void bsort(int *pt){
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

int calcVAL( int l, int a,char d[]){

    int ttl=0,cur=0;
    
    for (int i = 0; i < l; i++)
    {
        for (int j = i+1; j < l; j++)
        {
            if (d[i]>d[j])
            {
                cur++;
            }
            else{
                break;
            }

            ttl+=cur;
            cur=0;
            
        }
        
    }

    return ttl;
    
}
void sortWord(int l, char d[n][l+1]){

    int vals[n];

    for(int i=0;i<10;i++){

        vals[i]=calcVAL(l,i,d[i]);
    }

    //VALUES BEFORE SORT
    printf("The happiness values are:\n");

    for(int i=0;i<10;i++){

       printf("Word: %s, Value: %d\n",d[i],vals[i]);
    }

    //SORTING

    for(int i=0; i<10; i++){

        for(int j=i; j<10; j++){

            if(vals[i]<vals[j]){
                int temp=vals[i];
                vals[i]=vals[j];
                vals[j]=temp;
                char tem[10];
                strcpy(tem,d[i]);
                strcpy(d[i],d[j]);
                strcpy(d[j],tem);
            }
        }
    }

    printf("\n\nThe happiness values are:\n\n");

    for(int i=0;i<10;i++){

        printf("%s %d\n",d[i],vals[i]);
    }
}


int main(){

    int l;
    scanf("%d %d",&l,&n);
    int vals[n];
    char dna[n][l+1];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",dna[i]);
    }

    sortWord(l,&dna);
    
}