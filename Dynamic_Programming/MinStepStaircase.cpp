//One Dimentional DP
//Find the number of ways to reach the step 'num'.
/* 
    1. Recursion
    2. Repetitive Calls
    3. Memoize the code
    4. Recursive Call
    5. Solve
*/
#include <iostream>
using namespace std;

int staircase(int n){
    if(n== 0|| n==1){
        return 1;
    }
    if(n== 2){
        return 2;
    }

    int x = staircase(n-1);
    int y = staircase(n-2);
    int z = staircase(n-3);

    return x+y+z;
}

int staircase_mem(int n,int arr[]){ //memoization
    if(n== 0|| n==1){
        return 1;
    }
    if(n== 2){
        return 2;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int x = staircase_mem(n-1, arr);
    int y = staircase_mem(n-2, arr);
    int z = staircase_mem(n-3, arr);

    int ans x+y+z;
    arr[n] = ans;
    return arr[n];
}

int main(){
    int num;
    cin>>num;
    int arr[num+1];
    for(int i=0;i<num+1;i++){
        arr[i]= -1;
    }
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=num;i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    cout<<arr[num];
    

    return 0;
}