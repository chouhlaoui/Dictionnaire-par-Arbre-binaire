/* -------------------------------------------------------*/
/* Primitives de gestion d’un dictionnaire */
/* -------------------------------------------------------*/
#include "arbre.h"
void dicoAfficher(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);
int dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a); int
dicoNbMotsTotal(TArbre a);
/* -------------------------------------------------------*/