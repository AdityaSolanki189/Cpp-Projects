/* Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N' 
using the sum of the given three numbers.
(allowing repetitions and different arrangements).

Total number of ways to form 6 is: 8
1+1+1+1+1+1
1+1+1+3
1+1+3+1
1+3+1+1
3+1+1+1
3+3
1+5
5+1
*/
/* 
Solution : 
1) Adding 1 to all possible combinations of state (n = 6) 
Eg : [ (1+1+1+1+1+1) + 1] 
[ (1+1+1+3) + 1] 
[ (1+1+3+1) + 1] 
[ (1+3+1+1) + 1] 
[ (3+1+1+1) + 1] 
[ (3+3) + 1] 
[ (1+5) + 1] 
[ (5+1) + 1] 

2) Adding 3 to all possible combinations of state (n = 4);
Eg : [(1+1+1+1) + 3] 
[(1+3) + 3] 
[(3+1) + 3] 

3) Adding 5 to all possible combinations of state(n = 2) 
Eg : [ (1+1) + 5]

Now, think carefully and satisfy yourself that the above three cases are covering all possible ways to form a sum total of 7;
Therefore, we can say that result for 
state(7) = state (6) + state (4) + state (2) 
or 
state(7) = state (7-1) + state (7-3) + state (7-5)
In general, 
state(n) = state(n-1) + state(n-3) + state(n-5) */

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int dp[MAX];
 
// this function returns the number of 
// arrangements to form 'n' 
int solve(int n){ 
  // base case
  if (n < 0)  
      return 0;
  if (n == 0)
      return 1;
  // checking if already calculated
  if (dp[n] != -1) 
      return dp[n];
  // storing the result and returning
  return dp[n] = solve(n-1) + solve(n-3) + solve(n-5);
}

int main(){
    for(int i=0;i<MAX;i++) dp[i] = -1; 
    int n;
    cin >> n;
    if(n < MAX)
        cout << solve(n) << "\n";
    else    
        cout << "Invalid Input" << "\n";
    return 0;
}