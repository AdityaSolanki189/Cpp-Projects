// Connected Components and Strongly(mainly directed) & Weakly(non-directed) Connected Components
// Using the DFS traversal we first get list of visited nodes then, iterate over the not-visited nodes and count the components
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> AdjList[100001]; // Adjecency List
    int visited[100001];

    public:
    Graph(int);
    void addEdge(int, int);
    void DFS(int);
    int Connected_Components();
};

int Graph :: Connected_Components(){
    int count = 0;

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            DFS(i), count++;
        }
    }
 
    return count;
}

Graph::Graph(int V){
    this->V = V;
}
 
// Undirected Graph
void Graph::addEdge(int v, int w){ 
    AdjList[v].push_back(w);
    AdjList[w].push_back(v);
}

void Graph :: DFS(int node){
    visited[node] = 1;
    for(int next : AdjList[node]){
        if(!visited[next]){
            DFS(next);
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
    
    cout << "\nNo. of Connected Components : " << g.Connected_Components() << "\n";

    return 0;
}