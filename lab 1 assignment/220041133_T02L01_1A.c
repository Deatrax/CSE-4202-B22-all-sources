#include<stdio.h>
#include<string.h>

void xorCrypt(char *str, char k){
    //printf("the stirng is: %s",str);
    for (int i = 0; i < strlen(str); i++)
    {
        //printf("%c",str[i]);
        str[i]=str[i]^k;
    }
    
}   
int main(){

    
    printf("%c[4mEnter your message:%c[0m ",27,27);
    char arr1[5000];
    fgets(arr1,5000,stdin);
    printf("%c[4mEnter the encryption key:%c[0m ",27,27);
    char k;
    fflush(stdin);
    scanf("%c",&k);

    xorCrypt(arr1,k);
    printf("Encrypted message: %s\n Want to decrypt the message? [y/n]=",arr1);
    char in;
    fflush(stdin);
    scanf("%c",&in);
    if (in=='y')
    {
        xorCrypt(arr1,k);
    }
    printf("Decrypted message: %s\n",arr1);
    
    //printf("ios wokring properly");

    
}