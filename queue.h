#pragma once
#include "struct.h"

typedef struct elem {
    Node * team1;
    Node * team2;
    struct elem * next;;
} Qnode;

typedef struct Q {
    Qnode * front;
    Qnode * rear;
} Q;

Q * createqueue();
int isEmptyQ(Q *);
void insertmatch(Node *, Node *, Q *);
Node ** extractmatch(Q * );