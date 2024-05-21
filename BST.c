#include "tree.h"

treeNode * newNode ( Team * team ) {
    treeNode * node = ( treeNode *) malloc ( sizeof ( treeNode ));
    node -> team = team ;
    node -> left = node -> right = NULL ;
    return node ;
}

treeNode * insert ( treeNode * node , Team * team){
    if ( node == NULL ) return newNode ( team ); 

    if ( team -> team_points < node -> team -> team_points)   
        node -> left = insert (node -> left , team );
    else if (team -> team_points > node -> team -> team_points)
        node -> right = insert (node -> right , team );
    else if (team -> team_points == node -> team -> team_points) {
        if(strcmp(team -> team_name, node -> team -> team_name ) > 0) 
            node -> right = insert (node -> right , team );
        else
            node -> left = insert (node -> left , team );
    }
    
    return node ;  
} 

void printTreeNode(FILE * output, treeNode * node) {
    fprintf(output ,"%s",node -> team -> team_name);
    for(int i = 0; i < (34 - strlen(node -> team -> team_name)); i++) fprintf(output, " ");
    fprintf(output, "-");
    for(int i = 0; i < 2; i++) fprintf(output, " ");
    fprintf(output, "%.2f\n", node -> team -> team_points);
}

void inorder ( FILE * output, treeNode * root ){
    if ( root ){
        inorder (output, root -> right);
        printTreeNode(output, root);
        inorder (output, root -> left);   
    }
}