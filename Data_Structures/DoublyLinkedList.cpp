#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *head;

class DLL{
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
        DLL(){
            head = NULL;
        }
};

void DLL :: create(int value){ //insert at end Looped
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DLL :: display(){
    Node *temp;
    if(head == NULL){
        cout<<"The List Is Empty!"<<endl;
        return;
    }
    cout<<"The Doubly Linked List is : ";
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<" < - > ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void DLL::insert_begg(){
    Node *newNode = new Node();
    cout<<"Enter Data in newNode : ";
    cin>>newNode->data;
    
    newNode->prev = NULL;

    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DLL::insert_end(){
    Node *newNode = new Node();
    cout<<"Enter Data in newNode : ";
    cin>>newNode->data;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DLL::insert_n(){
    
    if(head == NULL){
        cout<<"The List Is Empty.\n";
        return;
    }

    int pos;
    cout<<"Enter The Position : ";
    cin>>pos;
    Node *temp = head;
    
    if(pos == 1){
        temp->next = NULL;
        head = temp;
        return;
    }
    else{
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
            if(temp->next==NULL){
                cout<<"Insufficient Nodes\n";
                return;
            }
        }
    }
    Node *newNode = new Node();
    cout<<"Enter The Data : ";
    cin>>newNode->data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(temp->next==NULL){ //position of last node
        temp->next = newNode;
        newNode->next = NULL;
        newNode->prev = temp;
    }
    else{ //position in middle
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DLL::delete_begg(){
    
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    else{
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void DLL::delete_end(){
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    
    Node* temp = head;
    if(temp->prev == temp->next){
        head = NULL;
        delete temp;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;        
    }   
}

void DLL::delete_pos(){  //by given position
    if(head == NULL){
        cout<<"The List Is Empty.\n";
        return;
    }

    int pos;
    cout<<"Enter The Position : ";
    cin>>pos;

    Node *temp = head;
    if(pos == 1){
        Node *temp1 = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
        if(temp->next==NULL){
            cout<<"Insufficient Nodes\n";
            return;
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void DLL::delete_node(){ //by given data
    Node *curr,*temp;
    int val;
    cout<<"Enter The Value : ";
    cin>>val;
    if(head == NULL){
        cout<<"List Is Empty\n";
        return;
    }
    temp = head;
    while(temp->data!=val){
        if(temp->next==NULL){
            cout<<"Data Not Found\n";
            return;
        }
        temp = temp->next;
    }
    if(head->next == temp){ //first node
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    else if(temp->next == NULL){ //last node
        temp->prev->next = NULL;
        delete temp; 
    }
    else if(temp->next->next == NULL){
        temp->next = NULL;
    }
    else{
        curr = temp->next;
        temp->next = curr->next;
        curr->next->prev = temp;
        delete curr;
        cout<<"Node Deleted \n"<<endl;
    }
}

void DLL::reverse(){
    Node *temp = head;
    if(temp == NULL){
        cout<<"List is Empty.\n";
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<"The Reversed List : ";
    while(temp != head){
        cout<<temp->data<<" < - > ";
        temp = temp->prev;
    }
    cout<<temp->data;
}

int main(){
    DLL obj;
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
        cout<<"\n\nBasic Operations :\n1. Insert at Beggining;\n2. Insert at End;\n3. Insert at N;\n4. Delete at Beggining;\n5. Delete at End;\n6. Delete a Node by Position\n7. Delete a Node by Value\n8. Reverse\n9. Exit(0)"<<endl;
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
