#include <bits/stdc++.h> 
using namespace std; 
  
void printPairs(int arr[], int n) 
{   
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            cout << "(" << arr[i] << ", " << arr[j] << ")" << ", "; 
        } 
    } 
} 
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printPairs(arr, n); 
  
    return 0; 
} 