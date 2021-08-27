// Find the Largest Sum Contiguous Sub-Array [V.imp]
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
// Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];

    int max_sum = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += array[i];
        max_sum = max(max_sum,sum);
        if(sum < 0){
            sum = 0;
        }
    }
    cout << "The Largest Sum of Contiguous Sub-Array is : " << max_sum << "\n"; 

    return 0;
}