#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int V;
    int **matrix;
}Graph;
//Tao ham cap phat bo nho cho Graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int** )malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)calloc(V, sizeof(int));
    }
    return graph;
}
//Ham ket noi giua 2 dinh
void Edge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

//In vo huong
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ",graph->matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    //Khoi tao Graph vo huong
    Graph* graph = createGraph(4);

    Edge(graph, 0, 1);
    Edge(graph, 0, 2);
    Edge(graph, 1, 2);
    Edge(graph, 2, 3);

    printGraph(graph);
    return 0;
}