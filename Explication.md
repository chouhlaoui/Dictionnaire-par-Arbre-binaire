# Dictionary Using a Binary Tree
Creation of a binary tree which will represent a dictionary with which we will ensure spelling correction.

## Usage

With this Dictionary you can:

-  Creating an empty dictionary
-  Adding words to the existing dictionary:
    -  Adding with a text file
    -  Manual addition from the command line
-  Displaying the contents of the dictionary :
    -  With the occurrences of each word
    -  Without the occurrences of each word
-  Display of the dictionary content as a graphical tree : 
    -  In another window with SDL 
    -  In the command line
-  Test the existence of a word in the dictionary 

-  Statistics: total number of words, number of different words, longest word, shortest word, average word length ...

-  Deletion of all dictionary entries


Structure of the tree :

A node can contain :
-   \0 : which indicates the end of a word and x = number of occurrences of the word
-   A letter c and x = 0

Passage through the tree :

-   Passage to the LEFT: Read the next letter in the word
-   Passage to the RIGHT: Reading of a new letter of the same level
 
 Exemple :
 
 ![image](https://user-images.githubusercontent.com/61617827/198856046-a8871747-56f4-41fc-89cf-722c822505f1.png)
 
 Interpretation of the tree :


- Going to the LEFT : 
    - Words beginning with A followed by B 
         - Moving to the LEFT :               
                  - ABD is a possible word
         - Going RIGHT: AE is a possible word:      
                  - AE is a possible word  
                  
                  
- Moving to the RIGHT : 
    - C: words beginning with C 
         - Moving to the LEFT :               
                  - CF is a possible word
         - Going RIGHT: G: words beginning with G      
                  - G: Words beginning with G
