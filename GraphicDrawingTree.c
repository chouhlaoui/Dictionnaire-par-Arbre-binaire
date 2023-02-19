#include"arbre.h"

int power(int x,int n){
    if(n==0){
        return 1;
    }
    else{
        return x*power(x,n-1);
    }
}

// Function to save the binary table in a 2D array 
void graphic(TArbre root, char table[][10000], int level, int left, int right) {
    if (root == NULL) {
        return;
    }
    int mid = (left + right) / 2;

    table[level][mid] = root->lettre ;

    graphic(root->filsGauche , table, level+1, left, mid-1);
    graphic(root->filsDroit , table, level+1, mid+1, right);
}













