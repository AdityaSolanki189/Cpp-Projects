#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int V; // nodes
    // Adjacency List
    vector<int> AdjList[101];    

    public:
    Graph(int Nodes){
        V = Nodes;
    }
    void AddEdge(int, int);
    void Display();
};

// Undirected 
void Graph :: AddEdge(int from , int to){
    AdjList[from].push_back(to);
    AdjList[to].push_back(from);
}

// Display
void Graph :: Display(){
    for(int i = 1; i <= V; i++){
        cout << "Adjacency Node  of " << i << " : ";
        for(auto node: AdjList[i]){
            cout << node << " ";
        }
        cout << "\n";
    }
}

int main(){
    int nodes;
    cout << " Enter Nodes :";
    cin >> nodes;

    Graph g(nodes);

    int Edges, from, to;
    cout << " Enter Edges : ";
    cin >> Edges;

    while(Edges--){
        cout << " Enter from and T0 : ";
        cin >> from >> to;
        g.AddEdge(from, to);
    }

    g.Display();

    return 0;
}