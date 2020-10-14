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
        void delete_n();
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
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void DLL::insert_begg(){}
void DLL::insert_end(){}
void DLL::insert_n(){}
void DLL::delete_begg(){}
void DLL::delete_end(){}
void DLL::delete_n(){}
void DLL::reverse(){}

int main(){
    DLL obj;
    int nodes,data,t=1;
    cout<<"\nEnter Number Of Nodes : ";
    cin>>nodes;
    cout<<"Enter Data for Each Node :-"<<endl;
    for(int i=1;i<=nodes;i++){
        cout<<i<<". ";
        cin>>data;
        obj.create(data);
    }
    obj.display();
    while(t!=0){
        cout<<"\nBasic Operations :\n1. insert_begg();\n2. insert_end();\n3. insert_n(int,int);\n4. delete_begg();\n5. delete_end();\n6. delete_n(int,int);\n7. reverse();\n8. Exit(0)"<<endl;
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
                obj.delete_n();
                obj.display();
            break;

            case 7:
                obj.reverse();
                obj.display();
            break;

            case 8:
                t = 0;
            break;

            default:
                cout<<"Invalid Input";
            break;

        }
    }
    return 0;
}
