#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

struct myGraph{
    int numOfNodes;
    bool **edges;
}

graph* creategraph(int nodes){
    myGraph* g = malloc(sizeof(*g));

    //if we can't make the graph, return NULL
    if(g = NULL){
        return NULL;
    }

    g->numOfNodes = nodes;

    //alocate edges (use calloc(sizeOfType, howManyOfThatType) to initialize all values to 0) 
        //-- we want edges that are connected to have a value of 1
    g->edges = calloc(sizeof(bool *), g->numOfNodes);

    //if we can't make the edges, free the graph from memory and return NULL
    if(g->edges == NULL){
        free(g);
        return NULL;
    }


}

void destroygraph(graph* g){}

void printgraph(graph* g){}

bool add_edge(graph* g, int fromNode, int toNode){}

bool has_edge(graph* g, int fromNode, int toNode){}