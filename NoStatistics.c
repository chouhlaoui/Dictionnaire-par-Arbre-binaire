#include "dico.h"

//Print the words without stats about each word

void ListWords(TArbre a, char prefixe[], int pos)
{
    if (!arbreEstVide(a))
        {
            prefixe[pos] = arbreRacineLettre(a);

            if (arbreRacineLettre(a) == '\0')
            {
                printf(" %s \n", prefixe);
            }

            ListWords(arbreFilsGauche(a), prefixe, pos+1);
            ListWords(arbreFilsDroit(a), prefixe, pos);
        }
}

void TreeListWords(TArbre a)
{
    char buffer[100];

    ListWords(a, buffer, 0);
}


