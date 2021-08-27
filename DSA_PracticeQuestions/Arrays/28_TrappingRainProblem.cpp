/* Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units. */

#include<bits/stdc++.h>
using namespace std;

class Solution{
    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int sum=0, l,r,lmax=0, rmax=0;
        l=0;
        r=n-1;
        while(l<r){
            if(lmax<rmax){
                if(lmax<arr[l]) lmax = arr[l];
                else{
                    sum += lmax -  arr[l];
                    l++;
                }
            }
            else{
                if(rmax<arr[r]) rmax = arr[r];
                else{
                    sum += rmax - arr[r]; 
                    r--;
                }
            }
        }
        return sum;
    }
};

int main(){
    //testcases
    int t;
    cin >> t;
    
    while(t--){
        int n;    
        //size of array
        cin >> n;
        int a[n];
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }
    return 0;
} 