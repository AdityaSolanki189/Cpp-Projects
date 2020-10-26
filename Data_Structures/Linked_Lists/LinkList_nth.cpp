#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

void Insert(int data,int n){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n==1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i=0;i<n-2;i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print(){
    Node* temp = head;
    cout<<"The List : "<<endl;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    head = NULL;
    int loc,num,x;
    cout<<"Enter No Of Elements : "<<endl;
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"Enter Element and Its Loaction : "<<endl;
        cin>>x>>loc;
        Insert(x,loc);
        Print();
    }
    return 0;
}