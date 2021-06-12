// Krushkals Algorithm using Disjoint Set Data Structure, first we Sort the adjecent nodes according to thier weight in Ascending order(Greedy Approach). Then we traverse the sorted list and check if the nodes are of the same component or not(Disjoint set approach), continue till we have visited all the nodes or till we have found our Minimum Spanning Tree.

// Time Complexity : O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int u, v, wt;
    node(int from, int to, int weight){
        u = from;
        v = to;
        wt = weight;
    }
};

bool compare(node a, node b){  // Sort according to weight in Ascending Order
    return a.wt < b.wt;
}

int findParent(int node, vector<int> &parent){
    if(node == parent[node]){
        return node;
    }
    return findParent(parent[node], parent); // Path Compression to Reduce Time Compl.
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
        rank[v] += rank[u];
    }
    else{
        parent[v] = u;
        rank[u] += rank[v];
    }
}

int main(){
    int N, M;
    cout << "\nEnter Total Nodes : ";
    cin >> N;
    cout << "\nEnter Total Edges : ";
    cin >> M;
    
    vector<node> EdgeList;
    for(int i=0; i<M; i++){
        int u, v, wt;
        cout << "Enter From, To and Weight of Edge : ";
        cin >> u >> v >> wt;
        EdgeList.push_back(node(u, v, wt));
    }

    sort(EdgeList.begin(), EdgeList.end(), compare);

    vector<int> parent(N);
    for(int i=0; i<N; i++){
        parent[i] = i;
    }
    vector<int> rank(N, 0);
    
    int cost = 0;
    vector<pair<int, int>> MST;
    for(auto it: EdgeList){
        if(findParent(it.v, parent) != findParent(it.u, parent)){
            cost += it.wt;
            MST.push_back({it.u, it.v});
            Union(it.u, it.v, parent, rank);
        }
    }
    
    cout << "\nMinimum Spanning Tree : \n" ;

    for(auto it: MST){
        cout << it.first << " - " << it.second << "\n";
    }

    cout << "Total Cost : " << cost <<"\n";

    return 0;
}