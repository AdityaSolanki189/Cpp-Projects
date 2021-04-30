// Find the Shortest Path/Distance in an Undirected Graph with Unit Weights.
// with the help of the BFS Algorithm
// Given a Source node, find the Distance from this node to everyother node in the Graph. 
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
    void findDistance(int);
};

// Undirected Graph
void Graph :: addEdge(int v, int w){
    AdjList[v].push_back(w);
    AdjList[w].push_back(v);
}

void Graph :: findDistance(int source){
    int distance[V];
    for(int i=0;i<V;i++) distance[i] = INT_MAX;
    queue<int> Q;

    distance[source] = 0;
    Q.push(source);

    while (!Q.empty()){
        int node = Q.front();
        Q.pop();

        for(auto it: AdjList[node]){
            if(distance[node] + 1 < distance[it]){
                distance[it] = distance[node] +1;
                Q.push(it);
            }
        }
    }

    for(int i=0;i<V;i++) cout << distance[i] << " ";    
}

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

    int src;
    cout << "\nEnter the Source Node : ";
    cin >> src;

    cout << "\nShortest Distance from Each Node : ";
    g.findDistance(src);
    cout << "\n";

    return 0;
}