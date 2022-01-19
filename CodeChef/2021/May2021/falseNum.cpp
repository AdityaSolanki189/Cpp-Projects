#include <bits/stdc++.h>
using namespace std;

void solve(){
    string A; 
    cin >> A;
    string b;
    int len = A.length();

    if(A[0] =='1'){
        b = "'10'" + A.substr(1,len-1);
        cout << b << "\n";
        return;
    }
    else{
        b =  "1" + A;
        cout << b << "\n";
        return;
    }

    /* vector<int> arr;
    cout << A[0];
    for(int i=0;i<len;i++){
        cout << A[i] << "\n";
        arr.push_back(A[i]);
    }

    if(arr[0] >= 2 && arr[0] <= 9){
        arr.insert(arr.begin(),1);
    }
    else{
        arr.insert(arr.begin()+1,0);
    }
    
    for(auto i=arr.begin();i!=arr.end();i++){
        cout << *i;
    }
    cout << "\n"; */
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