// The Prims' Efficient Solution Using Heap and Priority Queue
// Time Complexity : O(nlogn)
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph{
    int V;
    vector<pair<int, int>> AdjList[101];
    
    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int, int);
    void EfficientPRIM();
};

// Undirected Weighted Graph
void Graph :: addEdge(int from, int to, int weight){
    AdjList[from].push_back(make_pair(to, weight));
    AdjList[to].push_back(make_pair(from, weight));
}

void Graph :: EfficientPRIM(){ 
    int parent[V+1];
    int key[V+1];
    bool mstSet[V+1];
    for(int i=0; i<=V; i++){
        key[i] = INT_MAX; 
        mstSet[i] = false;
        parent[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

    //Let the Source be Node 0
    key[0] = 0;   
    parent[0] = -1;
    PQ.push({0, 0});

    for(int count=0; count<V; count++){
        
        int u = PQ.top().second;
        PQ.pop();

        mstSet[u] = true;

        for(auto it: AdjList[u]){
            int v = it.first;
            int weight = it.second;
            if(mstSet[v] == false && weight < key[v]){
                key[v] = weight;
                PQ.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "\nThe Minimum Spanning Tree : \n";
    cout << "\nAdjacency List : \n";
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

    g.EfficientPRIM();
    return 0;
}