#include<bits/stdc++.h>
using namespace std;
 
struct Node{
    int key;
    struct Node *left, *right;
};
 
struct Node *newNode(int item){
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Stores in-oder traversal of the BST in arr[]
void storeSorted(Node *root, int arr[], int &i){
    if (root != NULL){
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}
 
/* A function to insert a new Node with given key in BST */
Node* insert(Node* node, int key){
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) Node pointer */
    return node;
}
 
// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n){
    struct Node *root = NULL;
 
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        root = insert(root, arr[i]);
 
    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}

/* 
    Average Case Time Complexity : O(n log n) Adding one item to a Binary Search tree on average takes O(log n) time. Therefore, adding n items will take O(n log n) time.

    Worst Case Time Complexity : O(n2). The worst case time complexity of Tree Sort can be improved by using a self-balancing binary search tree like Red Black Tree, AVL Tree. Using self-balancing binary tree Tree Sort will take O(n log n) time to sort the array in worst case. 
    
    Auxiliary Space : O(n)
*/

int main(){
    int arr[] = {5, 4, 7, 2, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    treeSort(arr, n);
 
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    return 0;
}

/* 
Theory:
Tree sort uses a binary search tree. It involves scanning each element of the input and placing it
into its proper position in a binary search tree. This has two phases:
    • First phase is creating a binary search tree using the given array elements.
    • Second phase is traversing the given binary search tree in inorder, thus resulting in a
    sorted array. 
*/