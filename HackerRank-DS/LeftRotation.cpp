#include <iostream>

using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    int new_arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){

        int j = (i + n - d) % n;   
        // d left rotations equal (n-d) right rotations
        // mod to get the correct index when assigning
        new_arr[j] = arr[i];
    }
    for(int i=0;i<n;i++) cout<<new_arr[i]<<" ";
    return 0;
}