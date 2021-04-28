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
    bool checkforCycle(int);
    string cyclesBFS();
};

// Undirected Graph
void Graph::addEdge(int v, int w){
    AdjList[v].push_back(w); 
    AdjList[w].push_back(v);
}

bool Graph :: checkforCycle(int s){
    queue<pair<int, int>> Q;
    visited[s] = 1;
    Q.push({s, -1});

    while(!Q.empty()){
        int node = Q.front().first;
        int parent = Q.front().second;
        Q.pop();

        for(auto it: AdjList[node]){
            if(!visited[it]){
                visited[it] = 1;
                Q.push({it, node}); // current node, with parent node
            }
            else if(parent != it){
                return true; // there has to be a cycle
            }
        }
    }
    return false;
}

string Graph :: cyclesBFS(){
    for(int i=1; i<=V; i++){
        if(!visited[i]){
            if(checkforCycle(i)) return "Yes!";
        }
    }
    return "No!";
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

    cout << "\nCycles Detected ? - " << g.cyclesBFS();
    cout << "\n";
     
    return 0;
}