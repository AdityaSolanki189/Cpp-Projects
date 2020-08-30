#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
 
Node* head;  //global variable

void Insert(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print(){
    Node* temp = head;
    cout<<"List is : "<<endl;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<" ";
}

int main(){ 
    head = NULL;  //empty list
    int n,x;
    cout<<"Enter No. Of Elements : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nEnter The Element : "<<endl;
        cin>>x;
        Insert(x);
        Print();
    }
    return 0;
}