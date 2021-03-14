/* Given an array of size N and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Example 1:
Input: 
N = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1. */
// flag based quick sort

#include<bits/stdc++.h>
using namespace std;

// O(n) Time Complexity
void partition(vector<int> v, int a, int b){
    int start=0, end=v.size()-1;
    int i=0;
    while(i<=end){
        if(v[i] < a){
            swap(v[i++], v[start++]);
        }
        else if(v[i] > b){
            swap(v[i], v[end--]);
        }
        else i++;
    }
}

int main(){
    int n, x, a, b;
    cin >> n >> a >> b;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> x;
        v.push_back(x);
    }
    
    partition(v, a, b);

    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}