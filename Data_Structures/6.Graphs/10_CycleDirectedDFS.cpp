// Detecting a Cycle in a Directed Graph using the DFS Traverasl
// Bipartite Grapgh is a graph that can be coloured only using 2 colours such that NO TWO Adjecent Nodes have the Same Colour.
// If the Grpah has a Odd Length Cycle -> Not Bipartite | Even Length Cycle -> Bipartite
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> AdjList[100001]; // Adjecency List

    public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int, int);
    bool checkCycle(int src, int vis[], int dfsVis[]);
    string isCyclic();
};

// DIRECTED Graph
void Graph::addEdge(int v, int w){
    AdjList[v].push_back(w); 
}

bool Graph :: checkCycle(int node, int vis[], int dfsVis[]){
    vis[node] = 1;
    dfsVis[node] = 1;

    for(auto it: AdjList[node]){
        if(!vis[it]){
            if(!checkCycle(it, vis, dfsVis)){
                return true;
            }
        }
        else if(dfsVis[it]){
            return true;
        }
    }
    
    dfsVis[node] = 0;
    return false;
}

string Graph :: isCyclic(){
    int vis[V], dfsVis[V];
    memset(vis, 0, sizeof(vis));
    memset(dfsVis, 0, sizeof(dfsVis));

    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(checkCycle(i, vis, dfsVis)) {
                return "YES!\n";
            }
        }
    }
    return "NO!\n";
}

// Time Complexity : O(V + E)

int main(){
    int vertex;
    cout << "\nThe Total Vertices : ";
    cin >> vertex;
    Graph g(vertex);

    int Edges, from, to;
    cout << "\nTotal Edges : ";
    cin >> Edges;

    while(Edges--){
        cout << "Enter From and To : ";
        cin >> from >> to;
        g.addEdge(from, to);
    }

    cout << "\nIs it a Cyclic Directed Graph? - " << g.isCyclic();
    cout << "\n";
     
    return 0;
}