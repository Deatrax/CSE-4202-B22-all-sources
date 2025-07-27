#include<stdio.h>
#include<string.h>
#include<ctype.h>

void sort(char vals[]){

    for (int i = 0; vals[i]!=NULL; i++)
    {
        vals[i]=tolower(vals[i]);
    }
    
    for(int i=0; vals[i]!=NULL; i++){

        for(int j=i; vals[j]!=NULL; j++){

            if(vals[i]>vals[j]){
                char temp=vals[i];
                vals[i]=vals[j];
                vals[j]=temp;
            }
        }
    }

    for (int i = 0; vals[i]!=NULL; i++)
    {
        if (vals[i]==' ' || vals[i]=='\n')
        {
            continue;
        }
        else{

            
            for (int j = 0; vals[i]!=NULL; j++)
            {   
                vals[j]=vals[i];
                vals[j+1]=NULL;
                i++;
            }

            break;
            
        }
        
    }

    
}

int areAnagrams(const char* phrase1, const char* phrase2){

    char str1[2000];
    char str2[2000];
    strcpy(str1,phrase1);
    strcpy(str2,phrase2);
    sort(str1);
    sort(str2);

    //CHECK
    // printf("now input 1: %s",str1);
    // printf("now input 1: %s",str2);

    if(!strcmp(str1,str2)){
        return 1;
    }
    else{
        return 0;
    }

};


int main(){

    char inp1[1024];
    char inp2[1024];

    fgets(inp1,1024,stdin);
    fgets(inp2,1024,stdin);

    //CHECK
    // printf("initial input 1: %s");
    // sort(inp1);
    // printf("now input 1: %s");


    if(areAnagrams(inp1, inp2)){
        printf("Are Anagrams");
    
    }
    else{
        printf("Are NOT Anagrams");
    }
}