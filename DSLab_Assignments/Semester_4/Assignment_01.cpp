// Dictionary as a BST and all operations on dictionary insert, update, delete and search.

#include<iostream>
#include<string>
using namespace std;

class Node{
    char key[20];
    char meaning[20];
    Node *left, *right;
};

class Dictionary{
    Node* root;
public:
    Dictionary(){
        root = NULL;
    }
    Node* getData();
    void createDictionary();
    void insertNode(Node*);
    void display_Dictionary(Node*);
    void search_Dictionary(char []);
    void update_Dictionary(char []);
    void Delete_fromDictionary(searchKey);
};

Node* Dictionary :: getData(){
    Node* newNode = new Node();
    cout << "\nEnter the Key Value : ";
    cin >> newNode->key;

    cout << "\nEnter its Meaning : ";
    cin >> newNode->meaning;

    newNode->left = newNode->right = NULL;
    return newNode;
}

void Dictionary :: createDictionary(){
    Node* newNode = new Node();
    newNode = getData();
    if(root == NULL)
        root = newNode;
    else    
        insertNode(newNode);
}

void Dictionary :: insertNode(Node* newNode){
    Node* temp = new Node();
    temp = root;

    while(1){
        if(strcmp(newNode->key, temp->key) < 0){
            if(temp->left == NULL){
                temp->left = newNode;
                break;
            }
            else
                temp = temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right = newNode;
                break;
            }
            else
                temp = temp->right;
        }
    }
}

void Dictionary :: display_Dictionary(Node *temp) {
    if (temp != NULL) {
        display_Dictionary(temp -> left);
        cout << "\n Keyword : " << temp -> key;
        cout << "\t Meaning : " << temp -> meaning;
        display_Dictionary(temp -> right);
    }
    cout << "\n";
}

void Dictionary :: search_Dictionary(char search_key[]) {
    Node *temp = root;
    
    while (temp != NULL) {
        if (strcmp(search_key, temp -> key) == 0) {
            cout << "Keyword found! The meaning is: " << temp -> meaning;
            return;
        }
        else if (strcmp(search_key, temp -> key) <= 0)
            temp = temp -> left;
        else
            temp = temp -> right;
    }
    cout << "Keyword " << search_key << " not found.\n";
}

void Dictionary :: update_Dictionary(char search_key[]){
    Node *temp = root;
    
    while (temp != NULL) {
        if (strcmp(search_key, temp -> key) == 0) {
            cout << "Keyword found! The meaning is: " << temp -> meaning;
            cout << "\nEnter the new meaning: ";
            cin >> temp -> meaning;
            return;
        }
        else if (strcmp(search_key, temp -> key) <= 0)
            temp = temp -> left;
        else
            temp = temp -> right;
    }

    cout << "Keyword " << search_key << " not found.\n";
}

void Dictionary :: Delete_fromDictionary(Node* temp, char deleteKey[]){
    Node* temp = new Node();
    temp = root;
    if(temp == NULL){
        cout << "\nTree Empty!";
        return;
    }
    if(strcmp(deleteKey, temp->key) < 0)
        temp->left = Delete_fromDictionary(temp->left)
    else if(strcmp)
}

int main() {
    Dictionary dictObj;

    int choice,t=1;
    char permission, search_key[20];

    while(t){
        cout << "\nEnter: 1 to create, 2 to display, 3 to search and 4 to update. \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            dictObj.createDictionary();
            break;
        case 2:
            dictObj.displayDictionary(root);
            break;
        case 3:
            cout << "Enter the keyword you would like to search - ";
            cin >> search_key;
            dictObj.searchInDictionary(search_key);
            break;
        case 4:
            cout << "Enter the keyword you would like to update - ";
            cin >> search_key;
            dictObj.updateInDictionary(search_key);
            break; 

        default:
            cout << "Please enter a valid number";
            break;
        }
    }
return 0;