#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    map<int, bool> visited;
    map<int, list<int>> AdjNode;

    void addEdge(int, int);
    void DFS(int);
};

void Graph :: addEdge(int v, int w){
    AdjNode[v].push_back(w);
}

void Graph :: DFS(int v){
    visited[v] = true;
    cout << v << " ";

    list<int> :: iterator i;
    for(i = AdjNode[v].begin(); i != AdjNode[v].end(); ++i){
        if(!visited[*i])
            DFS(*i);
    }
}
 
// Time Complexity : O(V + E)
// Space Complexity: O(V)

int main(){
    Graph g;
    g.addEdge(2, 0);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addEdge(3, 3);
    g.addEdge(1, 3);

    int vertex;
    cout << "\nEnter Starting Vertex : ";
    cin >> vertex;

    cout << "\nThe Depth First Search of Tree (Starting Vertex " << vertex << " : ";
    g.DFS(vertex);
    cout << "\n";

    return 0;
}


// Diconnected Graph (Corner Case Condition)
/* class Graph {

    void DFSUtil(int v);
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    
    void addEdge(int v, int w);
 
    void DFS();
};
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); 
}
 
void Graph::DFSUtil(int v){
    
    visited[v] = true;
    cout << v << " ";
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i])
            DFSUtil(*i);
    }        
}
 
// The function to do DFS traversal. It uses recursiveDFSUtil()
void Graph::DFS(){
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (auto i:adj){
        if (visited[i.first] == false)
            DFSUtil(i.first);
    }        
} 
*/