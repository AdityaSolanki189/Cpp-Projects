#include <iostream>
#include <queue>
using namespace std;

int main(){
    cout << "\n";
    // Normal Queue (FIFO)
    queue<int> Q;

    // Max. Priority Queue 
    priority_queue<int> max_PQ;

    // Min. Priority Queue
    priority_queue<int, vector<int>, greater<int>> min_PQ;

    int input;
    while(input){
        cout << "Enter A Value (0 to quit) : ";
        cin >> input;
        if(input){
            Q.push(input);

            max_PQ.push(input);

            min_PQ.push(input);
        }
    }
    cout << "\nNormal Queue : ";
    while(!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }

    cout << "\nMax Priority Queue : ";
    while(!max_PQ.empty()){
        cout << max_PQ.top() << " ";
        max_PQ.pop();
    }

    cout << "\nMin Priority Queue : ";
    while(!min_PQ.empty()){
        cout << min_PQ.top() << " ";
        min_PQ.pop();
    }

    return 0;
}