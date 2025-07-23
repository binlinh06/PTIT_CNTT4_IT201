#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int V;
    int **matrix;
}Graph;
Graph* createGraph(int V) {
    Graph* graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)calloc(V, sizeof(int));
    }
    return graph;
}
void Edge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
}
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] != 0)
                printf("%d->", j);
        }
        printf("NULL\n");
    }
}
int main() {
    Graph* graph = createGraph(3);
    Edge(graph, 0, 2);
    Edge(graph, 1, 1);
    Edge(graph, 2, 0);
    printGraph(graph);
    return 0;
}