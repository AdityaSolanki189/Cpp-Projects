//Without Using the STL library!
#include <iostream>
using namespace std;

class stack {

public:
    void create();
    void push();
    void pop();
    void top();
    void display();
};

void stack::create() {

}

void stack::push() {

}

void stack::pop() {

}

void stack::top() {

}

void stack::display() {

}
int main() {
    stack obj;
    cout << "\n~ STACK OPERATIONS ~\n\n1. Create a Stack\n2. Push a Value\n3. Pop a Value\n4. Display Stack Contents\n5. Display top\n6. Exit\n" << endl;
    int t = 1, ch;
    while (t) {
        cin >> ch;
        switch (ch) {
        case 1:
            obj.create();
            obj.display();
            break;
        case 2:
            obj.push();
            obj.display();
            break;
        case 3:
            obj.pop();
            obj.display();
            break;
        case 4:
            obj.display();
            obj.display();
            break;
        case 5:
            obj.top();
            break;
        case 6:
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