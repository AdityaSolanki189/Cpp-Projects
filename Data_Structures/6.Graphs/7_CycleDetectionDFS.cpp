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
    bool checkforCycle(int, int);
    string cyclesDFS();
};

// Undirected Graph
void Graph::addEdge(int v, int w){
    AdjList[v].push_back(w); 
    AdjList[w].push_back(v);
}

bool Graph :: checkforCycle(int node, int parent){
    visited[node] = 1;
    for(auto it: AdjList[node]){
        if(visited[it] == 0){
            if(checkforCycle(it, node)){ 
                return true;
            }
        }
        else if(it != parent){
            return true;
        }
    }
    return false;
}

string Graph :: cyclesDFS(){
    for(int i=1; i<=V; i++){
        if(!visited[i]){
            if(checkforCycle(i, -1)) return "Yes!";
        }
    }
    return "No!";
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

    cout << "\nCycles Detected ? - " << g.cyclesDFS();
    cout << "\n";
     
    return 0;
}