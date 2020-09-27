#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(int x,int y){
    return x>y;
}

int main(){

        //C++ Standard Template Library

    vector<int> A = {11,2,3,14};

    cout<< A[1]<<endl;   //2

    sort(A.begin() , A.end()); // O(NlogN) - Ascending Order Sort
    //2,3,11,14

    bool present = binary_search(A.begin(), A.end(), 3); //true
    present = binary_search(A.begin(), A.end(), 4); //false

    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100); // true
    //2,3,11,14,100

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    //2,3,11,14,100,100,100,100,100,123

    auto it = lower_bound(A.begin(), A.end(), 100); // >=
    auto it2 = upper_bound(A.begin(),A.end(), 100); // >
    
    cout<< *it << " " << *it2 << endl; //100 123
    cout<< it2- it<< endl; //5

    sort(A.begin(),A.end(), f);

    for(int x: A){ //Without Reference
        cout<< x <<" ";
    }
    cout<<endl;  
    for(int &x: A){ //With Reference
        x++;
        cout<< x <<" ";
    }
    cout<<endl;
    
    return 0;
}