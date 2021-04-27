#include <bits/stdc++.h>
using namespace std;

// vector<int> AdjList[100]; // 100 nodes

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
    for(int i=0;i<n;++i){
        cout << "AdjList of " << i << " : ";
        for(int node : AdjList[i]){
            cout << node << ", ";
        }
        cout << "\n";
    }
    return 0;
}