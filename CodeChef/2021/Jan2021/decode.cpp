#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string get_alpha(string binary){
    ll num = stoi(binary);
    ll dec_value = 0;
    ll base = 1;
 
    ll temp = num;
    while (temp) {
        ll last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    
    string arr[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"};

    return arr[dec_value];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
	    
        ll n;
        cin>>n;
        string code;
        cin>>code;
        string str="",final="";
        for(ll i=0;i<n;i+=4){
            str="";
            str = str + code[i] + code[i+1] + code[i+2] + code[i+3];
            final = final + get_alpha(str);
        }

	    cout<<final<<"\n";
	}
	return 0;
}
