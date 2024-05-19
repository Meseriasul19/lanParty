#pragma once
#include "struct.h"
#include "tasks.h"

typedef struct treeNode {
    Team * team;
    struct treeNode * right;
    struct treeNode * left;
} treeNode;

treeNode * newNode ( Team *);
treeNode * insert ( treeNode *, Team *);
void inorder (FILE *, treeNode *);