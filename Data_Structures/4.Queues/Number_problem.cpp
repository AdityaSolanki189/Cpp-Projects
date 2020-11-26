/* Given a number n, print first n number(in increasing order) such that all these numbers have digits in set {5, 6} */
#include <iostream> 
#include <queue>
using namespace std; 

void printFirstN(int n) { 
    queue<string> q;
    
    q.push("5");
    q.push("6");
    
    for(int i = 0; i < n; i++) {
        string curr = q.front();
       
        cout << curr << " ";
        
        q.pop();
        
        q.push(curr + "5");
        q.push(curr + "6");
    }
    cout<<"\n";
} 

int main(){
    
    int n;
    cout<<"\nEnter Any Number : ";
    cin>>n;
    printFirstN(n);

    return 0;
}
