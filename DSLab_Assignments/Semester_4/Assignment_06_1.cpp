//MST - Prims Algorithm.
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Graph{
    int V;
    vector<pair<int, int>> AdjList[101];
    
    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int, int);
    void primsAlgo();
};

// Undirected Weighted Graph
void Graph :: addEdge(int from, int to, int weight){
    AdjList[from].push_back(make_pair(to, weight));
    AdjList[to].push_back(make_pair(from, weight));
}

void Graph :: primsAlgo(){ 
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i=0; i<V; i++){
        key[i] = INT_MAX; 
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;   
    parent[0] = -1;

    for(int count=0; count<V-1; count++){ //Since, ST has V-1 Edges
        int mini = INT_MAX, u;

        for(int i=0; i<V; i++){
            if(mstSet[i] == false && key[i] < mini){
                mini = key[i];
                u = i;
            }
        }

        mstSet[u] = true;

        for(auto it: AdjList[u]){
            int v = it.first;
            int weight = it.second;
            if(mstSet[v] == false && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    cout << "\nThe Minimum Spanning Tree : \n";

    for(int i=1; i<V; i++){
        cout << parent[i] << " - " << i << "\n";
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

    g.primsAlgo();
    return 0;
}