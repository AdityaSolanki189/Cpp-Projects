#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

class CSLL{
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
        CSLL(){
            head = NULL;
        }
};

void CSLL :: create(int value){ //insert at end (Looped)
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void CSLL :: display(){
    if(head == NULL){
        cout<<"The List Is Empty!"<<endl;
        return;
    }
    Node *temp = head;
    cout<<"The Circular Singly Linked List is : ";
    do{
        cout<<temp->data<<" - > ";
        temp = temp->next;
    }while(temp != head);
    cout<<"HEAD";
}

void CSLL::insert_begg(){
    Node *newNode = new Node();
    cout<<"Enter Data in newNode : ";
    cin>>newNode->data;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    else{
        newNode = head->next;
        head = newNode;
    }
}

void CSLL::insert_end(){
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

void CSLL::insert_n(){
    
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
        newNode->next = head;
    }
    else{ //position in middle
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void CSLL::delete_begg(){
    
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    else{
        Node *temp = head;
        if(temp->next == head){
            head = NULL;
            delete temp;
        }
        else{
            head = temp->next;
            head->next = head;
            delete temp;
        }
    }
}

void CSLL::delete_end(){
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
        secondLast_node->next = head;
    
    delete Last_node;
}   


void CSLL::delete_pos(){  //by given position
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

void CSLL::delete_node(){ //by given data/key
    int key;
    cout<<"Enter The Data/Key : ";
    cin>>key;
    //If the list is empty
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    Node *temp = head;
    //If there is only one node
    if(temp->next == head && temp->data == key){
        head = NULL;
        delete temp;
        return;
    }

    Node *last = head, *d;
    temp = head;
    //If the first node is to be deleted
    if(temp->data == key){
        while(last->next != head)
            last = last->next;
        last->next = temp->next;
        delete temp;
        head = last->next;
    }
    //If the node is in the middle
    while(last->next != head && last->next->data != key){
        last = last->next;
    }
    //If the Node is Found
    if(last->next->data == key){
        d = last->next;
        last->next = d->next;
        delete d;
    }
    else{
        cout<<"No Such Key Found!";
        return;
    }
}

void CSLL::reverse(){
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
    CSLL obj;
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
        cout<<"\n\nCSLL Basic Operations :\n1. Insert at Beggining;\n2. Insert at End;\n3. Insert at N;\n4. Delete at Beggining;\n5. Delete at End;\n6. Delete a Node by Position\n7. Delete a Node by Value\n8. Reverse\n9. Exit(0)"<<endl;
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
