#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

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
    cout<<endl;;
}

void Delete(int n){            //delete node at position n
    Node* temp1 = head;
    if(n==1){
        head = temp1->next;    //head now points to the 2nd node
        delete temp1;             
        return;
    }
    for(int i=0;i<n-2;i++){     //temp1 points towards n-1 th node
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;  //nth node
    temp1->next = temp2->next;  //(n+1)th node
    //thus linking the (n-1)th node and the (n+1)th node
    delete temp2;               //deleting temp2(the prev nth node)
}

int main(){
    Node* head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); //List : 2,4,5,6
    Print();
    int n;
    cout<<"Enter Position : "<<endl;
    cin>>n;    
    Delete(n);
    Print();
    return 0;
}