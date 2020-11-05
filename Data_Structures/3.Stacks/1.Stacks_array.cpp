//Without Using the STL library!
#include <iostream>
using namespace std;

#define SIZE 10

class stack {
    int top;
    int stack_arr[SIZE];
public:
       
    void push();
    void pop();
    void peek();
    void display();
    stack() {
        top = -1;
    }
};

void stack::push() {
    int value;
    cout << "Enter Any Value : ";
    cin >> value;

    if (top >= SIZE - 1) {
        cout << "Stack OverFlow !!" << endl;
        return;
    }
    top++;
    stack_arr[top] = value;
}

void stack::pop() {
    if (top <= -1) {
        cout << "Stack UnderFlow !!" << endl;
        return;
    }
    cout << stack_arr[top] << " is Popped from the stack !" << endl;
    top--;
}

void stack::peek() {
    cout << "Element at the TOP : " << endl;
    cout << stack_arr[top];
}

void stack::display() {
    if (top >= 0) {
        cout << "Stack Elemensts are : " << endl;;
        for (int i = top; i >= 0; i--) {
            cout << "\t" << stack_arr[i] << endl;
            cout << "\t" << "---" << endl;
        }
    }
    else {
        cout << "Stack Is Empty !!" << endl;
        return;
    }
}

int main() {
    stack obj;
    int t = 1, ch;
    while (t) {
        cout << "\n~ STACK OPERATIONS ~\n\n1. Push a Value\n2. Pop a Value\n3. Display Stack Contents\n4. Display top\n5. Exit \n" << endl;
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