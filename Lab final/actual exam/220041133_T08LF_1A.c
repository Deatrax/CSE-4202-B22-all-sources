#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>


#define INI_SIZE 1024

bool isPasswordStrong(const char* password);


int main(){

    char pass[INI_SIZE];
    //printf("give the password: ");
    scanf("%s",pass);
    
    if(isPasswordStrong(pass)){
        printf("Stronk\n");
    }
    else{
        printf("Bonk\n");
    }
    return 0;
}



bool isPasswordStrong(const char* password){

    int len=strlen(password);
    char cpy[len];
    strcpy(cpy,password);

    int upr=0,
        lwr=0,
        digi=0,
        symb=0;

    
    for (int i = 0; i < len; i++)
    {
        char ch = cpy[i];
        
         
        
        
        //Not going to use strstr() because "password" can have a cap anywhere like "passWOrd"
        char cha[14]={'a','A','s','S','s','S','w','W','o','O','r','R','d','D'};
        if (ch=='P' || ch=='p')
        {   
            int cnt=i+1;
            char cha2=cpy[i+1];
            for (int j = 0; j <14; j=j+2)
            {   
                
                //printf("verifying %c with %c and %c\n",cha2,cha[j],cha[j+1]);
                if (cha2==cha[j] || cha2==cha[j+1])
                {   
                    cnt++;
                    cha2=cpy[cnt];
                    
                    if (cha[j]=='d')
                    {
                        return false;
                    }
                    continue;
                }
                else{
                    break;
                }
                
                
            }
            
        }
        
        
        // Check for valid characters.
        if (isalnum(ch)) {

            //Lowercase characters.
            if (islower(ch)) {
                lwr++;
                continue;
            }
            // Uppercase characters.
            if (isupper(ch)) {
                upr++;
                continue;
            }

            // Numbers.
            if (isdigit(ch)) {
                digi++;
                continue;
            }
        }

        //Check for symbols
        switch (ch)
        {
        case '!':

            symb++;
            break;

        case '?':

            symb++;
            break;

        case '_':

            symb++;
            break;

        case '$':

            symb++;
            break;
        
        default:
            break;
        }
    }
    
    if (symb && digi && upr && lwr)
    {
        return true;
    }
    else{
        return false;
    }
    

}