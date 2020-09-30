/*

				Name: Gourav Singh
				https://www.linkedin.com/in/gouravsingh2580/

*/

/*
				PROBLEM STATEMENT
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/


#include <bits/stdc++.h>

using namespace std;

int minCount(int n){
    //non Recursive solution

	std::vector<int> dp(n+1, 0);
	dp[0] = 0;
	dp[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
    	int count = INT_MAX;
    	for (int j = 1; j <= i; ++j)
    	{
    		if (i-j*j<0)
    		{
    			break;
    		}

    		count = min(count, dp[i-j*j]);
    	}
    	dp[i] = 1+count;	
    }

    return dp[n];
	
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	 int num;
    cin >> num;
    cout << minCount(num)<<endl;


	return 0 ; 



}
