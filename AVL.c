#include "tree.h"

int height ( treeNode * root ){
    int hs , hd;
    if ( root == NULL ) return -1;
    hs = height (root -> left );
    hd = height (root -> right );
    return 1+(( hs>hd) ? hs:hd );
}

treeNode * RightRotation (treeNode *z) {
    
    treeNode *y = z -> left ;
    treeNode *T3 = y -> right ;

    y -> right = z;
    z -> left = T3;

    return y; 
}

treeNode * LeftRotation (treeNode *z) {

    treeNode *y = z -> right ;
    treeNode *T2 = y -> left ;

    y -> left = z;
    z -> right = T2;

    return y; 
}


