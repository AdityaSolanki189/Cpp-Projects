#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

void Reverse(){
    Node *current, *prev, *next;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void print(){
    Node* temp = head;
    cout<<"The List : "<<endl;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    head= NULL;
}