#include "arbre.h"

void TreeListWords(TArbre a);
void dicoAfficher(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);

void stats(TArbre dic);
int  dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsTotal(TArbre a);
int dicoNbMotDifferent(TArbre a);

void readwords(TArbre *dic);
void readfile(char ch[],TArbre *dic);
void Execute(TArbre *dic);

void makeUpperCase(char *str);
int power(int x,int n);

void graphic(TArbre root, char table[][10000], int level, int left, int right);
void WindowDisplay(char tableau[][10000], int NBL, int NBC);

int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);