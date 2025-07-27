#include<stdio.h>

int main(){

    char d='\0';
    unsigned int a=0;
    unsigned short e=0;
    unsigned long b=0;
    unsigned long long c=0;
    
    d=~d;
    a=~a;
    e=~e;
    b=~b;
    c=~c;

    int cnt=0;
    while (d)
    {
        
        d=d<<1;
        cnt++;
    }
    printf("Char: %d bits\n",cnt);

    cnt=0;
    while (a)
    {
        
        a=a<<1;
        cnt++;
    }
    printf("Unsigned int: %d bits\n",cnt);

    cnt=0;
    while (e)
    {
        
        e=e<<1;
        cnt++;
    }
    printf("Unsigned short: %d bits\n",cnt);

    cnt=0;
    while (b)
    {
        
        b=b<<1;
        cnt++;
    }
    printf("unsigned long: %d bits\n",cnt);

    cnt=0;
    while (c)
    {
        
        c=c<<1;
        cnt++;
    }
    printf("unsigned long long: %d bits\n",cnt);

    
    
    
}