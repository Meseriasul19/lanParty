#pragma once
#include "struct.h"

//BST
typedef struct treeNode {
    Team * team;
    struct treeNode * right;
    struct treeNode * left;
} treeNode;

treeNode * newNode ( Team *);
treeNode * insert ( treeNode *, Team *);
void inorder (FILE *, treeNode *);


//AVL
treeNode * RightRotation (treeNode *);
treeNode * LeftRotation (treeNode *);
int height ( treeNode *);