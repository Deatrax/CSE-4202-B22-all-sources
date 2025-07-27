#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);

    
    while (c!='~')
    {
        if (isalnum(c) == 0)
            printf("%c is not an alphanumeric character.", c);
        else
            printf("%c is an alphanumeric character.", c);
        
        printf("\nEnter a character: ");
        fflush(stdin);
        scanf("%c", &c);
    
    }
    
    return 0;
}