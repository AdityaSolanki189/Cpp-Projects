// Time Complexity of finding nth fibonacci number using recursion is O(2^n)
// So, Finding 50th fibonacci number will take 2^50 ie. more than 10^18 steps which very time consuming
// We need to find a way where we can save time by not repeating the known numbers, Using Memoization.
// Thus, by using Dynamic Programming.
// We get, Time Complexity : O(n) linear
// And, Space Complexity : O(n) Linear
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Normal recursion method
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

// TopDownDp = Recusrion + Memoization
ll topdownDP(ll n, ll dp[])
{
    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return n;
    }

    // Memoization
    if (dp[n] != -1)
    { //ie. if already computed
        return dp[n];
    }
    else
    {
        // Compute and store it, then return
        dp[n] = topdownDP(n - 1, dp) + topdownDP(n - 2, dp);
        return dp[n];
    }
}

ll bottomUP(ll n)
{
    int *dp = new int[n];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    //cout << fib(n) << "\n";

    ll dp[100];
    for (ll i = 0; i < 100; i++)
        dp[i] = -1;
    cout << topdownDP(n, dp) << "\n";

    cout << bottomUP(n) << "\n";

    return 0;
}

/*  Space Optimized Method :

    int fibonacciNumber(int n){
    int i, fibonacciFirst = 0, fibonacciSecond = 1, fibonacciResult;
    if(n == 0)
        return fibonacciFirst;
    else if(n == 1)
        return fibonacciSecond;
    else
        for(i=0; i<n; i++){
            fibonacciResult = fibonacciFirst + fibonacciSecond;
            fibonacciFirst = fibonacciSecond;
            fibonacciSecond = fibonacciResult;
        } 
    return fibonacciResult;
} */