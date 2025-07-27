#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int jan[4][7];
    int feb[4][7];
    int mar[4][7];
    int apr[4][7];
    int may[4][7];
    int jun[4][7];
    int jul[4][7];
    int aug[4][7];
    int sep[4][7];
    int oct[4][7];
    int nov[4][7];
    int dec[4][7];

    FILE *fp=fopen("BikeSales.csv","r");
    char str[100];
       
    for (int i = 0; i < 8; i++)
    {
        fscanf(fp,"%s,",str);
        ////printf("got str:%s",str);
    }
    //fp=NULL;

    
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            jan[i][j]=atoi(str);
                //printf("jan[%d][%d]: %d\n",i+1,j+1,jan[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            feb[i][j]=atoi(str);
                //printf("feb[%d][%d]: %d\n",i+1,j+1,feb[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            mar[i][j]=atoi(str);
                //printf("mar[%d][%d]: %d\n",i+1,j+1,mar[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            apr[i][j]=atoi(str);
                //printf("apr[%d][%d]: %d\n",i+1,j+1,apr[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            may[i][j]=atoi(str);
                //printf("may[%d][%d]: %d\n",i+1,j+1,may[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            jun[i][j]=atoi(str);
                //printf("jun[%d][%d]: %d\n",i+1,j+1,jun[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            jul[i][j]=atoi(str);
                //printf("jul[%d][%d]: %d\n",i+1,j+1,jul[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            aug[i][j]=atoi(str);
                //printf("aug[%d][%d]: %d\n",i+1,j+1,aug[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            sep[i][j]=atoi(str);
                //printf("sep[%d][%d]: %d\n",i+1,j+1,sep[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            oct[i][j]=atoi(str);
                //printf("oct[%d][%d]: %d\n",i+1,j+1,oct[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            nov[i][j]=atoi(str);
                //printf("nov[%d][%d]: %d\n",i+1,j+1,nov[i][j]);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {   
        fscanf(fp,"%s,",str);
        for (int j = 0; j < 7; j++)
        {
            fscanf(fp,"%s,",str);
            dec[i][j]=atoi(str);
                //printf("dec[%d][%d]: %d\n",i+1,j+1,dec[i][j]);
        }
        
    }
    fp=NULL;
    fclose(fp);

    int lrg=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            // //QUIZ TIME OUT SO COULDN'T FINISH THE QUESTIONS
            // NULL;
            if (apr[i][j]>lrg)
            {
                lrg=apr[i][j];
            }
            
        }
        
    }
    printf("max sell in the month of April: %d\n",lrg);

    int min=INT64_MAX;
    for (size_t i = 0; i < 4; i++)
    {
        if (jan[i][6]<min)
        {
            min=jan[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (feb[i][6]<min)
        {
            min=feb[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (mar[i][6]<min)
        {
            min=mar[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (apr[i][6]<min)
        {
            min=apr[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (may[i][6]<min)
        {
            min=may[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (jun[i][6]<min)
        {
            min=jun[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (jul[i][6]<min)
        {
            min=jul[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (aug[i][6]<min)
        {
            min=aug[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (sep[i][6]<min)
        {
            min=sep[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (oct[i][6]<min)
        {
            min=oct[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (nov[i][6]<min)
        {
            min=nov[i][6];
        }
        
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (dec[i][6]<min)
        {
            min=dec[i][6];
        }
        
    }

    printf("Least sell in Rangpur: %d",min);
    
        //GOT BORED,,,,TWO MORE QUESTIONS LEFT TO ANSWER
        //THIS IS BETTER DONE WITH A 3D ARRAY
    


    
}

// fscanf(fp,"%s,",str);
//         for (int i = 0; i < 7; i++)
//         {
//             fscanf(fp,"%s,",str);
//             //printf("got str:%s",str);
//         }
//         fp=NULL;