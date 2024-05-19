#include "tasks.h"

Node * winner(Node ** match) {
    if(match[0] -> team -> team_points > match[1] -> team -> team_points) {
        match[0] -> team -> team_points ++;
        return match[0];
    } 
    else {
        match[1] -> team -> team_points ++;
        return match[1];
    }
}

Node * loser(Node ** match) {
    if(match[0] -> team -> team_points <= match[1] -> team -> team_points) return match[0];
    else return match[1];
}

void printmatch(FILE * output, Node ** match) {
    fprintf(output ,"%s",match[0] -> team -> team_name);
    for(int i = 0; i < (33 - strlen(match[0] -> team -> team_name)); i++) fprintf(output, " ");
    fprintf(output, "-");
    for(int i = 0; i < (33 - strlen(match[1] -> team -> team_name)); i++) fprintf(output, " ");
    fprintf(output ,"%s\n", match[1] -> team -> team_name);
}

void printwinner(FILE * output, Node * w) {
    fprintf(output ,"%s",w -> team -> team_name);
    for(int i = 0; i < (34 - strlen(w -> team -> team_name)); i++) fprintf(output, " ");
    fprintf(output, "-");
    for(int i = 0; i < 2; i++) fprintf(output, " ");
    fprintf(output, "%.2f\n", w -> team -> team_points);
}

Team * play(FILE * output, Node ** node, Q * queue, int nr_round) {
 
    Node ** match;
    Node * winnersTop = NULL;
    Node * losersTop = NULL;
    Node * w;
    Node * l;

    for(Node * n = (*node); n != NULL; n = n -> next -> next) {
        insertmatch(n, n-> next, queue);
    }

    fprintf(output, "\n--- ROUND NO:%d\n", nr_round);
    while(!isEmptyQ(queue)) {
        match = extractmatch(queue);

        w = winner(match);
        l = loser(match);

        push(w, &winnersTop);
        push(l, &losersTop);

        printmatch(output, match);  
    }

    fprintf(output, "\nWINNERS OF ROUND NO:%d\n", nr_round);
    for(Node * n = winnersTop; n != NULL; n = n -> next) printwinner(output, n);

    deleteStack(&losersTop);
    nr_round++;
    if(winnersTop -> next != NULL) play(output, &winnersTop, queue, nr_round);
    else return (winnersTop -> team);
}

void task3(FILE * output, Node ** node) {
    Q * queue = NULL;
    queue = createqueue();
    Team * TheBigWinner;
    int nr_round = 1;
    TheBigWinner = play(output, node, queue, nr_round);
}