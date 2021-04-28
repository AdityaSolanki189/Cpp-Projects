// Kruskal's Algorithm - Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source, destination, weight;
};

// For a Undirected and Weighted Graph
class Graph{
    public:
    int V, E;
    // Edge(source -> destination) = Edge(destinaion -> source)
    Edge* edge; 
};

Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge;

    return graph;
}

// Using Union-Find Algorithm to detect cycles in a Graph
class subset{
    public:
    int parent, rank;
};

int find(subset subsets[], int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparing Two edges according to their Weights
int Compare(const void* a, const void* b){
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph){
    int V = graph->V;
    Edge result[V];
    int e = 0; // index for result 
    int i = 0; // index for sorted edges

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), Compare);

    subset* subsets = new subset[(V * sizeof(subset))];

    for(int v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E){
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.destination);
 
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
 
    cout << "Following are the edges in the constructed MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i){
        cout << result[i].source << " -- " << result[i].destination << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    
    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}

int main(){
    /* Let us create following weighted graph
            10
        0--------1
        | \ |
    6| 5\ |15
        | \ |
        2--------3
            4 */
    int V = 4; 
    int E = 5; 
    Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].source = 0;
    graph->edge[0].destination= 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].source = 0;
    graph->edge[1].destination= 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].source = 0;
    graph->edge[2].destination= 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].source = 1;
    graph->edge[3].destination= 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].source = 2;
    graph->edge[4].destination = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);   
    return 0;
}



