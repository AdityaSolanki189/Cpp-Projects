#include <iostream>
using namespace std;
#define MAX 20

/* 
    Time Complexity : 
    Best - O(1), when flag is used
    Avg. - θ(n)
    Worst - O(n) 
    Worst case space complexity : O(1) auxiliary
*/

void Linear_Search1(int arr[], int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i] == k){
            cout<<"Key Found at "<<i<<endl;
            return;
        }
    }
    cout<<"Key Not Found.\n";
}


void Linear_Search2(int arr[], int n, int k){
    int left = 0;
    int position = -1;
    int right = n - 1;
       
    for(left = 0; left <= right;){
        if (arr[left] == k){    
            position = left;
            cout << "Key Found at "<<position<<endl;
            return;
        }
        if (arr[right] == k){
            position = right;
            cout << "Key Found at "<<position<<endl;
            return;
        }
        left++;
        right--;
    }

    if (position == -1) cout << "Key Not Found.\n";
}


int main(){
    int n,k;
    cout<<"\nEnter the Number of Elements : ";
    cin>>n;
    if(n>MAX) exit(0);
    int arr[MAX];
    cout<<"\nEnter Elements in the Array : \n";
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"\nEnter the Key : ";
    cin>>k;

    Linear_Search1(arr, n, k);  // Worst Case: O(n)

    Linear_Search2(arr, n, k); // Worst Case: O(n/2)

    return 0;
}
