#include "dico.h"


void Afficher(TArbre a, char prefixe[], int pos)
{
    if (!arbreEstVide(a))
    {
        prefixe[pos] = arbreRacineLettre(a);

        if (arbreRacineLettre(a) == '\0')
            {
                printf("\"%s\" [%d]\n", prefixe, arbreRacineNbOcc(a));
            }

        Afficher(arbreFilsGauche(a), prefixe, pos+1);
        Afficher(arbreFilsDroit(a), prefixe, pos);
    }
}

/* --------------------------------------------------- */

void InsererMot(char mot[], int debut, TArbre *Tree)
{
    if (arbreEstVide(*Tree)) /* Empty Dictionnary */
    {
        *Tree = arbreCons(mot[debut], 0, arbreConsVide(), arbreConsVide());

        if (debut == strlen(mot))
        {
            ((*Tree)->nbocc)++;
        }

        else
        {
            InsererMot(mot, debut+1, &((*Tree)->filsGauche));
        }
    }

    else if (mot[debut] < arbreRacineLettre(*Tree)) /* the word starts with a letter smaller than the letter in the dictionnary */
    {
        *Tree = arbreCons(mot[debut], 0, arbreConsVide(), *Tree);
        if (debut == strlen(mot))
        {
            ((*Tree)->nbocc)++;
        }

        else
        {
            InsererMot(mot, debut+1, &((*Tree)->filsGauche));
        }
    }

    else if (mot[debut] > arbreRacineLettre(*Tree)) /* the word starts with a letter bigger than the letter in the dictionnary */
    {
        InsererMot(mot, debut, &((*Tree)->filsDroit));
    }

    else /* the word starts with a letter same letter in the dictionnary */
    {
        if (debut == strlen(mot))
        {
            ((*Tree)->nbocc)++;
        }

        else
        {
            InsererMot(mot, debut+1, &((*Tree)->filsGauche));
        }
    }
}

/* --------------------------------------------------- */

int NbOcc(char mot[], int debut, TArbre a)
{
    if (arbreEstVide(a)) /* Empty Dictionnary */
    {
        return 0;
    }

    else if (debut > strlen(mot)) /* The word doesn't belong to the dictionnary */
    {
        return 0;
    }

    else if (mot[debut] < arbreRacineLettre(a)) /* the first letter of the word < the letter in the dictionnary */
    {
        return 0;
    }

    else if (mot[debut] == arbreRacineLettre(a)) /* The word starts with the same letter as dictionnary */
    {
        if (mot[debut] == '\0')
        {
            return arbreRacineNbOcc(a);
        }

        else
        {
            return NbOcc(mot, debut+1, arbreFilsGauche(a));
        }
    }

    else /* The word doesn't start with the same letter as dictionnary so we keep diging */
    {
        return NbOcc(mot, debut, arbreFilsDroit(a));
    }
}

/* ------------------------------------------------------- */

// Calculate all the distinct words

int calcul(TArbre a)
{
    int x=0;
    if (!arbreEstVide(a))
    {
        if (arbreRacineLettre(a)=='\0')
        {
            x=1;
        }

        x = x + calcul(arbreFilsGauche(a));
        x = x + calcul(arbreFilsDroit(a));
    }
    else
    {
        x = 0;
    }

    return x ;
}

// Calculate all the existing words using the occurrence of each word

int calculTous(TArbre a)
{
    int x=0;
    if (!arbreEstVide(a))
    {
        if (arbreRacineLettre(a)=='\0')
        {
            x = arbreRacineNbOcc(a);
        }

        x = x + calculTous(arbreFilsGauche(a));
        x = x + calculTous(arbreFilsDroit(a));
    }
    return x ;
}


void dicoAfficher(TArbre a)
{
    char buffer[100];

    Afficher(a, buffer, 0);
}

void dicoInsererMot(char mot[], TArbre *Tree)
{
    InsererMot(mot, 0, Tree);
}

int dicoNbOcc(char mot[], TArbre a)
{
    return NbOcc(mot, 0, a);
}

int dicoNbMotDifferent(TArbre a)
{
    return calcul(a);
}

int dicoNbMotsTotal(TArbre a)
{
    return calculTous(a);
}


