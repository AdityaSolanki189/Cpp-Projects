#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    Graph(int V){
        V = V;
    }
    vector<pair<int, int>> AdjList[101];
    void addEdge(int, int, int);
};

void Graph :: addEdge(int from, int to, int weight){
    AdjList[from].push_back(make_pair(to, weight));
    AdjList[to].push_back(make_pair(from, weight));
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

    //vector<vector<int>> AdjList(vertex); // List using vec of vec
    //vector<int> AdjList[vertex+1]; // List using vec or array
    // vector<pair<int, int>> AdjList[vertex+1];
    
    // adjMat Object for storing N Adecency Lists
    // Accepting Directed edges (ex. 0 -> 1) 
    /* for(int i=0;i<Edges;++i){
        int from, to;
        cin >> from >> to;
        AdjList[from].push_back(to);
    } */

    // Accepting Undirected Edges
    /* for(int i=0;i<Edges;i++){
        int from, to;
        cin >> from >> to;
        AdjList[from].push_back(to);
        AdjList[to].push_back(from);
    } */

    // Accepting Undirected Weighted Graph
    /* for(int i=0;i<Edges;i++){
        int from, to, wt;
        cin >> from >> to >> wt;
        AdjList[from].push_back({to, wt});
        AdjList[to].push_back({from, wt});
    } */

    // Printing the Adjecency List Unweighted
    /* for(int i=0;i<vertex;++i){
        cout << "AdjList of " << i << " : ";
        for(int node : AdjList[i]){
            cout << node << ", ";
        }
        cout << "\n";
    } */

    // Printing the Adjecency List Weighted
    for(int i=1;i<=vertex;++i){
        cout << "AdjList of " << i << " : ";
        for(auto node : g.AdjList[i]){
            cout << "(" << node.first << ", " << node.second << ")" << ", ";
        }
        cout << "\n";
    }
    return 0;
}