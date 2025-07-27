#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char arr[2000];
    fgets(arr,2000,stdin);
    int par1=0,
        //par1c=0,
        par2=0,
        //par2c=0,
        par3=0,
        //par3c=0
        flag=0,
        dquot=0,
        squot=0;


    for (int i = 0; arr[i]!=NULL; i++)
    {

        //if((arr[i]=='"' || arr[i]=="'") || flag)
            switch (arr[i])
            {
            case '(': if(!flag) par1++; //printf(" found (");
                break;
            
            case ')': if(!flag) par1--; //printf(" found )");
                break;

            case '{': if(!flag) par2++; //printf(" found {");
                break;

            case '}': if(!flag) par2--; //printf(" found }");
                break;

            case '[': if(!flag) par3++; //printf(" found [");
                break;

            case ']': if(!flag) par3--; //printf(" found ]");
                break;

            case '"': 
                //printf(" found \"");
                if (!dquot)
                {
                    dquot++;
                    flag++;
                }
                else if (dquot)
                {
                    dquot--;
                    flag--;
                }
                break;

            case '\'': 

                //printf(" found '");
                if (!squot)
                {
                    squot++;
                    flag++;
                }
                else if (squot)
                {
                    squot--;
                    flag--;
                }
                break;

            case '\\': i++; //printf(" found \\");
                break;
            
            // case ']': par3--;
            //     break;

            // case ']': par3--;
            //     break;
            default:    continue;
                break;
            }
    }

    if ((par1+par2+par3)==0)
    {
        printf("Properly matched opening and opening parentheses!");
    }
    else if (par1>0)
    {
        printf("%d extra opening parenthesis",abs(par1));
    }
    else if (par2>0)
    {
        printf("%d extra opening parenthesis",abs(par1));
    }
    else if (par3>0)
    {
        printf("%d extra opening parenthesis",abs(par1));
    }
    else if (par1<0)
    {
        printf("%d extra closing parenthesis",abs(par1));
    }
    else if (par2<0)
    {
        printf("%d extra closing parenthesis",abs(par1));
    }
    else if (par3<0)
    {
        printf("%d extra closing parenthesis",abs(par1));
    }
    
    
    
}