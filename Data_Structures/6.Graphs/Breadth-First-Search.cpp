#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int, int);
    void BFS(int);
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); 
}

void Graph :: BFS(int s){
    // setup a visited list
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int> :: iterator i;

    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Time Complexity : O(V + E)

int main(){
    Graph g(6);  // pass the no. of nodes
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    int vertex;
    cout << "\nEnter Starting Vertex : ";
    cin >> vertex;
    
    cout << "\nThe BFS Traversal of the Tree (Starting Vertex "<< vertex << ") : ";
    g.BFS(vertex); // Like Linear Order Traverasl in Trees
    cout << "\n";
     
    return 0;
}