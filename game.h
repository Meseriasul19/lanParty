#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char * firstName;
    char * secondName;
    int points;
};

typedef struct Player Player;


struct Team {
    int nr_players;
    char * team_name;
    Player * players;
};

typedef struct Team Team;


struct Node{
    Team * team;
    struct Node * next;
};

typedef struct Node Node;

void insertTeam ( Node ** , int , char[]  );
void insertPlayer(Player *  ,int, char[] , char[] );