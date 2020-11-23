//Queue DS Without Using the STL library!
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

class Queue_SLL {
public:
       
    void push();
    void pop();
    void peek();
    void display();
    Queue_SLL() {
        head = NULL;
    }
};

void Queue_SLL::push() {   //insert at end 
    Node *newNode = new Node();
    cout << "Enter Any Value : ";
    cin >> newNode->data;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Queue_SLL::pop() {    //Delete from front
    if(head == NULL){
        cout<<"Queue Is Empty"<<endl;
        return;
    }
    else{
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
}

void Queue_SLL::peek() {     //print first element
    if(head == NULL){
        cout<<"Queue Is Empty"<<endl;
        return;
    }
    cout << "\nElement at the Front : ";
    Node *temp = head;
    cout << temp->data << endl;;
}

void Queue_SLL::display() {
    Node *temp;
    if(head == NULL){
        cout<<"The Queue Is Empty!"<<endl;
        return;
    }
    temp = head;
    cout<<"\n| ";
    while(temp != NULL){
        
        cout<<temp->data<<" | ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main() {
    Queue_SLL obj;
    int t = 1, ch;
    while (t) {
        cout << "\n~ Queue OPERATIONS ~\n\n1. Push a Value\n2. Pop a Value\n3. Display Stack Contents\n4. Display top\n5. Exit " << endl;
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