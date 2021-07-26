/* A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
deleting keywords, updating values of any entry. Provide facility to display whole data sorted 
in ascending/ Descending order. Also find how many maximum comparisons may require for 
finding any keyword. Use Binary Search Tree for implementation. */
#include<iostream>
#include<string.h>
using namespace std;

struct Node{
    char key[20];
    char meaning[20];
    Node *left, *right;
}*root;

class Dictionary {
    public:
    Dictionary() {
        root = NULL;
    }
    Node *getData();
    Node *getInorderSuccessor(Node *curr);
    void create();
    void insertNode(Node *);
    void display(Node *);
    void search(char *);
    void update(char *);
    Node *remove(Node *, char *);
};

Node *Dictionary :: getData() {
    Node *new_node = new Node;
    cout << "\nEnter a key value : ";
    cin >> new_node -> key;

    cout << "Enter its meaning : ";
    cin >> new_node -> meaning;

    new_node -> right = NULL;
    new_node -> left = NULL;

    return new_node;
}

Node *Dictionary:: getInorderSuccessor(Node *curr){ 
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left; 
    return curr;
}

void Dictionary :: create() {
    Node *new_node = new Node;
    new_node = getData();

    if (root == NULL)
        root = new_node;
    else 
        insertNode(new_node);
}

void Dictionary :: insertNode(Node *new_node) {
    Node *temp = new Node;
    temp = root;
    
    while (1) {
        if (strcmp(new_node -> key, temp -> key) < 0) {
            if (temp -> left == NULL){
                temp -> left = new_node;
                break;
            }
            else
                temp = temp -> left;
        }
        else {
            if (temp -> right == NULL){
                temp -> right = new_node;
                break;
            }
            else
                temp = temp -> right;
        }
    }
}

void Dictionary :: display(Node *temp) {
    if (temp != NULL) {
        display(temp -> left);
        cout << "\nKeyword : " << temp -> key;
        cout << "\t Meaning : " << temp -> meaning;
        display(temp -> right);
    }
}

void Dictionary :: search(char search_key[]) {
    Node *temp = root;
    
    while (temp != NULL) {
        if (strcmp(search_key, temp -> key) == 0) {
            cout << "\nKeyword found! The meaning is: " << temp -> meaning << "\n";
            return;
        }
        else if (strcmp(search_key, temp -> key) < 0)
            temp = temp -> left;
        else
            temp = temp -> right;
    }

    cout << "\nKeyword " << search_key << " not found.\n";
}

void Dictionary :: update(char search_key[]){
    Node *temp = root;
    
    while (temp != NULL) {
        if (strcmp(search_key, temp -> key) == 0) {
            cout << "\nKeyword found! The meaning is: " << temp -> meaning;
            cout << "\nEnter the new meaning: ";
            cin >> temp -> meaning;
            return;
        }
        else if (strcmp(search_key, temp -> key) < 0)
            temp = temp -> left;
        else
            temp = temp -> right;
    }

    cout << "\nKeyword " << search_key << " not found.\n";
}

Node *Dictionary :: remove(Node *root, char delete_key[]) {

    if (root == NULL){
        cout << "\n[Dictionary Empty!]\n";
        return root;
    }

    if (strcmp(delete_key, root -> key) < 0)
        root->left = remove(root->left,delete_key);

    else if (strcmp(delete_key, root -> key) > 0)
        root->right = remove(root->right,delete_key);

    else{
        if (root->left == NULL){
            Node *temp = root -> right;
            delete root;
            return temp;
        }
        else if (root -> right == NULL){
            Node *temp = root -> left;
            delete root;
            return temp;
        }
        else{
            Node *succ=getInorderSuccessor(root);
            *root->key=*succ->key;
            root->right = remove(root->right,succ->key);
        }
    }
    return root;
}

int main(){
    int t=1,ch;
    char search_Key[20];
    Dictionary Obj;
    while(t){
        cout << "\nDictionary Using BST Operations: \n";
        cout << "1. Create\n2. Display\n3. Search\n4. Update\n5. Delete\n6. Exit.\nEnter Your Choice : ";
        cin >> ch;
        switch(ch){
            case 1: 
                Obj.create();
            break;

            case 2: 
                cout << "\nYour Dictionary : \n";
                Obj.display(root);
                cout << "\n";
            break;

            case 3: 
                cout << "\nEnter the keyword you want to Search :";
                cin >> search_Key;
                Obj.search(search_Key);
            break;

            case 4: 
                cout << "Enter the keyword you want to Update : ";
                cin >> search_Key;
                Obj.update(search_Key);
            break;

            case 5:
                cout << "\nEnter the keyword you want to delete : ";
                cin >> search_Key;
                root = Obj.remove(root, search_Key);
                cout<<"\nYour dictionary : \n";
                Obj.display(root);
            break;

            case 6:
                t = 0;
                cout << "\n[Program Terminated!]\n";
            break;

            default:
                cout << "\nInvalid Input!!\n";
            break;
        }
    }   
    return 0;
}