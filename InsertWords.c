#include "dico.h"

void makeUpperCase(char *str) 
{
    for (int i = 0; str[i]!='\0'; i++) 
    {
        str[i] = toupper(str[i]);
    }
}

// Read words from the line and add them to the dictionnary
void readwords(TArbre *dic)
{
    char* WordToBeAdded;

    printf("Once you wanna stop the insert process type 0\n");
    WordToBeAdded = readline("");

    while(strcmp(WordToBeAdded,"0")!=0)
    {
        if (strlen(WordToBeAdded) == 0)
        {
            continue;
        }
            
        dicoInsererMot(WordToBeAdded, dic);
        WordToBeAdded = readline("");
    }

}