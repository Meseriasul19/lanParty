#include "tasks.h"
//argv[1] = c.in (task-ul)
//argv[2] = d.in (fisierul citit)
//argv[3] = out.out (fisierul in care scriu)

int main(int argc, char *argv[])
{ 
    FILE * tasks = fopen(argv[1], "rt");
    FILE * input = fopen(argv[2], "rt");
    FILE * output = fopen(argv[3], "at");
    
    int nr_teams;
    fscanf(input, "%d", &nr_teams);
    Node * node = NULL;

    int * v = (int*)malloc(sizeof(int) * 5);
    for(int i=0; i<5; i++) fscanf(tasks, "%d", &v[i]);

    if (v[0]) task1(input, output, &node, v, nr_teams); //TASK 1
    if (v[1]) task2(output, &node, nr_teams); 
    /*
    if (v[2]) task3(output, &node, nr_teams);
    if (v[3]) task4(output, &node, nr_teams);
    if (v[4]) task5(output, &node, nr_teams);
    */

    free(v);
    fclose(tasks);
    fclose(input);
    fclose(output);

    return 0;
}