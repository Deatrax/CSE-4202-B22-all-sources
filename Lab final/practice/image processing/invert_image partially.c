#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void file_pros(char str1[],char str2[]){

    char copy[200];
    strcpy(copy,str1);
    char *tok=strtok(copy,".");
    strcpy(copy,tok);
    strcat(copy,"_partial_negative.tif");
    strcpy(str2,copy);
    return;
}


int main(){

    char file_name[200];
    printf("Give the file name: ");
    scanf("%s",file_name);

    char dest[200];
    file_pros(file_name,dest);

    int W_lim,H_lim;
    printf("Give the width neg limit (max 1192): ");
    scanf("%d",&W_lim);
    printf("Give the height neg limit (max 500): ");
    scanf("%d",&H_lim);

    
    printf("the output file name is: %s",dest);
    FILE *fsrc=fopen(file_name,"rb");
    FILE *ftarg=fopen(dest,"wb");

    if (fsrc==NULL || ftarg==NULL)
    {
        perror("failed to open file:");
        return -1;
    }
    
    for (int i = 0; i < 8; i++)
    {
        char ch=fgetc(fsrc);
        fputc(ch,ftarg);
    }

    const int H=500;
    const int W=1192;

    char dat[H][W];

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {   
            if (i<H_lim && j<W_lim)
            {
                char ch=fgetc(fsrc);
                dat[i][j]=255-ch;
            }
            else{

                dat[i][j]=fgetc(fsrc);
            }
            
            
        }
        
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j <W ; j++)
        {
            fputc(dat[i][j],ftarg);
        }
        
    }

    // do
    // {
    //     char ch=fgetc(fsrc);
    //     fputc(ch,ftarg);

    // } while (!feof(fsrc));
    char ch;
    do
    {
        ch=fgetc(fsrc);
        fputc(ch, ftarg);
    } while (ch!=EOF);
    
    

    fclose(fsrc);
    fclose(ftarg);

    printf("\nThe image should be flipped by now");
    return 0;
    
    
    
    
}