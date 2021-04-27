// Prim's Algorithm - Minimum Spanning Tree
// Using the Adjecency Matrix
// Time Complexity : O(V^2)

#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    int graph[20][20];
    Graph(){
        cout << "Enter the No. of Vertices : ";
        cin >> V; 
    }
    void CreateGraph();
    int minKey(int a[], bool b[]);
    void printMST(int x[]);
    void primMST();
};

void Graph :: CreateGraph(){
    cout << "Enter the Adjecency Matrix : \n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin >> graph[i][j];
        }
    }
}

int Graph :: minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index;
    for(int i=0; i<V;i++){
        // find vertex with min key value, which are not in mstSet and are less than the Min value 
        if(mstSet[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void Graph :: printMST(int parent[]){
    cout << "\nEdge \tWeight\n";
    int wt = 0;
    for(int i=1;i<V;i++){
        cout << parent[i] << " - " << i << "\t " << graph[i][parent[i]] << "\n";
        wt+=graph[i][parent[i]];
    }
    cout << "\nTotal Minimum Weight : " << wt;
}

void Graph :: primMST(){
    int parent[V]; // Store MST
    int key[V];    // Store key values
    bool mstSet[V];// Vertices included in MST

    // initialize key array with infinity
    // initialize mst array with false/not visited
    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;   // first vertex is always set 0
    parent[0] = -1; // root node of mst

    for(int count = 0; count < V; count++){
        // pick vertex with min key
        int u = minKey(key, mstSet);

        // add the picked min key vextex in the mstSet
        mstSet[u] = true;

        for(int v=0;v<V;v++){
            if (graph[u][v] && mstSet[v]==false && graph[u][v]<key[v]){ 
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent);
}

int main(){
    Graph g;
    g.CreateGraph();
    g.primMST();
    
    return 0;
}

/* The entire implementation of this algorithm is identical to that of Dijkstra’s algorithm. The running time is O(|V|^2) without heaps [good for dense graphs], and O (ElogV) using binary heaps [good for sparse graphs]. */
