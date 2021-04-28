#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> AdjList[100001]; // Adjecency List
    int visited[100001] = {0};

    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int);
    void DFS(int);
    void DfsOfGraph();
};

void Graph :: addEdge(int v, int w){
    AdjList[v].push_back(w);
    AdjList[w].push_back(v);
}

void Graph :: DFS(int node){
    cout << node << " ";
    visited[node] = 1;

    for(auto it: AdjList[node]){
        if(!visited[it])
            DFS(it);     // recursive call for backtracking
    }
}

void Graph :: DfsOfGraph(){
    for(int i=1; i<=V; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}
 
// Time Complexity : O(V + E)
// Space Complexity: O(V)

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

    cout << "\nThe Depth First Search of Tree : ";
    g.DfsOfGraph();
    cout << "\n";

    return 0;
}