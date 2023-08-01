#include<stdio.h>
#include<stdlib.h>

typedef struct Vertex
{
    int info;
    struct Vertex *prox;
}Vertex;


typedef struct Graph
{
    Vertex *first;

}Graph;

Vertex* create_vertex(int info)
{
    Vertex *new_vertex = (Vertex*)malloc(sizeof(Vertex));

    new_vertex->prox = NULL;
    new_vertex->info = info;

    return new_vertex;
}

Graph* CreateGraph(int number_vertex)
{
    Graph *graph = (Graph*)malloc(number_vertex * sizeof(Graph));

    for(int i = 0 ; i < number_vertex ; i++)
    {
        graph[i].first = NULL; 
    }
    
    return graph;
}

int AddEdge(Graph *graph, int origin, int destiny)
{
    Vertex *new_vertex = create_vertex(destiny);

    // if the graph is directed
    
    new_vertex->prox = graph[origin].first;

    graph[origin].first = new_vertex;

    // if the graph is undirected uncomment this part below

    /*new_vertex = create_vertex(origin);

    new_vertex->prox = graph[destiny].first;

    graph[destiny].first = new_vertex;
    */
   
    return 1; 
}

void PrintGraph(Graph *graph, int number_vertex)
{
    Vertex *aux;

    for(int i = 0; i < number_vertex; i++)
    {
        aux = graph[i].first;
        
        printf("Vertex[%d]:",i);

        while (aux)
        {
            printf("(%d)->",aux->info);

            aux = aux->prox;
        }
        printf("\n");
    }
}

int main()
{
    Graph *graph = CreateGraph(6);

    AddEdge(graph,0,1);
    AddEdge(graph,0,5);
    AddEdge(graph,1,2);
    AddEdge(graph,1,4);
    AddEdge(graph,2,3);
    AddEdge(graph,3,1);
    AddEdge(graph,3,0);
    AddEdge(graph,4,3);
    AddEdge(graph,5,4);

    PrintGraph(graph,6);

    return 1;
}