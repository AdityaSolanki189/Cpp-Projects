//Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){

    int max_sum = INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        max_sum = max(max_sum,sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return max_sum;
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];

    cout << "The Largest Sum of Contiguous Sub-Array is : " << max_sum(array,n) << "\n"; 

    return 0;
}