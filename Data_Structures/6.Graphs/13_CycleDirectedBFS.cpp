// Kahn's Algorithm (Using in-degree of each nodes)
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
    string isCyclic();
};

// Directed Graph
void Graph :: addEdge(int v, int w){
    AdjList[v].push_back(w);
}

string Graph :: isCyclic(){
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

    int count = 0;

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        count++;
        for(auto it: AdjList[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                Q.push(it);
            }
        }
    }

    if(count == V) return "No!";
    return "Yes!"; 
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

    cout << "\nIs it a Cyclic Directed Graph? - " << g.isCyclic();
    cout << "\n";

    return 0;
}