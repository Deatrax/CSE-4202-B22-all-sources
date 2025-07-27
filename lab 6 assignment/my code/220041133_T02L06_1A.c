#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int pros_name(char str[],char str2[]){

    char copy[200];
    strcpy(copy,str);
    char *tok=strtok(copy,".");
    strcpy(copy,tok);
    strcat(copy,"_blurred.tif");
    strcpy(str2,copy);
}


int main(int argc,char *argv[]){

    char fl_nam[200];
    if (argc<2)
    {
        printf("Give the image file name (tif file only)=");
        fflush(stdin);
        //fgets(fl_nam,199,stdin);
        scanf("%s",fl_nam);
    }
    else{
        strncpy(fl_nam,argv[1],sizeof(fl_nam));
    }
    

    char dest[200];
    pros_name(fl_nam,dest);

    FILE *src=fopen(fl_nam,"rb");
    FILE *targ=fopen(dest,"wb");
    printf("the output file name is %s",dest);

    if (src==NULL)
    {
        perror("ERROR failed to open source image");
        return -1;
    }
    else if (targ==NULL)
    {
        perror("ERROR failed to target image");
        return -1;
    }
    
    char ch;
    for (int i = 0; i <8; i++)   //GET THE META DATA
    {
        ch=fgetc(src); 
        fputc(ch, targ);
    }

    //SETTING WIDTH AND HEIGHT & BLUR STRENGTH
    const int H=500;
    const int W=1192;
    int blr;
    printf("\nGive blur strenght:");
    scanf("%d",&blr);


    //READING AND STORING PIXEL DATA
    int pix[H][W];
    for(int i=0; i<H; i++){ 
        for(int j=0; j<W; j++){

            pix[i][j]=fgetc(src);
        }
   
    }

    //BOX BLUR
    //AVRAGING THE VALUE OF N BY N PIXLES AROUND TARGETED PIXEL 
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int avg=0;
            for (int x = i-blr; x < i+blr; x++)
            {
                for (int y = j-blr; y < j+blr; y++)
                {
                    avg+=pix[(x+H)%H][(y+W)%W];
                }
                
            }
            int divd=((blr*2)+1)*((blr*2)+1);
            avg/=divd;
            fputc(avg,targ);
        }
        
    }
    
    //COPYING TAILING METADATAS
    do
    {
        ch=fgetc(src);
        fputc(ch, targ);
    } while (ch!=EOF);


    fclose(src);
    fclose(targ);
    printf("OPERATION SUCCEEDED");
    return 0;


}