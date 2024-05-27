#include "tasks.h"

// inseram cele 8 echipe in lista
void generateLeaderBoard(Node ** lb, Node * n) {
    insertTeam(lb, n -> team -> nr_players, n -> team -> team_name);
    (*lb) -> team -> team_points = n -> team -> team_points;
}

// functie ce returneaza castigatorul meciului
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

// functie ce returneaza pierzatorul meciului
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

Team * play(FILE * output, Node ** node, Q * queue, int nr_round, Node ** leaderboard) {
    
    // vector ce va stoca 2 noduri
    Node ** match; 
    match = (Node**)malloc(sizeof(Node*) * 2);

    Node * winnersTop = NULL; // stiva pentru castigatori
    Node * losersTop = NULL; // stiva pentru pierzatori

    // inseram cate doua meciuri in coada (sub forma unui QNode: vezi structura in queue.h)
    for(Node * n = (*node); n != NULL; n = n -> next -> next) {
        insertmatch(n, n-> next, queue);
    }

    int cont = 0; // variabila ce va numara 8 echipe ramase (pentru task 4)

    // simulam campionatul
    fprintf(output, "\n--- ROUND NO:%d\n", nr_round);
    while(!isEmptyQ(queue)) {

        // extragem meciurile din coada
        match = extractmatch(queue);

        // selectam castigatorii si pierzatorii
        push(winner(match), &winnersTop);
        cont++;
        push(loser(match), &losersTop);

        // afisam meciul
        printmatch(output, match);  
    }

    // afisam castigatorii
    fprintf(output, "\nWINNERS OF ROUND NO:%d\n", nr_round);
    for(Node * n = winnersTop; n != NULL; n = n -> next) {
        printwinner(output, n);
        // daca au ramas 8 echipe, le stocam intr-o alta lista
        if(cont == 8) generateLeaderBoard(leaderboard, n);
    }

    deleteStack(&losersTop); // eliberam memoria ocupata de pierzatori
    nr_round++;

    // apelam recursiv (inlocuind lista initiala cu stiva castigatorilor)
    if(winnersTop -> next != NULL) 
        play(output, &winnersTop, queue, nr_round, leaderboard);

    // returneaza castigatorul
    else {
        Team * w = winnersTop -> team;
        deleteStack(&winnersTop);
        return w;
    }
}

void task3(FILE * output, Node ** node, Node ** leaderboard) {

    // cream coada pentru simularea meciurilor
    Q * queue = NULL;
    queue = createqueue();

    Team * TheBigWinner;
    int nr_round = 1;

    //OPTIONAL : finding the big winner of the game
    TheBigWinner = play(output, node, queue, nr_round, leaderboard); 

    free(TheBigWinner);  
}