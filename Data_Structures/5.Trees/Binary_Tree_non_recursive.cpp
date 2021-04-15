/* 
Properties:
    1. At given L -> Max(Nodes at L) = 2^(L-1)
    2. At given H -> Max(Nodes in Tree) = 2^(H+1) - 1
    3. At given N -> Min(Height of tree) = [log(N+1)] - 1
    4. At Given Leaves -> min(Levels) = [log (Leaves)] + 1
    5. At Given No. of Nodes -> Total Emumeration = (2n)! / (n+1)!.n!  
    
*/

// All operations are Non - Recursive (Level Order Traversing)

#include <iostream>
#include <queue>
#include <stack>
#include <climits>
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
    /* void del_deepestNode(Node*, Node*);
    void remove(); */
    void level_order();
    void pre_order();
    void post_order();
    void in_order();
    void find_MAX();
    void find_MIN();
    void find_SUM();
    void find_Size();
    void Reverse_level_order();
    void Height_Depth();
    void No_of_leaves();
    void No_of_full_nodes();
    void No_of_half_nodes();
    void Diameter_width();
    void level_with_max_sum();
    Binary_Tree(){
        root = NULL;
        Node *left = NULL;
        Node *right = NULL;
    }
};

void Binary_Tree :: create_root(){
    Node *newNode = new Node();
    cout << "\nEnter the value in Root Node : ";
    cin >> newNode->data;
    newNode->left = NULL;
    newNode->right = NULL;
    root = newNode;
}

// Using Level Order Traversal to Insert Node in the Tree
void Binary_Tree :: insert(){
    queue<Node*> q;
    queue<Node*> empty;
    Node* temp;
    Node* newNode = new Node();
    cout << "\nEnter value to be inserted : ";
    cin >> newNode->data;
    newNode->left = newNode->right = NULL;
    if(!newNode)
        cout << "\nMemory Error!";
    if(!root){
        root = newNode;
        return;
    }
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        else{
            temp->left = newNode;
            swap(q,empty);
            return;
        }
        if(temp->right){
            q.push(temp->right);
        }
        else{
            temp->right = newNode;
            swap(q,empty);
            return;
        }
    }
    swap(q, empty);   // to empty a queue
    cout << "Node Inserted Successfully.\n";
}

void Binary_Tree :: search(){
    int key;
    cout << "Enter Data to be Searched : ";
    cin >> key;
    Node* temp = new Node();
    queue<Node*> q;
    queue<Node*> empty;
    if(!root){
        cout << "\nEmpty Tree!";
        return;
    }
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == key){
            cout << "\nData Found in the Tree!";
            return;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);    
    }
    swap(q, empty);  
    cout << "\n";
}

/* The deletion of a node in binary tree can be implemented as
• Starting at root, find the node which we want to delete.
• Find the deepest node in the tree.
• Replace the deepest node’s data with node to be deleted.
• Then delete the rightmost deepest node. */
/* void Binary_Tree :: del_deepestNode(Node* r_node, Node* del_node){
    queue<Node*> q, empty;
    q.push(r_node);
    // Do level order traversal until last node and delete it
    Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == del_node) {
            temp = NULL;
            delete (del_node);
            return;
        }
        if (temp->right) {
            if (temp->right == del_node) {
                temp->right = NULL;
                delete (del_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left) {
            if (temp->left == del_node) {
                temp->left = NULL;
                delete (del_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
    swap(q, empty);
}

// Search the Node to be deleted and Replace its value with Deepest Node data
void Binary_Tree :: remove(){
    int del;
    cout << "\nEnter Data to Remove form the Tree : ";
    cin >> del;
    Node* temp, key_node = NULL;
    queue<Node*> q, empty;
    q.push(root);
    // searching the node to delete
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == del) // temp will store searched node 
            key_node = temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if (key_node != NULL) {
        int x = temp->key;     // data of the deepest rightmost Node
        del_deepestNode(root, temp);
        key_node->key = x;
    }
    cout << "Node Removed Successfully!\n";
} */

