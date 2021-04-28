#include <bits/stdc++.h>
using namespace std;

// vector<int> AdjList[100]; // 100 nodes

int run_bfs(int s, vector<bool> &visited){
    queue<int> Q;
    visited[s] = true;
    int node_count = 0;
    while(!Q.empty()){
        s = Q.front();
        Q.pop();
        node_count += 1;

        for(int adjNode: )
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    // N -> Vertices
    // M -> Edges);
    vector<vector<int>> AdjList(n);
    // adjMat Object for storing N Adecency Lists
    // Accepting Directed edges (ex. 0 -> 1) 
    for(int i=0;i<m;++i){
        int from, to;
        cin >> from >> to;
        AdjList[from].push_back(to);
    }
    // Printing the Adjecency Matrix
    /* for(int i=0;i<n;++i){
        cout << "AdjList of " << i << " : ";
        for(int node : AdjList[i]){
            cout << node << ", ";
        }
        cout << "\n";
    } */

    const int INF = 100000000;

    vector<bool> visited(n, false);
    vector<int> entryTime(n, INF);

    int t = 0;
    int s = 0;
    visited[s] = true;
    entryTime[s] = t;
    t++;
    dist[s] = 0;


    queue<int> Q;
    Q.push(s);

    while(!Q.empty()){
        s = Q.front(); Q.pop();
        cout << "We're at Node : " << s << "\n";
        for(int AdjNode: AdjList[s]) if(!visited[AdjNode]){
            visited[AdjNode] = true;
            dist[AdjNode] = dist[s] + 1;
            Q.push(AdjNode);
        }
    }

    for(int i=0;i<n;++i){
        cout << "Distance from " << 0 << " to " << i << " is : " << dist[i] << "\n";
    }
    /* for(int tm = 0; tm < n; ++tm){
    // tm : entry time of the node from
    // where we are going to do the BFS now.
        s = -1;
        for(int node = 0; node < n; ++node){
            if(entryTime[node] == tm){
                s = node;
                break;
            }
        }

        for(int adjNode: AdjList[s]){
            if(!visited[adjNode]){
                visited[adjNode] = true;
                entryTime[adjNode] = t;
                t++;
            }
        }
    } */

    return 0;
}