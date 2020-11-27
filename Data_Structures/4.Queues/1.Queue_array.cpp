//Without Using the STL library!
#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int top;
    int queue_arr[SIZE];
public:
       
    void enqueue();
    void dequeue();
    void peek();
    void display();
    Queue() {
        top = -1;
    }
};

void Queue::enqueue() {
    int value;
    cout << "Enter Any Value : ";
    cin >> value;

    if (top >= SIZE - 1) {
        cout << "Queue OverFlow !!" << endl;
        return;
    }
    top++;
    queue_arr[top] = value;
}

void Queue::dequeue() {
    int front =queue_arr[0];
    if (top <= -1) {
        cout << "Queue UnderFlow !!" << endl;
        return;
    }
    cout << queue_arr[0] << " is Popped from the queue !" << endl;
    for(int i=0;i<queue_arr.size()-1;i++){
        queue_arr[i] = queue_arr[i+1];
    }
    top--;
}

void Queue::peek() {
    cout << "Element at the TOP : ";
    cout << queue_arr[top];
}

void Queue::display() {
    if (top >= 0) {
        cout << "Queue Elemensts are : " << endl;;
        for (int i = top; i >= 0; i--) {
            cout << "\t" << queue_arr[i] << endl;
            cout << "\t" << "---" << endl;
        }
    }
    else {
        cout << "Queue Is Empty !!" << endl;
        return;
    }
}

int main() {
    Queue obj;
    int t = 1, ch;
    while (t) {
        cout << "\n~ QUEUE OPERATIONS ~\n\n1. Push a Value\n2. Pop a Value\n3. Display Stack Contents\n4. Display top\n5. Exit \n" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            obj.push();
            obj.display();
            break;
        case 2:
            obj.pop();
            obj.display();
            break;
        case 3:
            obj.display();
            obj.display();
            break;
        case 4:
            obj.peek();
            break;
        case 5:
            cout << "Exit(0)!";
            t = 0;
            break;
        default:
            cout << "Invalid Input !" << endl;
            break;
        }
    }
    return 0;
}