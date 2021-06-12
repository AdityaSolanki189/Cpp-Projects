/*Create Binary Search tree and find it's mirror image.
print original and new tree level wise. Find height & print leaf nodes.*/
 
#include<iostream>
using namespace std;

class BSTNode{
    public:
    int data;
    BSTNode *left , *right;
};

BSTNode* create_node(int data){
    BSTNode *newNode = new BSTNode;
    newNode->data = data;
    newNode->right =NULL;
    newNode->left = NULL;
    return newNode;
}

BSTNode* insert(BSTNode *root, int data){
    if(root == NULL)
        root = create_node(data);
    if(data < root->data)
        root->left = insert(root->left , data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void displayInorder(BSTNode *ptr){
    if(ptr!=NULL){
        displayInorder(ptr->left);
        cout<<ptr->data<<" ";
        displayInorder(ptr->right);
    }
}

void inorder_leaf(BSTNode *ptr){
    if(ptr!=NULL){
        inorder_leaf(ptr->left);
        if(ptr->left == NULL && ptr->right == NULL){
            cout<<ptr->data<<" ";
        }
        inorder_leaf(ptr->right);
    }
}

int height(BSTNode *ptr){
    int lt, rt;
    if(ptr!=NULL){
        lt = height(ptr -> left);
        rt = height(ptr -> right);

        if(lt>rt)
            return lt+1;
        else
            return rt+1;
    }
    else{
        return 0;
    }
}

void print(BSTNode *root, int level){
    if(root == NULL){
        return;
    }
    else if(level == 1)
        cout<<root->data<<" ";
    else if(level>1){
        print(root->left, level -1);
        print(root->right, level - 1);
    }
}

void level(BSTNode *root){
    int h =height(root);
    int i;
    for(i=1; i<=h; i++){
        print(root, i);
        cout<<endl;
    }
}

void mirror(BSTNode *node){
    if(node == NULL){
        return;
    }
    else{
        BSTNode *temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int main(){
    BSTNode* root=NULL;
    
    int data, choice, t=1;
    
    while(t){
        cout << "\nBST Operations : \n";
        cout << "\n1.Insert Node" << endl;
        cout << "2.Display Binary Tree (Inorder)" << endl;
        cout << "3.Height of Binary Tree" << endl;
        cout << "4.Mirror Image of Binary Tree" << endl;
        cout << "5.Display Level-wise" << endl;
        cout << "6.Display Leaf Nodes" << endl;
        cout << "7.Exit\n";
        cout << "\nEnter your choice : ";
        cin >>  choice;
        switch(choice){
            case 1: 
                cout << "\nEnter the value to be added : ";
                cin >> data;
                root = insert(root, data);
            break;

            case 2:
                cout << "\nBST InOrder Traversal : ";
                displayInorder(root);
                cout << "\n";
            break;
            
            case 3:
                cout << "\nThe height of Binary tree is : " << height(root);
                cout << "\n";
            break;
            
            case 4:
                cout << "\nThe Mirror Image of the Binary Search Tree is : "<<endl;
                mirror(root);
                displayInorder(root);
                mirror(root);
                cout << "\n";
            break;
            
            case 5:
                cout << "\nThe level wise display is: "<<endl;
                level(root);
                mirror(root);
                cout << "\nThe level-wise Display of Mirror Image is : "<<endl;
                level(root);
                mirror(root);
            break;
            
            case 6:
                inorder_leaf(root);
            break;

            case 7:
                t = 0;
                cout << "\n[Program Terminated!]\n";
            break;

            default:
                cout<<"\nInvalid choice!";
            break;
        }
    }
    return 0;
}