#include <stdbool.h>


typdef struct mygraph graph;


graph* creategraph(int numOfNodes);

void destroygraph(graph* g);

void printgraph(graph* g);

bool add_edge(graph* g, int fromNode, int toNode);

bool has_edge(graph* g, int fromNode, int toNode);