// Level Order Traversal to  Display
void Binary_Tree :: level_order(){
    cout << "\nLevel-Order Traversal : ";
    Node* temp = new Node();
    queue<Node*> q;
    queue<Node*> empty;
    if(!root)
        return;
    q.push(root);
    while (!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    swap(q,empty);
    cout << "\n";
}

// In-Order Traversal to Display
void Binary_Tree :: in_order(){
    cout << "\nIn-Order Traversal : ";
    stack<Node*> s, empty;
    Node* temp = root;
    while(1){
        while(temp){
            s.push(temp);
            temp = temp->left; // keep on adding the left child to the stack
        }
        if(s.empty()){
            break;
        }
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
    swap(s, empty);
    cout << "\n";
}

// Pre-Order Traversal to Display
void Binary_Tree :: pre_order(){
    cout << "\nPre-Order Traversal : ";
    stack<Node*> s, empty;
    Node* temp = root;
    while(1){
        while(temp){
            cout << temp->data << " "; // print current node
            s.push(temp);
            temp = temp->left; // keep on adding the left child to the stack
        }
        if(s.empty()){
            break;
        }
        temp = s.top();
        s.pop();
        temp = temp->right;
    }
    swap(s, empty);
    cout << "\n";
}

// Post-Order Traversal to Display
void Binary_Tree :: post_order(){
    cout << "\nPost-Order Traversal : ";
    stack<Node*> s, empty;
    Node* temp = root;
    Node* previous = new Node();
    do{
        while(temp){
            s.push(temp);
            temp = temp->left;
        }
        while(temp == NULL & !s.empty()){
            temp = s.top();
            if(temp->right == NULL || temp->right == previous){
                cout << temp->data << " ";
                s.pop();
                previous = temp;
                temp = NULL;
            }
            else    temp = temp->right;
        }
    }while(!s.empty());
    cout << "\n";
}

// Find the Minimum of the Tree
void Binary_Tree :: find_MIN(){
    Node* temp = new Node();
    int min = INT_MAX;
    queue<Node*> q, empty;
    if(!root)
        return;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(min > temp->data)
            min = temp->data;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    swap(q, empty);
    cout << "\nValue of the Min Element in the Binary Tree : " << min;
    return;
}

// Find the Maximum of the Tree
void Binary_Tree :: find_MAX(){
    Node* temp = new Node();
    int max = INT_MIN;
    queue<Node*> q, empty;
    if(!root)
        return;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(max < temp->data)
            max = temp->data;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    swap(q, empty);
    cout << "\nValue of the Max Element in the Binary Tree : " << max;
    return;
}

// Find the Sum of All Elements of the Binary Tree
void Binary_Tree :: find_SUM(){
    Node* temp = new Node();
    int sum = 0;
    queue<Node*> q, empty;
    if(!root)
        return;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        sum += temp->data; 
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    swap(q, empty);
    cout << "\nSum of al the Elements in the Binary Tree : " << sum;
    return;
}

// Find the Size of the Binary Tree
void Binary_Tree :: find_Size(){
    Node* temp = new Node();
    queue<Node*> q, empty;
    int count = 0;
    if(!root){
        cout << "\nEmpty Tree!";
        return;
    }
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        count++;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    swap(q, empty);
    cout << "\nThe Size of the Binary Tree : " << count;
}

// Print the Level Order Traversal in Reverse Order
void Binary_Tree :: Reverse_level_order(){
    queue<Node*> q, empty;
    stack<Node*> s;
    Node* temp = new Node();
    if(!root){
        cout << "\nEmpty Tree!";
        return;
    }
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        s.push(temp);
    }
    while(!s.empty()){
        cout << s.top()->data << " ";
        s.pop();
    }
}



int main(){
    Binary_Tree BT;
    cout << "Welcome To Binary Tree as ADT Operations :\n";
    BT.create_root();
    int t=1;
    while(t!=0){
        cout<<"\n\nBasic Operations :\n1. Insert a Node;\n2. Search a Node;\n3. Remove a Node;\n4. Level-Order Traversal;\n5. In-Order Traversal;\n6. Pre-Order Traversal;\n7. Post-Order Traversal;\n8. Find Max Node of Tree;\n9. Find Min Node of Tree;\n10. Exit(0)"<<endl;
        int ch;
        cin>>ch;
        switch (ch){
            case 1:
                BT.insert();
            break;

             case 2:
                BT.search();
            break;

            case 3:
                /* BT.remove(); */
            break;

            case 4:
                BT.level_order();
            break;

            case 5:
                BT.in_order();
            break;

            case 6:
                BT.pre_order();
            break;

            case 7:
                BT.post_order();
            break;

            case 8:
                BT.find_MAX();
            break;

            case 9:
                BT.find_MIN();
            break; 
            
            case 10:
                cout << "Thank You!";
                t = 0;
            break;

            default:
                cout<<"Invalid Input!";
            break;

        }
    }
    return 0;
}

/* void BinaryTree :: create(int data) {
    Node *new_node = new Node;
    new_node -> data = data;
    new_node -> lc = NULL;
    new_node -> rc = NULL;

    if (root == NULL) {
        root = new_node;
    }
    else {
        insertNode(root, new_node);
    }
}

void BinaryTree :: insertNode(Node *old_node, Node *new_node) {
    char ch;
    cout << "Left or right of " << old_node -> data << "? - ";
    cin >> ch;

    if (ch == 'l') {
        if (old_node -> lc == NULL) 
            old_node -> lc = new_node;
        else
            insertNode(old_node -> lc, new_node);
    }
    else if (ch == 'r') {
        if (old_node -> rc == NULL) 
            old_node -> rc = new_node;
        else
            insertNode(old_node -> rc, new_node);
    }
    else {
        cout << "Enter valid choice\n";
        insertNode(old_node, new_node);
    }
}
*/