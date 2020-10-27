#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head;

class CLL{
    public: 
    void create();
    void insert();
    void delete();
    void display();
    CLL(){
        head = NULL;
    }
}

void CLL :: create(){
    Node *newNode = new Node();
    cout<<"Enter Data : ";
    cin>>newNode->data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        Node *temp = head;
        while(temp->next != head){
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
    }
}

void CLL :: insert(){
    Node *newNode = new Node();
    cout<<"Enter Data : ";
    cin>>newNode->data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

void CLL :: display(){
    if(head == NULL){
        cout<<"Empty List\n";
        return;
    }
    Node *temp = head;
    cout<<"The CLL : ";
    while(temp->next != head){
        cout<<temp->data<<" --> ";
    }
}

int main(){
    
}