#include "dico.h"

/* Find the length of each word in the dictionnary */

void count(TArbre a, char prefixe[], int WordPosition, int WordsLength[], int* DistinctWordCount, char words[][2000], int Occ[])
{
    if (!arbreEstVide(a))
    {
        prefixe[WordPosition] = arbreRacineLettre(a);

        if (arbreRacineLettre(a) == '\0')
        {
            sprintf(words[*DistinctWordCount],"%s", prefixe);

            WordsLength[(*DistinctWordCount)]=strlen(prefixe);
            
            Occ[(*DistinctWordCount)]=arbreRacineNbOcc(a);

            (*DistinctWordCount)++;
        }

        count(arbreFilsGauche(a), prefixe, WordPosition + 1, WordsLength, DistinctWordCount, words, Occ);
        count(arbreFilsDroit(a), prefixe, WordPosition, WordsLength, DistinctWordCount, words, Occ);
    }
}



/* Find the longest and the shortest words, Find the Total Length of the words */

float Sum(int WordsLength[], int n, int *min, int *max, int occ[])
{
    int s = 0;

    for (int j=0 ; j<n ; j++)
    {
        if(WordsLength[j] > (*max))
        {
            *max = WordsLength[j] ;
        }

        if(WordsLength[j] < (*min))
        {
            *min = WordsLength[j] ;
        }

        if(occ[j] > 1)
        {
            s = s + ( occ[j] * WordsLength[j] ) ;
        }
        else
        {
            s = s + WordsLength[j];
        }
        
    }
    return ((float)s);

}



/* Show the all the statistics */

void stats(TArbre dic)
{
    int nbocc[2000];
    int WordLength[2000];
    int DistinctWords=0;
    int Minimum=80;
    int Maximum=0;
    char buffer[100];
    char Words[100][2000];

    count(dic, buffer, 0, WordLength, &DistinctWords, Words, nbocc);

    float summ = Sum(WordLength, DistinctWords, &Minimum, &Maximum, nbocc);

    printf("Number of distinct words = %d \nTotal number of words = %d \n", dicoNbMotDifferent(dic), dicoNbMotsTotal(dic));
    printf("Average length = %.2f \nMaximum = %d \nMinimum = %d \n", summ/(float)dicoNbMotsTotal(dic), Maximum, Minimum);
    printf("Dictionnary's height : %d \n",treeHeight(dic));
    
    /* Show the longest words */
    
    printf("\n\nLongest Words :\n");

    for(int j=0 ; j < DistinctWords ; j++)
    {
        if(WordLength[j] == Maximum)
        {
            printf("%s repeated %d times \n", Words[j], nbocc[j]);
        }
    }

    /* Show the shortest words */

    printf("\n\nShortest Words :\n");

    for(int j=0 ; j < DistinctWords ; j++)
    {
        if(WordLength[j]==Minimum)
        {
            printf("%s repeated %d times \n", Words[j], nbocc[j]);
        }
    }

}