#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    // N -> Vertices
    // M -> Edges
    vector<vector<int>> adjMat(n, vector<int>(n, 0));
    // adjMat Object for storing N*N Adecency Matrix
    // Accepting Directed edges (ex. 0 -> 1) 
    for(int i=0;i<m;++i){
        int from, to;
        cin >> from >> to;
        adjMat[from][to] = 1;
    }

    // Accepting Undirected Graphs
    for(int i=0;i<m;++i){
        int from, to;
        cin >> from >> to;
        adjMat[from][to] = 1;
        adjMat[to][from] = 1;
    }

    // Accepting Undirected Weighted Graphs
    for(int i=0;i<m;++i){
        int from, to, wt;
        cin >> from >> to >> wt;
        adjMat[from][to] = wt;
        adjMat[to][from] = wt;
    }

    // Printing the Adjecency Matrix
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout << adjMat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Time Complexity : O(V^2)