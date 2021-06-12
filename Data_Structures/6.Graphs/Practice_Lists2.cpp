#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int V; // nodes
    // Adjacency List
    vector<pair<int, int>> AdjList[101];    

    public:
    Graph(int Nodes){
        V = Nodes;
    }
    void AddEdge(int, int, int);
    void Display();
};

// Undirected 
void Graph :: AddEdge(int from , int to, int weight){
    AdjList[from].push_back(make_pair(to, weight));
    AdjList[to].push_back(make_pair(from, weight)); 
}

// Display
void Graph :: Display(){
    for(int i = 1; i <= V; i++){
        cout << "Adjacency Node  of " << i << " : ";
        for(auto node: AdjList[i]){
            cout << "(" <<node->first << ", " << node->second << ")" << " ";
        }
        cout << "\n";
    } 
}

int main(){
    int nodes;
    cout << " Enter Nodes :";
    cin >> nodes;

    Graph g(nodes);

    int Edges, from, to, weight;
    cout << " Enter Edges : ";
    cin >> Edges;

    while(Edges--){
        cout << " Enter from and T0 & weight: ";
        cin >> from >> to >> weight;
        g.AddEdge(from, to,weight);
    }

    g.Display();

    return 0;
}