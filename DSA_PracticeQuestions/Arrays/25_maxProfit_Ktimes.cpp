/* Maximum profit by buying and selling a share at most K Times/Transactions
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made. */

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int a[], int n, int k){
    if(k >= n/2){
        int maxp = 0, i;
        for(i=1;i<n;i++){
            if(a[i] > a[i-1])
                maxp += a[i] - a[i-1];
        }
        return maxp;
    }

    int mx[k+1] = {0}; // set all min
    int lp[k+1];       // set all max

    for(int i=0;i<=k;i++){
        lp[i] = 32000;
    }

    for(int i=0;i<n;i++){
        for(int j=k;j>=1;j--){
            mx[j] = max(mx[j], a[i]-lp[j]);
            lp[j] = min(lp[j], a[i]-mx[j-1]);
        }
    }
    return mx[k];
}

int main(){
    int n, k;
    cin >> n >> k;
    int price[n];
    for(int i=0;i<n;i++) cin >> price[i];

    cout << maxProfit(price, n, k) << "\n";
    return 0;
}