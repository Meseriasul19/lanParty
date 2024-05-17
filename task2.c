#include "tasks.h"

//diferenta dintre nr de echipe si cea mai apropiata putere a lui 2 = nr de echipe ce vor fi eliminate
int diff(int nr){
    int power = 1;
    while (nr>power) power *=2;
    return (nr-(power/2));
}

void eliminate(Node ** node, int nr) {

    //FILE * f = fopen("r1.out", "wt");
    //stergem echipele
    for(Node * n = (*node); n!= NULL; n = n -> next) {
        //fprintf(f, "%s : %.2f\n", n -> team -> team_name, n -> team -> team_points);
    }
    for (int i = 0; i < diff(nr); i++) {     
        Node * prevmin = (*node);
        Node * min = (*node);
        Node * prev = (*node);   
        for(Node * n = prev -> next; n!= NULL; n = n -> next) {
            
            
            if (n -> team -> team_points < min -> team -> team_points ) {
                min = n;
                prevmin = prev;
            }
            prev = n;
        }
        //printf("Punct min:");
        //printf("%.2f\n", min -> team -> team_points);
        if(prevmin == min) {
            (*node) = min -> next;
        }
        deleteNode(&min, &prevmin); 
    }
    
}

void task2(FILE * output, Node ** node, int nr_teams) {

    eliminate(node, nr_teams);

    for(Node * n = (*node); n!= NULL; n = n -> next) 
        fprintf(output, "%s\n", n->team->team_name);
}