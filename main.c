#include "game.h"

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[2], "rt");

    int numar_echipe;
    fscanf(f, "%d", &numar_echipe);

    Node * node = NULL;

   for(int i = 0; i < numar_echipe; i++) {

        int nr_players;
        char buffer[50];

        fscanf(f, "%d", &nr_players);
        fseek(f, 1L, SEEK_CUR);
        fgets(buffer, 50, f);
        buffer[strlen(buffer)-1] = '\0';

        insertTeam (&node , nr_players, buffer);
        
        for(int j = 0; j < nr_players; j++)
        {
            int points;
            char buffer2[50];

            fscanf(f, "%s", buffer);
            fscanf(f, "%s", buffer2);
            fscanf(f, "%d", &points);
            fseek(f, 2L, SEEK_CUR);

            insertPlayer (&(node -> team -> players[j]), points, buffer, buffer2);
        }

   }

   fclose(f);

   //afisare

   f = fopen(argv[3], "wt");

   if(f == NULL) {
    printf("Nu s-a deschis");
   }

    for(Node * n = node; n!= NULL; n = n -> next) 
        fprintf(f,"%s\n", n->team->team_name);

    return 0;
}