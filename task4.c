#include "tasks.h"

void task4(FILE * output, Node ** leaderboard, treeNode ** root) {
    for(Node * n = (*leaderboard); n != NULL; n = n -> next) (*root) = insert((*root), n -> team);

    fprintf(output, "\nTOP 8 TEAMS:\n");
    inorder(output, (*root));
}