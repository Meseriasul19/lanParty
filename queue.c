#include "queue.h"

Q * createqueue() {
    Q * q;
    q = (Q*)malloc(sizeof(Q));
    if(!q) return NULL;
    q -> front = q -> rear = NULL;
    return q;
}

int isEmptyQ(Q * q){
    return q -> front == NULL;
}

void insertmatch(Node * team1, Node * team2, Q * q) {
    Qnode * newmatch = (Qnode *)malloc(sizeof(Qnode));
    newmatch -> team1 = team1;
    newmatch -> team2 = team2;
    newmatch -> next = NULL;
    if(q -> rear == NULL) {
        q -> rear = newmatch;
    }
    else {
        q -> rear -> next = newmatch;
        q -> rear = newmatch;
    }
    if(q -> front == NULL) q -> front = q -> rear;
}

Node ** extractmatch(Q * q) {
    if(isEmptyQ(q)) return NULL;
    Node ** teams = (Node **)malloc(sizeof(Node*)*2);
    Qnode * aux = q -> front;
    teams[0] = q -> front -> team1;
    teams[1] = q -> front -> team2;
    q -> front = q -> front -> next;
    free(aux);
    return teams;
}