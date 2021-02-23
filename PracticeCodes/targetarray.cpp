#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int nums[n], index[n];
    int target[n]={0};
    //nums array
    for(int i=0;i<n;i++) {
        //initialize empty target array with -1
        target[i] = -1;
        cin>>nums[i];
    }
    //index array
    for(int i=0;i<n;i++){
        cin>>index[i];
    }

    int i=0;
    while( i < n ){
        int idx = index[i];
        if(target[idx] == -1){
            //place at index idx
            target[idx] = nums[i];
        }    
        else{
            //idx already taken
            //shift the elements
            for(int j = n-1; j > idx; j--){
                target[j] = target[j-1];
            }
            //place 
            target[idx] = nums[i];
        }
        i++;
    }
    //print target array
    for(int i=0;i<n;i++){
        cout<<target[i];
    }
    return 0;
}