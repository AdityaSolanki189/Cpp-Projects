//Dijkstra's Single Shortest Path Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph{
    int V;
    vector<pair<int, int>> AdjList[101];
    
    public:
    Graph(int nodes){
        V = nodes;
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