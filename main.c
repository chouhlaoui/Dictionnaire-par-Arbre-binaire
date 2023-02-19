#include "dico.h"


int main(int argc, char **argv)
{
    TArbre dico;
    char typeConstruct[100];
    char* filename;

    dico = arbreConsVide();

    printf("Would you like to construct your dictonnary manually ? YES or NO : ");
    scanf("%s",typeConstruct);
    makeUpperCase(typeConstruct);

    while (1)
    {
        
        if(strcmp(typeConstruct,"YES")==0)
        {
            readwords(&dico);
            Execute(&dico);
            return 0;
        }

        else if(strcmp(typeConstruct,"NO")==0)
        {
            printf("Please provide your file name : ");
            filename = readline("");
            readfile(filename,&dico);
            Execute(&dico);
            return 0;
        }

        else if (strcmp(typeConstruct,"QUIT")==0)
        {
            return 0;
        }

        else 
        {
            printf("Would you like to construct your dictonnary manually ? YES or NO : ");
            scanf("%s",typeConstruct);
        }

    }   

}