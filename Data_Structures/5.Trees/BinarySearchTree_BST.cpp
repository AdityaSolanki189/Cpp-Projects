// non linear BST using Linked list
// Address of the root node is our head node
#include<bits/stdc++.h>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* root; // to store address of the rood node

BstNode* get_NewNode(int data){
    BstNode* newNode = new BstNode(); // create a new node
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = get_NewNode(data);
        return root;
    }
    //2 cases(left|right)
    // Using recursion
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

// Finding Min and Max Element in a BST
int FindMin(BstNode* root){
    if(root == NULL){
        cout << "Error: Empty Tree\n";
        return -1;
    }

    /* Iterative Method: 
    while(root->left != NULL){
        root = root->left;
    }
    return root->data; */

    // Exit condition for our recursion
    else if(root->left == NULL){
        return root->data;
    }
    // Search in Left Sub-Tree
    return FindMin(root->left);
}

int FindMax(BstNode* root){
    if(root == NULL){
        cout << "Error: Empty Tree\n";
        return -1;
    }

    /* Iterative Method:
    while(root->right != NULL){
        root = root->right;
    }
    return root->data; */

    // Exit condition for our recursion
    else if(root->right == NULL){
        return root->data;
    }
    // Search in Right Sub-Tree
    return FindMax(root->right);
}

// Finding Height of a Binary Tree
// Height of tree = No. of edges of the longest path from root to leaf
int Height(BstNode* root){
    if(root == NULL)
        return -1; // as we are counting edges and not nodes.
    
    return max(Height(root->left), Height(root->right)) + 1;    
}

int main(){
    root = NULL; // intitialze as NULL (Empty tree)

    int data, x;
    cout << "Enter No. of Nodes : ";
    cin >> x;
    cout << "\n";
    for(int i=0;i<x;i++){
        cout << "Enter Data in Node : ";
        cin >> data;
        root = Insert(root, data);
        cout << "\n";
    }

    int num;
    cout << "Enter Number to be Searched : ";
    cin >> num;

    if(Search(root, num) == true) cout << "Found\n";
    else cout << "Not Found\n";

    cout << "Min. Element of the BST : " << FindMin(root);
    cout << "\n";
    cout << "Max. Element of the BST : " << FindMax(root);
    cout << "\n";

    cout << "Height of BST : " << Height(root) << "\n";

    return 0;
}