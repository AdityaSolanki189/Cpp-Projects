#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
    int n, curr;
    cin >> n;
    int heights[n], res[n];
    for(int i=0;i<n;i++){
        cin >> heights[i];
    }
    for(int i=0;i<n;i++){
        int counter = 0;
        if (i == 0){
            curr = i;
            for (int j = i + 1; j < n; j++){
                if (heights[j] == heights[i])
                    counter++;
                else if (heights[j] < heights[i])
                    continue;
                else
                    break;
            }
        }
        if (i == n - 1){
            curr = i;
            for (int j = i - 1; j >= 0; j--){
                if (heights[j] == heights[i])
                    counter++;
                else if (heights[j] < heights[i])
                    continue;
                else
                    break;
            }
        }
        else{
            for (int j = i + 1; j < n; j++){
                if (heights[j] == heights[i])
                    counter++;
                else if (heights[j] < heights[i])
                    continue;
                else
                    break;
            }
            for (int j = i - 1; j >= 0; j--){
                if (heights[j] == heights[i])
                    counter++;
                else if (heights[j] < heights[i])
                    continue;
                else
                    break;
            }
        }
        res[i] = counter;
    }
    for(int i=0;i<n;i++){
        cout << res[i] << " ";
    }
    cout<<endl;
}    

int main(){
    fastio();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}