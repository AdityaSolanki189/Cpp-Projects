#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    // N -> Vertices
    // M -> Edges);
    //vector<vector<int>> AdjList(n); // List using vec of vec
    //vector<int> AdjList[n+1]; // List using vec or array
    vector<pair<int, int>> AdjList[n+1];
    
    // adjMat Object for storing N Adecency Lists
    // Accepting Directed edges (ex. 0 -> 1) 
    /* for(int i=0;i<m;++i){
        int from, to;
        cin >> from >> to;
        AdjList[from].push_back(to);
    } */

    // Accepting Undirected Edges
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        AdjList[from].push_back(to);
        AdjList[to].push_back(from);
    }

    // Accepting Undirected Weighted Graph
    /* for(int i=0;i<m;i++){
        int from, to, wt;
        cin >> from >> to >> wt;
        AdjList[from].push_back({to, wt});
        AdjList[to].push_back({from, wt});
    } */

    // Printing the Adjecency List
    for(int i=0;i<n;++i){
        cout << "AdjList of " << i << " : ";
        for(int node : AdjList[i]){
            cout << node << ", ";
        }
        cout << "\n";
    }
    return 0;
}