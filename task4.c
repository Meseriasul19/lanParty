#include "tasks.h"

void task4(FILE * output, Node ** leaderboard, treeNode ** root) {

    // inseram echipele in arbore
    for(Node * n = (*leaderboard); n != NULL; n = n -> next) 
        (*root) = insert((*root), n -> team);

    // eliberam memorie
    free(*leaderboard);

    // afisam clasamentul celor 8 echipe
    fprintf(output, "\nTOP 8 TEAMS:\n");
    inorder(output, (*root)); // parcurge arborele afisand descrescator echipele dupa punctaj

}