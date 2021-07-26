#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >>N;
    string s;
    int c;
    unordered_map<string,int> Codes;

    for(int i=0;i<N*3;i++){
        cin >> s >>c;
        if(Codes.find(s) != Codes.end()){
            Codes[s] += c;
        }
        else{
            Codes.insert(make_pair(s,c));
        }
    }
    vector<int> order;
    for(auto it :Codes){
        order.push_back(it.second);
    }

    sort(order.begin(), order.end());

    for(int i=0;i<order.size();i++){
        cout << order[i] << " ";
    }

    cout << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}