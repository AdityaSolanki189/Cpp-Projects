#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
        //time taken to sort in ascending order is O(logN)
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for(int x: S)
        cout<< x <<" ";
    cout<<endl;
    //-10,-1,1,2

    auto it = S.find(-1);
    if(it == S.end())
        cout<<"not present \n";
    else{ 
        cout<<"Present \n";
        cout<< *it <<endl;}



    return 0;
}