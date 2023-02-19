#include "dico.h"


void readfile(char FileName[],TArbre *dic)
{

    FILE *fp = fopen(FileName,"r");

    if (fp == NULL)
    {
        printf("File Not Found\n");
    }

    else
    {
        char Word[90] ;
        
        /* Fill in the tree based on the file */
        while(!feof(fp))
        {
            fgets(Word, 90, fp);
            Word[strlen(Word)-1] = '\0';
            dicoInsererMot(Word, dic);
        }

        fclose(fp);               
    }

}