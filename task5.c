#include "tasks.h"

// functie ce verifica conditia de echilibru 
int isBalanced(treeNode * root) {
    int hs = height(root -> left);
    int hd = height(root -> right);
    if(abs(hs - hd) <= 1) return 1;
    else return 0;
}

// functie ce realizeaza rotatiile
void balance(treeNode * r) {
    if(!isBalanced(r -> left)) r -> left = RightRotation(r -> left);  
    if(!isBalanced(r -> right)) r -> right = LeftRotation(r -> right); 
}

// functie ce realizeaza rotatii la inserarea echipelor in noul arbore
void makeAVLTree(treeNode * oldroot, treeNode ** newroot) {
    if(oldroot){  
        makeAVLTree (oldroot -> right, newroot);
        (*newroot) = insert((*newroot), oldroot -> team);
        if(!isBalanced(*newroot)) {
            (*newroot) = RightRotation(*newroot);
            balance(*newroot);
        }
        makeAVLTree(oldroot -> left, newroot);   
    }
}

void printLevel2Teams(FILE * output, treeNode * root) {
    fprintf(output, "\nTHE LEVEL 2 TEAMS ARE:\n");
    fprintf(output, "%s\n", root -> right -> right -> team -> team_name);
    fprintf(output, "%s\n", root -> right -> left -> team -> team_name);
    fprintf(output, "%s\n", root -> left -> right -> team -> team_name);
    fprintf(output, "%s\n", root -> left -> left -> team -> team_name);
}

void task5(FILE * output, treeNode ** root) {

    // cream un nou arbore pentru stocarea echipelor din celalalt arbore
    treeNode * newroot = NULL;

    // transferam datele si transformam noul arbore in AVL
    makeAVLTree(*root, &newroot);

    // afisam echipele de pe nivelul 2                    
    printLevel2Teams(output, newroot);

    // eliberam memoria
    free(*root);
    free(newroot);
}