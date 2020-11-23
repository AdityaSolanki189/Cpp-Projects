//STACKS Without Using the STL library!
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

class stack_sll {
public:
       
    void push();
    void pop();
    void peek();
    void display();
    stack_sll() {
        head = NULL;
    }
};

void stack_sll::push() {   //insert at end node
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

void stack_sll::pop() {      //delete from end node
    if(head == NULL){
        cout<<"Stack Is Empty"<<endl;
        return;
    }
    
    Node* Last_node = head;
    Node* secondLast_node = head;
    while(Last_node->next != NULL){
        secondLast_node = Last_node;
        Last_node = Last_node->next;
    } 

    if(secondLast_node == head)
        head = NULL;        
    else
        secondLast_node->next = NULL;
    
    delete Last_node;
}

void stack_sll::peek() {       //print last node
    if(head == NULL){
        cout<<"The Stack Is Empty!"<<endl;
        return;
    }
    cout << "Element at the TOP : ";
    Node *temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void stack_sll::display() {
    
    Node *temp;
    if(head == NULL){
        cout<<"The Stack Is Empty!"<<endl;
        return;
    }

    //reversing the LIST
    
    Node* current = head; 
    Node *prev = NULL, *next = NULL; 
  
    while (current != NULL) { 
            // Store next 
        next = current->next; 
            // Reverse current node's pointer 
        current->next = prev; 
            // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    head = prev;

    //printing the reversed LIST

    temp = head;
    while(temp != NULL){
        cout<<"\t"<<temp->data<<endl;
        cout<<"\t"<<"---"<<endl;
        temp = temp->next;
    }

    //reversing back to the original LIST

    current = head; 
    prev = NULL;
    next = NULL; 
  
    while (current != NULL) { 
            // Store next 
        next = current->next; 
            // Reverse current node's pointer 
        current->next = prev; 
            // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    head = prev;

}

int main() {
    stack_sll obj;
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