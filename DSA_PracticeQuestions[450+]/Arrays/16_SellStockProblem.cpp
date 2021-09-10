/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell. */

#include<bits/stdc++.h>
using namespace std;
 
void calculate_maxProfit(vector<int>& prices){
    int min_price=INT_MAX;
    int max_profit=0;
    for(int i=0;i<prices.size();i++){
        min_price = min(min_price, prices[i]);
        max_profit = max(prices[i]-min_price, max_profit);
    }
    cout << "The Max Profit Made : " << max_profit;
}

int main(){
    int days;
    cin >> days;
    vector<int> prices;
    int val;
    for(int i=0;i<days;i++){
        cin >> val;
        prices.push_back(val);
    }

    calculate_maxProfit(prices);

    return 0;
}