#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Reverse( Node* head){
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

Node* Insert(Node* head, int data){
    Node* temp = new Node();
    temp->data = data; temp->next = NULL;
    if (head == NULL) head = temp;
    else {
    Node* temp1 = head;
    while (temp1->next != NULL) temp1 = temp1->next;
    temp1->next = temp;
    }
    return head;
}

void Print(Node* head){
    while (head != NULL){
    printf("%d ", head->data);
    head = head->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;  //local variable head pointing NULL
    int n,elem;
    cout<<"\nEnter The Number Of Elements : ";
    cin>>n;
    cout<<"\nEnter Elements : ";
    for(int i=0;i<n;i++){
        cin>>elem;
        head = Insert(head,elem);
    }
    cout<<"\nThe Qriginal List : ";
    Print(head);
    head = Reverse(head);
    cout<<"\nThe Reversed List : ";
    Print(head);
}