#include"dico.h"


/* Act according to the demand */

void Execute(TArbre *dic)
{
    int choice;
    int ChoiceTwo;
    char* filename;
    char* WordToCheck;
    int Rows ;
    int Cols;
    

    system ("clear");

    puts("\nYou can Type : "
        "\n1 : To insert more words manually"
        "\n2 : To insert more words using a File "
        "\n3 : To Show the words in the dictionnary "
        "\n4 : To Show the words in the dictionnary with the number of occurrence"
        "\n5 : To show the statistics of the dictionnary"
        "\n6 : To check whether a word belongs to the dictionnary or not with its occurrence"
        "\n7 : To delete the Whole dictionnary"
        "\n8 : To show the dictionnary tree\n"
        "\n0 : To Quit\n");

    scanf("%d",&choice);

    while (choice !=0 )
    {
        switch (choice)
        {
            case 1:
                readwords(dic);
                break;

            case 2:
                printf("Please provide your file name : ");
                filename = readline("");
                readfile(filename,dic);
                break;

            case 3:
                // show the dictionnary
                if (*dic == NULL)
                {
                    printf("Your dictionnary is empty .\n");
                }
                else
                    TreeListWords(*dic);
                break;

            case 4:
                // show the dictionnary
                if (*dic == NULL)
                {
                    printf("Your dictionnary is empty .\n");
                }
                else
                    dicoAfficher(*dic);
                break;

            case 5:
                // Show the stats
                stats(*dic);
                break;

            case 6:
                // Check if a word belongs
                WordToCheck = readline("Please provide the word to check : ");

                int occ = dicoNbOcc(WordToCheck, *dic);

                if(occ == 0)
                {
                    printf("%s does not belong to the dictionnary \n", WordToCheck);
                }
                else
                {
                    printf("\"%s\" \t -> \t %d\n", WordToCheck, occ);
                }
                break;

            case 7:
                *dic = arbreSuppr(*dic);
                break;
            
            case 8:
                if (*dic == NULL)
                {
                    printf("Your dictionnary is empty .\n");
                }
                else
                {
                    Rows = treeHeight(*dic);
                    Cols = power(2,Rows);
                    char table[1000][10000] = {0};
                    
                    // generate the table containing the binary tree
                    graphic(*dic, table, 0, 0, Cols);
                    
                    // Print The binary tree in a graphic way
                    int i, j;
                    for (i = 0; i < Rows ; i++) 
                    {
                        for (j = 0; j < Cols ; j++) 
                        {
                            if (table[i][j] > 0) 
                            {
                                printf("%c", table[i][j]);
                            } 
                            else 
                            {
                                printf(" ");
                            }
                        }
                        printf("\n");printf("\n");printf("\n");
                    }
                    
                    WindowDisplay(table,Rows,Cols);
                }


    
                break;

            default:
                // Wrong choice handeling

                printf("Wrong choice, please rechoose : ");
                scanf("%d",&choice);
                ChoiceTwo = 1;
                break;
        }

        if(ChoiceTwo != 1)
        {
            puts("\nYou can Type : "
                "\n1 : To insert more words manually"
                "\n2 : To insert more words using a File "
                "\n3 : To Show the words in the dictionnary "
                "\n4 : To Show the words in the dictionnary with the number of occurrence"
                "\n5 : To show the statistics of the dictionnary"
                "\n6 : To check whether a word belongs to the dictionnary or not with its occurrence"
                "\n7 : To delete the Whole dictionnary"
                "\n8 : To show the dictionnary tree\n"
                "\n0 : To Quit\n");

            scanf("%d",&choice);
        }

    }

}

