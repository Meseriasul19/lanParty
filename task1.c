#include "tasks.h"

void task1(FILE * input, FILE * output, Node ** node, int * v, int nr_teams) {
    //citire
    for(int i = 0; i < nr_teams; i++) { 

        int nr_players;
        float team_p = 0;
        char buffer[50];

        fscanf(input, "%d", &nr_players);
        fseek(input, 1L, SEEK_CUR);
        fgets(buffer, 50, input);
        buffer[strlen(buffer)-1] = '\0';

        insertTeam (node , nr_players, buffer);
        
        for(int j = 0; j < nr_players; j++)
        {
            int points;
            char buffer2[50];

            fscanf(input, "%s", buffer);
            fscanf(input, "%s", buffer2);

            fscanf(input, "%d", &points);
            team_p += points;
            fseek(input, 2L, SEEK_CUR);
            insertPlayer (&((*node) -> team -> players[j]), points, buffer, buffer2);
        }
        team_p = team_p / nr_players;
        (*node) -> team -> team_points = team_p;
    }

    //afisare
    if(v[1] == 0 && v[2] == 0 && v[3] == 0 && v[4] == 0)
        for(Node * n = (*node); n!= NULL; n = n -> next) 
            fprintf(output,"%s\n", n->team->team_name);
}


