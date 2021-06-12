// Linear ordering of vextices such that if there is an Edge u->v, then u appears before v in that Ordering. (ON Directed Acyclic Graph using BFS).
// Kahn's Algorithm (Using in-degree of each node)
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> AdjList[101]; // Adjecency List

    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int);
    void topoSort();
};

// Directed Graph
void Graph :: addEdge(int v, int w){
    AdjList[v].push_back(w);
}

void Graph :: topoSort(){
    queue<int> Q;
    vector<int> indegree(V, 0);

    for(int i=0; i<V; i++){
        for(auto it: AdjList[i]){
            indegree[it]++;
        }
    }

    for(int i=0;i<V;i++){
        if(indegree[i] == 0){
            Q.push(i);
        }
    }

    vector<int> topo;

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        topo.push_back(node);
        for(auto it: AdjList[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                Q.push(it);
            }
        }
    }

    for(int i=0;i<V;i++){
        cout << topo[i] << " ";
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

    cout << "\nThe TopoSort of Graph (using BFS) : ";
    g.topoSort();
    cout << "\n";

    return 0;
}