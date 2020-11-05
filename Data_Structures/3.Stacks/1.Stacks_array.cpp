//Without Using the STL library!
#include <iostream>
using namespace std;

#define SIZE 10

class stack {
    int top;
    
    public:
    int stack_arr[SIZE];
    void create();
    void push();
    void pop();
    void top();
    void display();
    stack(){
        top = -1;;
    }
};

void stack::push() {
    int value;
    cout<<"Enter Any Value : ";
    cin>>value;

    if(top >= n-1){
        cout<<"Stack OverFlow !!"<<endl;
        return;
    }
    top++;
    stack_arr[top] = value;
}

void stack::pop() {
    if(top <= -1){
        cout<<"Stack UnderFlow !!"<<endl;
        return;
    }
    cout<< stack_arr[top] <<" is Popped from the stack !"<<endl;
    top--;
}

void stack::top() {
    cout<<"Element at the TOP : "<<endl;
    cout<< stack_arr[top];
}

void stack::display() {
    if(top >= 0){
        cout<<"Stack Elemensts are : "<<endl;;
        for(int i = top; i >= 0; i--){
            cout<<"\t"<<stack_arr[i]<<endl;
        }
    }
    else{
        cout<<"Stack Is Empty !!"<<endl;
        return;
    }
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