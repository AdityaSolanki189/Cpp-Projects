#include <bits/stdc++.h>
using namespace std;
#define li long long int 

int main(){
    li t;
    cin >> t;
    while(t--){
        li n;
        cin >> n;
        li arr[n];
        for(li i=0;i<n;i++) cin >> arr[i];
        sort(arr, arr + n);
        li ans=0,cnt=0;
        for(li i=0;i<n;i++){
            if(i+1-arr[i] < 0){
                cnt = 1;
                break;
            }
            ans = ans +(i+1- arr[i]);
        }
        if(cnt == 1) cout << "Second" << "\n";
        else{
            if(ans%2 == 1)
                cout << "First" << "\n";
            else 
                cout << "Second" << "\n";
        }
    }
    return 0;
}