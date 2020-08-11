#include <iostream>

using namespace std;

struct node{
    int data;
    node *link;
};

node* head;

void append(int n){
    head = NULL;
    node* temp = new node();
    temp->data = n;
    temp->link = NULL;
    head = temp;
}

void display(){
    node *temp1 = head;
    while (temp1 != NULL) { 
        cout << temp1->data << " "; 
        temp1 = temp1->link; 
    } 
}

int main(){
    int n;
    cout<<"Enter any Integer : ";
    cin>>n;
    append(n);
    display();
    return 0;
}