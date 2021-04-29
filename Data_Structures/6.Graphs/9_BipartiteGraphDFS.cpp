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
    bool BipartiteDFS(int src, int color[]);
    string checkBipartite();
};

// Undirected Graph
void Graph::addEdge(int v, int w){
    AdjList[v].push_back(w); 
    AdjList[w].push_back(v);
}

bool Graph :: BipartiteDFS(int node, int color[]){
    if(color[node] == -1){
        color[node] = 1;
    }
    for(auto it: AdjList[node]){
        if(color[it] == -1){
            color[it] = 1-color[node];
            if(!BipartiteDFS(it, color)){
                return false;
            }
        }
        else if(color[it] == color[node]){
            return false;
        }
    }
    return true;
}

string Graph :: checkBipartite(){
    int color[V];
    memset(color, -1, sizeof(color));
    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if(!BipartiteDFS(i, color)) {
                return "No!\n";
            }
        }
    }
    return "Yes!\n";
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

    cout << "\nIs it a Bipartite Graph? - " << g.checkBipartite();
    cout << "\n";
     
    return 0;
}