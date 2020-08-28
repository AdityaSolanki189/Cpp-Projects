#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

void Insert(int data){
    Node* temp = new Node();
    temp->data = data; temp->next = NULL;
    if (head == NULL) head = temp;
    else {
    Node* temp1 = head;
    while (temp1->next != NULL) temp1 = temp1->next;
    temp1->next = temp;
    }
}
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
    Node* head = NULL;  //empty head node
    int n,x;
    cout<<"Enter No. Of Elements : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nEnter The Element : ";
        cin>>x;
        Insert(x);
    }
    cout<<"The Orginal List : "<<print();
    for(int i=0;i<n;i++){
        Reverse();
    }
    cout<<"The List After Reversing : "<<print();
    return 0;
}