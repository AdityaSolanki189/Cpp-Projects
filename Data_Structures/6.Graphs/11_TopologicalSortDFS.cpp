// Linear ordering of vextices such that if there is an Edge u->v, then u appears before v in that Ordering. (ON Directed Acyclic Graph using DFS).

#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> AdjList[100001]; // Adjecency List
    stack<int> S;

    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int);
    void findTopo(int node, vector<int> &visited);
    void topoSort();
};

// Directed Graph
void Graph :: addEdge(int v, int w){
    AdjList[v].push_back(w);
}

void Graph :: findTopo(int node, vector<int> &visited){
    visited[node] = 1;

    for(auto it: AdjList[node]){
        if(!visited[it]){
            findTopo(it, visited);
        }
    }
    S.push(node);
}

void Graph :: topoSort(){
    vector<int> visited(V, 0);

    for(int i=0; i<V; i++){
        if(visited[i] == 0){
            findTopo(i, visited);
        }
    }

    while(!S.empty()){
        int it = S.top();
        cout << it << " ";
        S.pop();
    }
    cout << "\n";    
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

    cout << "\nThe TopoSort of Graph (using DFS) : ";
    g.topoSort();
    cout << "\n";

    return 0;
}