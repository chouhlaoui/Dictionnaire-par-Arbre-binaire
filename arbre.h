#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <readline/readline.h>
#include<sys/types.h>


struct TNoeud {
  char lettre;
  int  nbocc;
  struct TNoeud* filsGauche;
  struct TNoeud* filsDroit;
};

typedef struct TNoeud* TArbre;


TArbre arbreConsVide(void);
int    arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
char   arbreRacineLettre(TArbre a);
int arbreRacineLevel(TArbre a);
int    arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
TArbre   arbreSuppr(TArbre a);
int treeHeight(TArbre root) ;
