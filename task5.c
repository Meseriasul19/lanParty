#include "tasks.h"

int isBalanced(treeNode * root) {
    int hs = height(root -> left);
    int hd = height(root -> right);
    if(abs(hs - hd) <= 1) return 1;
    else return 0;
}

void balance(treeNode ** r) {
    if(!isBalanced((*r) -> left)) (*r) -> left = RightRotation((*r) -> left);  
    if(!isBalanced((*r) -> right)) (*r) -> right = LeftRotation((*r) -> right); 
}

void makeAVLTree(treeNode * oldroot, treeNode ** newroot) {
    if(oldroot){  
        makeAVLTree (oldroot -> right, newroot);
        (*newroot) = insert((*newroot), oldroot -> team);
        if(!isBalanced(*newroot)) {
            (*newroot) = RightRotation(*newroot);
            balance(newroot);
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
    treeNode * newroot = NULL;
    makeAVLTree(*root, &newroot);                    
    printLevel2Teams(output, newroot);
}