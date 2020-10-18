//Using Bit Manipulation
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};

Node *head;

void insert(int x){
    Node *temp = new Node();
    temp->val = x;
    temp->next = head;
    head = temp;
}

int getDecimalValue() {
        int num = 0;
        Node* curr_node = head;
        while( curr_node != NULL ) {
            num <<= 1;
            num |= curr_node->val;
            curr_node = curr_node->next;
        }
    return num;
}

void display(){
    Node *temp = head;
    cout<<"The List : ";
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int bits,value;
    cout<<"How Many Bits ?"<<endl;
    cin>>bits;
    cout<<"Enter The Binary Digit(1/0) :- "<<endl;
    for(int i=0;i<bits;i++){
        cout<<"Bit Location "<<i<<" : ";
        cin>>value;
        insert(value);
    }
    display();
    cout<<"The Decimal Value Is : "<<getDecimalValue();
    return 0;
}