#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*  Given Info : 
    N Students
    Items :  Omlet   Chocolate_milkshake    Choco_Cake
    Price :  A       B                       C
    Canteen has E Eggs and H Chocolate_Bars
    OMLET - requires 2 Eggs
    Chocolate_Milkshake - requires 3 Chocolate_Bars
    Chocolate_CAKE - requires 1 Egg and 1 Chocolate_Bar
*/

/* int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, eggs, bars, omlet_price, shake_price, cake_price;
        cin >> n >> eggs >> bars >> omlet_price >> shake_price >> cake_price;
        int min_price = INT_MAX;
        
        if(2*n <= eggs)
            min_price = min(omlet_price*n,min_price);
        
        else if(3*n <= bars)
            min_price = min(shake_price*n, min_price);

        else if(n <= eggs && n <= bars)
            min_price = min(cake_price*n, min_price);        

        else min_price = -1;

        cout << min_price << "\n";
    }
    return 0;
} */

void give_output(vector<ll> v){
    if(v.size() == 0)
        cout << "-1" << "\n";
    else{
        sort(v.begin(),v.end());
        cout << v[0] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--){
        ll n, eggs, bars, omlet_price, shake_price, cake_price;
        cin >> n >> eggs >> bars >> omlet_price >> shake_price >> cake_price;
        
        vector<ll> v;
        vector<ll> lv;

        for(int i=0;i<=n+1;i++){
            lv.push_back(i);
        }
        
        for(ll x =0;x <= n; x++){
            ll lb = lower_bound(lv.begin(), lv.end(), (2*n-eggs-2*x))-lv.begin();
            ll ub = upper_bound(lv.begin(), lv.end(), (bars-3*x))-lv.begin()-1;

            if(ub < lb || lb == n+1) continue;
            if(ub == n+1 && ub+3*x > bars) continue;

            ll k;
            if(cake_price > omlet_price)
                k = min(lb, (n-x)); 
            else
                k = min(ub, (n-x)); 
            
            ll og = n - k - x;
            if(k+2*x >= 2*n-eggs && k+3*x <= bars){
                v.push_back(omlet_price*og + shake_price*x + cake_price*k);
            }
        }
                
        give_output(v);
        
    }
    return 0;
}
