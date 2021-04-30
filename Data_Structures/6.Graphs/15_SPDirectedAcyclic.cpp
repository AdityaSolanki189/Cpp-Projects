// Finding the Shortest Path in a Weighted Directed Acyclic Graph (DAG) 
// Using DFS Algorithm TopoSort
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<pair<int, int>> AdjList[100001]; // Adjecency List (from, to, weight)
    stack<int> S;

    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int, int);
    void findTopoSort(int node, int visited[]);
    void findDistance(int);
};

// Directed Weighted Graph
void Graph :: addEdge(int from, int to, int weight){
    AdjList[from].push_back({to, weight});
}

void Graph :: findTopoSort(int node, int visited[]){
    visited[node] = 1;

    for(auto it: AdjList[node]){
        if(!visited[it.first]){
            findTopoSort(it.first, visited);
        }
    }
    S.push(node);
}

void Graph :: findDistance(int source){ 
    int visited[V] = {0};
    for(int i=0;i<V;i++){
        if(!visited[i]){
            findTopoSort(i, visited);
        }
    }

    int distance[V];
    for(int i=0;i<V;i++) distance[i] = INT_MAX;
    distance[source] = 0;

    while(!S.empty()){
        int node = S.top();
        S.pop();

        if(distance[node] != INT_MAX){
            for(auto it: AdjList[node]){
                if(distance[node] + it.second < distance[it.first]){
                    distance[it.first] = distance[node] + it.second; 
                }
            }
        }
    }
    
    for(int i=0;i<V;i++){
        if(distance[i] == INT_MAX){
            cout << "INF ";
        }
        else cout << distance[i] << " "; 
    }
}

int main(){
    int vertex;
    cout << "\nThe Total Vertices : ";
    cin >> vertex;
    Graph g(vertex);

    int Edges, from, to, weight;
    cout << "\nTotal Edges : ";
    cin >> Edges;

    while(Edges--){
        cout << "Enter From, To and Weight of Edge : ";
        cin >> from >> to >> weight;
        g.addEdge(from, to, weight);
    }

    int src;
    cout << "\nEnter the Source Node : ";
    cin >> src;

    cout << "\nShortest Distance from Each Node : ";
    g.findDistance(src);
    cout << "\n";

    return 0;
}