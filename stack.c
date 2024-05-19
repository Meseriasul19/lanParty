#include "stack.h"

int isEmptyS(Node * top) {
    return(top == NULL);
}

void push(Node * team, Node ** topteam) {
    team -> next = (*topteam); 
    (*topteam) = team;
}

void deleteStack(Node ** top) {
    Node * temp;
    while(!isEmptyS(*top)) {
        temp = (*top);
        (*top) = (*top) -> next;
        free(temp);
    }
}