#include "arbre.h"


/* Initialise an empty Tree */
TArbre arbreConsVide(void)
{
    return NULL;
}

/* Check if it's an empty Tree */
int arbreEstVide(TArbre a)
{
    return (a==NULL);
}

/* Initialise a Constant Tree */
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd)
{
    TArbre temp;

    temp = (TArbre)malloc(sizeof(struct TNoeud));
    temp->lettre     = c;
    temp->nbocc      = n;
    temp->filsGauche = fg;
    temp->filsDroit  = fd;

    return temp;
}

/* Get the letter */
char arbreRacineLettre(TArbre a)
{
    return a->lettre;
}


/* Find the occurence of a word */
int arbreRacineNbOcc(TArbre a)
{
    return a->nbocc;
}

/* Pass to the left part */
TArbre arbreFilsGauche(TArbre a)
{
    return a->filsGauche;
}

/* Pass to the right part */
TArbre arbreFilsDroit(TArbre a)
{
    return a->filsDroit;
}

/* Delete the whole tree */
TArbre arbreSuppr(TArbre a)
{
    if (!arbreEstVide(a))
    {
        arbreSuppr(a->filsGauche);
        arbreSuppr(a->filsDroit);
        free(a);
    }

    a = NULL;
    
    return a;
}

// Function to calculate the tree height 
int treeHeight(TArbre root) {

    if (root == NULL) 
    {
        return 0;
    } 

    else 
    {
        int leftHeight = treeHeight(root->filsGauche);
        int rightHeight = treeHeight(root->filsDroit);

        if (leftHeight > rightHeight) 
        {
            return leftHeight + 1;
        } 
        else 
        {
            return rightHeight + 1;
        }
    }
}