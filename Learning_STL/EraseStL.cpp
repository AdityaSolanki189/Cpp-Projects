#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N,x;
    cin>>N;
    vector<int>numbers;
    for(int i=0;i<N;i++){
        cin>>x;
        numbers.push_back(x);
    }
    int first,start,end;
    cin>>first>>start>>end;
    numbers.erase(numbers.begin()+(first-1));
    numbers.erase(numbers.begin()+(start-1),numbers.begin()+(end-1));
    cout<<numbers.size()<<endl;
    for(int i=0;i<numbers.size();i++){
        cout<<numbers.at(i)<<" ";
    }
    return 0;
}
