/* Maximum profit by buying and selling a share at most twice
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made. 

Examples: 

Input:   price[] = {10, 22, 5, 75, 65, 80}    12+70+15 = 97  (if there can be n=3 transactions)
Output:  87                                   12+75 = 87     (if there can only be 2 transactions)
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n){
    int *profit = new int[n];
    profit[n] = {0};
    
    int max_price = price[n-1];
    for(int i=n-2;i>=0;i--){
        if(price[i] > max_price)
            max_price = price[i];
        
        profit[i] = max(profit[i+1], max_price - price[i]);
    }

    int min_price = price[0];
    for(int i=1;i<n;i++){
        if(price[i] < min_price)
            min_price = price[i];
        
        profit[i] = max(profit[i-1], profit[i] + (price[i]-min_price));
    }

    int result = profit[n-1];

    delete[] profit;

    return result;
}

int main(){
    int n;
    cin >> n;
    int price[n];
    for(int i=0;i<n;i++) cin >> price[i];

    cout << maxProfit(price, n) << "\n";

    return 0;
}

