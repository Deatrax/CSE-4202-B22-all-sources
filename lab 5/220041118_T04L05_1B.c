#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n, count = 1, first = 0;
    char str[100], ch[1];

    // scanf("%s%s",str,ch);
    // scanf("%[^\n]s")
    fgets(str, sizeof(str), stdin);
    scanf("%c", &ch[0]);
    // fgets(ch, sizeof(ch), stdin);

    n = strlen(str);
    n--;

    // printf("%c",ch[0]);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ch[0])
        {
            if (i != n - 1 && str[i + 1] != str[i] && first)
            {
                printf("\n");
                count++;
            }
        }
        else if (str[i] != '\n')
        {
            printf("%c", str[i]);
            first=1;
        }
    }

    printf("\n%d", count);

    return 0;
}