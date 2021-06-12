#include <bits/stdc++.h>
using namespace std;

int main(){
   int nodes;
    cout << "\nEnter No of Nodes : ";
    cin >> nodes;

    int Edges, from , to;
    cout << "\nEnter total Edges : ";
    cin >> Edges;

    // 2-D Array/Matix initialized with 0
    vector<vector<int>> matrix(nodes+1, vector<int> (nodes+1, 0));

    // Undirected Graph
    while(Edges--){
        int from, to;
        cout << "\nEnter from and to : ";
        cin >> from >> to;
        matrix[from][to] = 1;
        matrix[to][from] = 1;
    }
    // We can do for Directed and Weighted the same way

    // depends on the indexing of the graph
    cout << "\nAdjacency Matrix : \n";
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout << "\t" << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Time Complexity : O(V^2)