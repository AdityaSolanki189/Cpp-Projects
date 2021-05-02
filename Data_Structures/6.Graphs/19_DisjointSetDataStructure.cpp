// To tell if any Two Random Nodes belong to the Same or a Different Component. 
/* By Using Union By Rank and Path Compression, To perform a UNION on two sets, we merge the two trees by making the root of one tree point to
the root of the other.

 */
// Time Complexity : approx. O(4) Constant Time

#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    int N;
    public:
    int parent[100000];
    int rank[100000];

    DisjointSet(int N){
        this->N = N;
    }
    void makeSet();
    int findParent(int);
    void Union(int, int);
};

void DisjointSet :: makeSet(){
    for(int i=1;i<=N;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int DisjointSet :: findParent(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findParent(parent[node]); // Path Compression 
}

void DisjointSet :: Union(int u, int v){
    u = findParent(u);
    v = findParent(v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int N;
    cout << "Enter Total Nodes : ";
    cin >> N;
    DisjointSet ds(N);

    while(N--){
        int u, v;
        cin >> u >> v;
        ds.Union(u, v);
    }

    // To check if 2 and 3 belong to the same component or not
    if(ds.findParent(2) != ds.findParent(3)){
        cout << "Different Components\n";
    }
    else{
        cout << "Same Component\n";
    }

    return 0;
}