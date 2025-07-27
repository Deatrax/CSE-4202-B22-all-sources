

#include <stdio.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LEN 256

static int alphaBsort(char str[MAX_FILES][MAX_NAME_LEN]) {
    int i, j, n = 0;
    char s[MAX_NAME_LEN];

    // Find the number of valid entries in the array
    for (i = 0; i < MAX_FILES && str[i][0] != '\0'; i++) {
        n++;
    }

    int swaps;
    // Bubble sort
    for (i = 0; i < n - 1; i++) {
        swaps = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                // Swap the strings
                strcpy(s, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], s);
                swaps++;
            }
        }
        // If no swaps were made, the array is already sorted
        if (swaps == 0) {
            break;
        }
    }

    // Print the sorted order of names
    printf("The sorted order of names are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0; // Return 0 to indicate success
}

// int main() {
//     char names[MAX_FILES][MAX_NAME_LEN] = {
//         "John", "Alice", "Bob", "Eve", "Charlie", ""
//     };

//     alphaBsort(names);

//     return 0;
// }

int main(){
   int i,j,n;
   char str[MAX_FILES][MAX_NAME_LEN],s[100];
   printf("Enter number of names :");
   scanf("%d",&n);
   printf("Enter names in any order:");
   for(i=0;i<n;i++){
      scanf("%s",str[i]);
   }
   alphaBsort(str);
   printf("The sorted order of names are:");
   for(i=0;i<n;i++){
      printf("%s\n",str[i]);
   }
}
