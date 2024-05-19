#include "list.h"

void removeReturn(Node ** node) {
    if ((*node) -> team -> team_name[strlen((*node) -> team -> team_name) - 1] == '\r')
    {
        (*node) -> team -> team_name[strlen((*node) -> team -> team_name) - 1] = '\0';
        (*node) -> team -> team_name = (char*)realloc((*node) -> team -> team_name, strlen((*node) -> team -> team_name));
    } 
}

void removespace(Node ** node) {
    if ((*node) -> team -> team_name[strlen((*node) -> team -> team_name) - 1] == ' ')
    {
        (*node) -> team -> team_name[strlen((*node) -> team -> team_name) - 1] = '\0';
        (*node) -> team -> team_name = (char*)realloc((*node) -> team -> team_name, strlen((*node) -> team -> team_name));
    } 
}

//adaugare element
void insertTeam ( Node ** node , int nr, char name[]) {

    if(* node == NULL) {
        * node =( Node *) malloc ( sizeof ( Node ));  
        (* node) -> team =( Team *) malloc ( sizeof ( Team ));  
        (* node) -> team -> players = ( Player *)malloc(sizeof(Player) * nr); 

        (* node) -> team -> nr_players = nr;

        (* node) -> team -> team_name = (char*)malloc(sizeof(char) * (strlen(name)+1));
        strcpy((* node) -> team -> team_name, name);
        removeReturn(node);
        removespace(node);   

        (* node) -> next = NULL;

        return;
    }

    Node * newNode =( Node *) malloc ( sizeof ( Node ));  
    newNode -> team =( Team *) malloc ( sizeof ( Team ));  
    newNode -> team -> players = ( Player *)malloc(sizeof(Player) * nr); 
                       
    newNode -> team -> nr_players = nr;

    newNode -> team -> team_name = (char*)malloc(sizeof(char) * (strlen(name)+1));
    strcpy(newNode -> team -> team_name, name);
    removeReturn(&newNode);
    removespace(&newNode);
    
    newNode -> next = *node;                               
    *node = newNode ;                                       
}

void insertPlayer(Player * players ,int p, char fName[], char sName[]) {

    players -> points = p; 

    players -> firstName = (char*)malloc(sizeof(char) * (strlen(fName)+1));
    strcpy(players -> firstName, fName);

    players -> secondName = (char*)malloc(sizeof(char) * (strlen(sName)+1));
    strcpy(players -> secondName, sName);
}

void freeTeam(Node * n) {

    for(int i=0; i < (n) -> team -> nr_players; i++) {
        free(n -> team -> players[i].firstName);
        free(n -> team -> players[i].secondName);
    }

    free(n -> team -> players);
    free(n -> team -> team_name);
    free(n -> team);
}

void deleteNode(Node ** n, Node ** prev) {
    if ((*prev) != (*n)) {
        freeNode(n);
        (*prev) -> next = (*n);
    }
    else {
        freeNode(n);
    }
}

void freeNode(Node ** n) {
    freeTeam(*n);
    Node * aux = (*n);
    *n = (*n) -> next;
    free(aux);
}

