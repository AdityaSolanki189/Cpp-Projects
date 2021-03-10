/* Given an array arr of size N and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Example 1:

Input:
N = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13. */

#include<bits/stdc++.h>
using namespace std;
//2 pointer approach + sorting (nlogn)
int isSum_triplet(int array[], int n, int sum){
    int i;
    sort(array, array+n);
    int j,k,flag=0;
    for(int i=0;i<n;i++){
        j = i+1;
        k = n-1;
        while(j < k){
            if(array[i]+array[j]+array[k] == sum){
                flag = 1;
                break;
            }
            else if(array[i]+array[j]+array[k] < sum){
                j++;
            }
            else{
                k--;
            }
        }
        if(flag)
            break;
    }
    if(flag) return 1;
    else     return 0;
}

int main(){
    
    int n, sum;
    cin >> n >> sum;
    int array[n];

    for(int i=0;i<n;i++) cin >> array[i];

    cout << isSum_triplet(array, n, sum);

    return 0;
}