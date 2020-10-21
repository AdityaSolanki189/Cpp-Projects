#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

class SLL{
    public:
        void create(int);
        void display();
        void insert_begg();
        void insert_end();
        void insert_n();
        void delete_begg();
        void delete_end();
        void delete_pos();
        void delete_node();
        void reverse();
        SLL(){
            head = NULL;
        }
};

void SLL :: create(int value){ //insert at end Looped
    Node *newNode = new Node();
    newNode->data = value;
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

void SLL :: display(){
    Node *temp;
    if(head == NULL){
        cout<<"The List Is Empty!"<<endl;
        return;
    }
    cout<<"The Singly Linked List is : ";
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<" - > ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void SLL::insert_begg(){
    Node *newNode = new Node();
    cout<<"Enter Data in newNode : ";
    cin>>newNode->data;
    newNode->next = NULL;

    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void SLL::insert_end(){
    Node *newNode = new Node();
    cout<<"Enter Data in newNode : ";
    cin>>newNode->data;
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

void SLL::insert_n(){
    
    if(head == NULL){
        cout<<"The List Is Empty.\n";
        return;
    }

    int pos;
    cout<<"Enter The Position : ";
    cin>>pos;

    Node *newNode = new Node();
    cout<<"Enter The Data : ";
    cin>>newNode->data;
    newNode->next = NULL;
    
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *temp = head;
    for(int i=0;i<pos-2;i++){
        temp = temp->next;
        if(temp->next==NULL){
            cout<<"Insufficient Nodes\n";
            return;
        }
    }

    if(temp->next==NULL){ //position of last node
        temp->next = newNode;
        newNode->next = NULL;
    }
    else{ //position in middle
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void SLL::delete_begg(){
    
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    else{
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
}

void SLL::delete_end(){
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
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


void SLL::delete_pos(){  //by given position
    if(head == NULL){
        cout<<"The List Is Empty.\n";
        return;
    }

    int pos;
    cout<<"Enter The Position : ";
    cin>>pos;

    Node *temp = head;
    if(pos == 1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0;i<pos-2;i++){
        temp = temp->next;
        if(temp->next==NULL){
            cout<<"Insufficient Nodes\n";
            return;
        }
    }
    //after the for loop temp points towards n-1 th node
    Node* temp2 = temp->next; // temp 2 points to n th node
    temp->next = temp2->next; // link n-1 th node with n+1 the node
    delete temp2; // delete n th node
}

void SLL::delete_node(){ //by given data/key
    Node* prev = NULL;
    Node* curr = head;
    int key;
    cout<<"Enter The Data/Key : ";
    cin>>key;

    if(curr != NULL && curr->data == key){
        head = curr->next;
        delete curr;
        return;
    }
    
    while(curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    
    if(curr == NULL) return;

    prev->next = curr->next;
    delete curr;
}

void SLL::reverse(){
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
}

int main(){
    SLL obj;
    int nodes,data,t=1;
    cout<<"\nEnter Number Of Nodes : ";
    cin>>nodes;
    cout<<"Enter Data for Each Node :-"<<endl;
    for(int i=1;i<=nodes;i++){
        cout<<"Node "<<i<<" -> ";
        cin>>data;
        obj.create(data);
    }
    obj.display();
    while(t!=0){
        cout<<"\n\nSLL Basic Operations :\n1. Insert at Beggining;\n2. Insert at End;\n3. Insert at N;\n4. Delete at Beggining;\n5. Delete at End;\n6. Delete a Node by Position\n7. Delete a Node by Value\n8. Reverse\n9. Exit(0)"<<endl;
        int ch;
        cin>>ch;
        switch (ch){
            case 1:
                obj.insert_begg();
                obj.display();
            break;

            case 2:
                obj.insert_end();
                obj.display();
            break;

            case 3:
                obj.insert_n();
                obj.display();
            break;

            case 4:
                obj.delete_begg();
                obj.display();
            break;

            case 5:
                obj.delete_end();
                obj.display();
            break;

            case 6:
                obj.delete_pos();
                obj.display();
            break;

            case 7:
                obj.delete_node();
                obj.display();
            break;

            case 8:
                obj.reverse();
                obj.display();
            break;
            
            case 9:
                t = 0;
            break;

            default:
                cout<<"Invalid Input";
            break;

        }
    }
    return 0;
}
