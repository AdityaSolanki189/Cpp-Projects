#include <bits/stdc++.h>
using namespace std;

void solve(){
    string Code; // Actual No (Also Largest No in W- 1digit)
    cin >> Code;

    int len = Code.length();

    if(len <= 3) {
        cout << "Error\n";
        return;
    }



    if(int(Code[0]) == 60 && int(Code[1]) == 47 && int(Code[len-1]) == 62){
        for(int i=2;i<len-1;i++){
            if(!((Code[i] >= 'a' && Code[i] <= 'z' ) || (Code[i] >= '0' && Code[i] <= '9'))){
                cout << "Error\n";
                return;
            }
            else{
                continue;
            }
        }
    }
    else{    
        cout << "Error\n";
        return;
    }
    cout << "Success\n";
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