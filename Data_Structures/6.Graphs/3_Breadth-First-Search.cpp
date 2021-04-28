#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> AdjList[100001]; // Adjecency List
    int visited[100001] = {0};

    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int, int);
    void BFS();
};

// Undirected Graph
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

// Time Complexity : O(V + E)

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

    cout << "\nThe BFS Traversal of the Tree : ";
    g.BFS(); // Like Linear Order Traverasl in Trees
    cout << "\n";
     
    return 0;
}