#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--){
        int N;
        cin>>N;
        int fuel[N];
        for(int i=0;i<N;i++)cin>>fuel[i];
        int cost[N];
        for(int i=0;i<N;i++)cin>>cost[i];

        for(int i=0;i<N;i++){
            int index = 0;
            index = i;
            int gas = fuel[0];
            // forward j stations
            while(gas)
            for (int j = i+1; j <= N; j++) {
                int k = (i + j - 1) % N;
                gas_left += gas[k] - cost[k];
                if (gas_left < 0)
                    break;
            }
        }

        /* for (int i = 0; i < n; i += j) {
            int gas_left = 0;
            // forward j stations
            for (int j = 1; j <= n; j++) {
                int k = (i + j - 1) % n;
                gas_left += gas[k] - cost[k];
                if (gas_left < 0)
                    break;
            }
            if (j > n)
                return i;
        } */

        return -1;

    }
    return 0;
}