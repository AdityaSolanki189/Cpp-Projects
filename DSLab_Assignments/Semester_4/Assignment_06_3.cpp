/* Represent a given graph using adjacency array and generate a minimum spanning tree using kruskal or prim’s algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

//Structure to represent weighted edge
struct Edge {
    int src, dest, weight;
};

//Structure to represent a connected Graph
struct Graph{
    int V;
    int E;
    struct Edge* edge;
};

//Create a graph with V vertices nd E edges
struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> V = V;
    graph -> E = E;
    
    graph -> edge = (struct Edge*)malloc(graph -> E *sizeof(struct Edge));
    
    return graph;
};

// A Structure to represent a subset for union and find
struct subset{
    int parent;
    int rank;
};

//Find set of an element
//Path compression technique
int find(struct subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
}

//A function that does union of two sets x & y
//(uses union by rank)
void Union(struct subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    //Attach smaller rank tree under root of higher rank tree
    // Union(by Rank)
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
        
    //If ranks are same, then make one as root and increment
    // its rank by one
    
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int myComp(const void* a, const void* b){
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    
    return a1 -> weight > b1 -> weight;
}

// The main function to construct MST using Kruskal's
// algorithm
void KruskalMST(Graph* graph){
    int V = graph->V;
    Edge result[V]; // Tnis will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges
 
    // Step 1: Sort all the edges in non-decreasing
    // order of their weight. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
          myComp);
 
    // Allocate memory for creating V ssubsets
    subset* subsets = new subset[(V * sizeof(subset))];
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E){
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the
    // built MST
    cout << "Following are the edges in the constructed "
            "MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i){
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    // return;
    cout << "Minimum Cost Spanning Tree: " << minimumCost<< endl;
}


int main(){
    int V = 4;
    int E = 5;
    struct Graph* graph = createGraph(V, E);
    
    //add Edge 0-1
    graph -> edge[0].src = 0;
    graph -> edge[0].dest = 1;
    graph -> edge[0].weight = 10;
    
    //add Edge 0-2
    graph -> edge[1].src = 0;
    graph -> edge[1].dest = 2;
    graph -> edge[1].weight = 6;
    
    //add Edge 0-3
    graph -> edge[2].src = 0;
    graph -> edge[2].dest = 3;
    graph -> edge[2].weight = 5;    
    
    //add Edge 1-3
    graph -> edge[3].src = 1;
    graph -> edge[3].dest = 3;
    graph -> edge[3].weight = 15;
    
    //add Edge 2-3
    graph -> edge[4].src = 2;
    graph -> edge[4].dest = 3;
    graph -> edge[4].weight = 4;    
        
    KruskalMST(graph);

    return 0;
}