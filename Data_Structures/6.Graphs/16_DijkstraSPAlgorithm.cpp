// Shortest path in an Undirected Graph using Dijkstra's Algorithm
// Using Priority Queue to always take the path with least distance (Greedy Algorithm)
// Or use set ds as set<pair<int, int>>
// Formula : D(y) = min(old D(x), D(y) + Wt.(x, y))  where, x is the source

#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<pair<int, int>> AdjList[100001];
    
    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int, int);
    void ShortestDistance(int);
};

// Undirected Weighted Graph
void Graph :: addEdge(int from, int to, int weight){
    AdjList[from].push_back(make_pair(to, weight));
    AdjList[to].push_back(make_pair(from, weight));
}

void Graph :: ShortestDistance(int source){ 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ; // min priority queue
    vector<int> distTo(V+1, INT_MAX);

    distTo[source] = 0;
    PQ.push(make_pair(0, source));

    while(!PQ.empty()){
        int dist = PQ.top().first;
        int prev = PQ.top().second;
        PQ.pop();

        vector<pair<int, int>> ::iterator it;
        for(it = AdjList[prev].begin(); it != AdjList[prev].end(); it++){ 
            int next = it->first;           // -> adj. node
            int nextDist = it->second;      // -> edge weight
            if(distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                PQ.push(make_pair(distTo[next], next));
            }
        }
        
        /* for(auto it: AdjList[prev]){ 
            int next = it->first;
            int nextDist = it->second;
            if(distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                PQ.push(make_pair(distTo[next], next));
            }
        } */
    }
    
    for(int i=1; i<=V;i++){
        cout << distTo[i] << " ";
    }
    cout << "\n";
}

// Time Complexity : O((V + E)logV)

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
    g.ShortestDistance(src);
    cout << "\n";

    return 0;
}