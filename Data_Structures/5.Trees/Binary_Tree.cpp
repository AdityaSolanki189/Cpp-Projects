#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *root;

class Binary_Tree{
    public:
    void create_root();
    void insert();
    void search();
    void pre_order();
    void post_order();
    void in_order();
    Binary_Tree(){
        root = NULL;
        Node *left = NULL;
        Node *right = NULL;
    }
};

void Binary_Tree :: create_root(){
    Node *root = new Node();
    cout<<"\nEnter the value in Root Node";
    cin>>root->data;
    root->left = NULL;
    root->right = NULL;
}

void Binary_Tree :: insert(){
    Node *temp = new Node();
    Node *curr = new Node();
    Node *parent = new Node();
    
    cout<<"\nEnter Data To be Inserted : ";
    cin>>temp->data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        
    }

}

int main(){
    Binary_Tree BT;
    BT.create_root();
    return 0;
}