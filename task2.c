#include "tasks.h"

//diferenta dintre nr de echipe si cea mai apropiata putere a lui 2 (nr de echipe ce vor fi eliminate)
int diff(int nr){
    int power = 1;
    while (nr>=power) power *=2;
    return (nr-(power/2));
}

void eliminate(Node ** node, int nr) {

    //stergem echipele
    for (int i = 0; i < diff(nr); i++) {     
        Node * prevmin = (*node); // adresa nodului din-aintea minimului aflat
        Node * min = (*node); // adresa minimului ce va fi aflat
        Node * prev = (*node); // adresa din-aintea nodului cu care parcurgem lista, pentru a retine prevmin
        for(Node * n = prev -> next; n!= NULL; n = n -> next) {  
            if (n -> team -> team_points < min -> team -> team_points ) {
                min = n;
                prevmin = prev;
            }
            prev = n;
        }

        if(prevmin == min) {
            (*node) = min -> next;
        }
        deleteNode(&min, &prevmin); // eliberam memoria nodului si refacem legaturile
    }
    
}

void task2(FILE * output, Node ** node, int nr_teams) {

    // eliminam echipele
    eliminate(node, nr_teams);

    // afisam echipele ramase
    for(Node * n = (*node); n!= NULL; n = n -> next) 
        fprintf(output, "%s\n", n->team->team_name);
}