#include<stdio.h>
#include<string.h>

void replaceSubstring(const char* sentence, const char* toReplace, const char* replaceWith, char* result){

    printf("function started....\n");
    int len=strlen(sentence)+1;
    char cpy[len];
    char out[2000]="\0";
    strcpy(cpy,sentence);
    printf("safety copy string: %s",cpy);
    
    //strcat(out,tok);
    // for (int i = 0; tok==NULL; i++)
    // {
    //     printf("the loop is running at pass:%d",i);
    //     strcat(out,replaceWith);
    //     tok=strtok(NULL,toReplace);
    //     strcat(out,tok);
    // }
    int i=0;
    char *tok=strtok(cpy,toReplace);
    do
    {   
        strcat(out,tok);
        printf("the loop is running at pass:%d\n",i);
        strcat(out,replaceWith);
        tok=strtok(NULL,toReplace);
       
        i++;
    } while (tok!=NULL);
    
    strcpy(result,out);
    printf("function run complete....");
    

    

};



int main(){

    char inp[1024];
    char targ[1024];
    char replacent[1024];
   
    fgets(inp,1024,stdin);
    fgets(targ,1024,stdin);
    fgets(replacent,1024,stdin);
    
    
    char outString[strlen(inp)+(strlen(replacent)*10)];
    //memset(outString, '\0', 1); 
    //DEBUG 
    printf("Input 1: %s\nInput 2: %s\nInput 3: %s",inp,targ,replacent,outString);

    replaceSubstring(inp, targ, replacent, outString);
    
    printf("the result string is: %s",outString);
    

}