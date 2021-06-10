#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph{
    int V;
    vector<int> AdjList[101]; // Adjecency List
    int visited[101] = {0};

    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int);
    void BFS();
    void DFS(int);
    void DfsOfGraph();
};

// Undirected and Unweighted Graph
void Graph::addEdge(int v, int w){
    AdjList[v].push_back(w); 
    AdjList[w].push_back(v);
}

void Graph :: BFS(){
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            queue<int> Q;
            Q.push(i);
            visited[i] = 1;

            while(!Q.empty()){
                int node = Q.front();
                cout << node << " ";
                Q.pop();

                for(auto it: AdjList[node]){
                    if(!visited[it]){
                        Q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
}

void Graph :: DFS(int node){
    cout << node << " ";
    visited[node] = 1;

    for(auto it: AdjList[node]){
        if(!visited[it])
            DFS(it);     // recursive call for backtracking
    }
}

void Graph :: DfsOfGraph(){
    for(int i=1; i<=V; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
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

    cout << "\nSelect the Traversal Approach : \n";
    cout << "1. Breadth First Search Traversal.\n";
    cout << "2. Depth First Search Traversal.  \n";
    int ch;
    cin >> ch;
    switch (ch){
        case 1:
            cout << "\nThe BFS Traversal of the Tree : ";
            g.BFS(); 
            cout << "\n";
        break;
    
        case 2:
            cout << "\nThe DFS Traversal of the Tree : ";
            g.DfsOfGraph(); 
            cout << "\n";
        break;

        default:
        break;
    }
    return 0;
}