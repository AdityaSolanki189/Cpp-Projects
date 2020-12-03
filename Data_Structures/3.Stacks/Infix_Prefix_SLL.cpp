#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node *next;
};

Node *head;

void push(char oper){
    Node *newNode = new Node();
    newNode->data = oper;
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

void pop(){
    if(head == NULL){
        //cout<<"Stack Is Empty"<<endl;
        return ;
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

char top() {       //print last node
    if(head == NULL){
        //cout<<"The Stack Is Empty!"<<endl;
        return '\0';
    }
    Node *temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->data;
}

bool empty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

int priority ( char alpha ){
    if(alpha == '+' || alpha =='-'){
        return(1);
    } 
    if(alpha == '*' || alpha =='/'){
        return(2);
    }
    if(alpha == '^'){
        return 4;
    }
    return 0;
}

bool precedence(char op1, char op2){
    if(priority(op1)>=priority(op2)){
        return true;
    }
    else{
        return false;
    }
} 

string convert(string infix){
    string postfix = "";
    int i=0;
    while(infix[i]!='\0'){
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z'){
            postfix += infix[i];
            i++;
        }
        else {
            while(!empty() && precedence(top(),infix[i])){
                postfix += top();
                pop();
            }
            push(infix[i]);
            i++;
        }
    }
    while(!empty()){
        postfix += top();
        pop();
    }
    return postfix;
}

int main(){
    head = NULL;
    string infix, postfix;
    cout<<"\nEnter The Infix Expression : ";
    cin>>infix;
    postfix = convert(infix);
    cout<<"The Converted Postfix String Is : "<<postfix;
    return 0;
}