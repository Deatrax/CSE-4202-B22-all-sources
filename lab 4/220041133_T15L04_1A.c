#include<stdio.h>

int main(){

    int a,n;
    scanf("%u %u",&a,&n);

    a=a^(1<<n);
    printf("%u",a);
}