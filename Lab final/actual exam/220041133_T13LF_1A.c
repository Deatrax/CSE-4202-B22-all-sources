#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

int main(){

    FILE *fp1=fopen("table.md","rb");
    char str[1024];

    // for (int i = 0; i < 4; i++)
    // {
    //     fscanf(fp1,"%s",str);
    //     printf("got dat= %s\n",str);
    //     char *tok=strtok(str,"|");
    //     for (int i = 0; tok!=NULL; i++)
    //     {   
    //         char out[100];
    //         strcpy(out,tok);
    //         printf("data is= %s\n",out);
    //         tok=strtok(NULL,"|");
    //     }    
    // }

    for (int i = 0; i < 2; i++)
    {
        fscanf(fp1,"%s",str);
    }

    char store[16][1024];
    for (int i = 0; i < 4; i++)
    {
        
        fscanf(fp1,"%s",str);
        char *tok=strtok(str,"|");
        for (int j = 4*i; tok!=NULL; j++)
        {   
            char out[100];
            strcpy(out,tok);
            sprintf(store[j],"\0");
            strcat(store[j],tok);
            tok=strtok(NULL,"|");
        }    
    }
    
    
    // for (int i = 0; i < 16; i++)
    // {
    //     printf("dat in array: %s\n",store[i]);
    // }
    
    FILE *fp2=fopen("tabel.tex","wb");
    fprintf(fp2,"\\begin{tabular}{| l | l | l | l |}\n\t\\hline	\\textbf{Fruit} & \\textbf{Quantity} & \\textbf{Price} & \\textbf{Date} \\\\\n ");
    for (int i = 0; i < 4; i++)
    {   
        fprintf(fp2,"\t\\hline\n\t");
        for (int j = 0; j < 4; j++)
        {
            fprintf(fp2,"%s",store[(4*i)+j]);
            if (j<3)
            {
                fprintf(fp2," & ");
            }
            
        }
        fprintf(fp2," \\\\\n");
        
    }
    fprintf(fp2,"\t\\hline\n\\end{tabular}");
}