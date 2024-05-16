#include "game.h"

//adaugare element
void insertTeam ( Node ** prevNode , int nr, char name[]) {

    if(*prevNode == NULL) {
        *prevNode =( Node *) malloc ( sizeof ( Node ));  
        (*prevNode) -> team =( Team *) malloc ( sizeof ( Team ));  
        (*prevNode) -> team -> players = ( Player *)malloc(sizeof(Player) * nr); 

        (*prevNode) -> team -> nr_players = nr;
        (*prevNode) -> team -> team_name = (char*)malloc(sizeof(char) * (strlen(name)+1));
        strcpy((*prevNode) -> team -> team_name, name);

        (*prevNode) -> next = NULL;

        return;
    }

    Node * newNode =( Node *) malloc ( sizeof ( Node ));  
    newNode -> team =( Team *) malloc ( sizeof ( Team ));  
    newNode -> team -> players = ( Player *)malloc(sizeof(Player) * nr); 
                       
    newNode -> team -> nr_players = nr;
    newNode -> team -> team_name = (char*)malloc(sizeof(char) * (strlen(name)+1));
    strcpy(newNode -> team -> team_name, name);

    newNode -> next = *prevNode;                               
    *prevNode = newNode ;                                       
}

void insertPlayer(Player * players ,int p, char fName[], char sName[]) {

    players -> points = p; 

    players -> firstName = (char*)malloc(sizeof(char) * (strlen(fName)+1));
    strcpy(players -> firstName, fName);

    players -> secondName = (char*)malloc(sizeof(char) * (strlen(sName)+1));
    strcpy(players -> secondName, sName);
}

