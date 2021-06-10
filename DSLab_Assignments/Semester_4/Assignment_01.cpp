#include<iostream>
#include<string.h>

using namespace std;

struct node{
    char key[20];
    char meaning[20];
    node *left, *right;
}*root;

class dictionary{
    public:
    dictionary(){
        root = 0;
    }
    node* getData();
    void create();
    void insert(node *newNode);
    int search(char []);
    void display(node *);
    void update(node*);
    node* del(node *,char deletekey[]);
    node *min(node *);

};

node *dictionary :: getData(){
    node *newNode;
    newNode = new node();
    cout<<"Enter key value : ";
    cin>>newNode->key;
    cout<<"Enter the meaning of Key :";
    cin>>newNode->meaning;

    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void dictionary :: insert(node *newNode){
    node *temp = root;
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

void dictionary :: create(){
    node* newnode = new node();
    char input = 'y';
    while(input == 'y' || input == 'Y'){
        newnode = getData();
        if(root == NULL)
            root = newnode;
        else{
            insert(newnode);
        }
        cout<<"Do you want to add more data?? (y/n)";
        cin>>input;
        if(input =='n' || input == 'N')
            break;
    }
}

void dictionary :: display(node *temp){
    if(temp !=NULL){
        display(temp->left);
        cout<<"Key word :"<< temp->key;
        cout<<"\t"<<"Meaning : "<< temp->meaning<<endl;
        display(temp->right);
    }
}

int dictionary :: search(char searchKey[]){
    node *temp;
    temp = root;
    while(temp!= NULL){
        if(strcmp(searchKey, temp->key) == 0 )
            return 1;
        else if(strcmp(searchKey ,temp->key) < 0)  
            temp = temp->left;
        else if(strcmp(searchKey, temp->key) > 0 )    
            temp = temp->right;
        else 
            return 0;
    }
    return 0;
}

void dictionary :: update(node *updatednode){
    node *temp = new node;
    temp = root;
    int flag =0;
    while(flag == 0){
        if(strcmp(updatednode->key, temp->key) == 0 ){
            cout<<"Enter the new meaning for the key :";
            cin>>temp->meaning;
            cout<<"Meaning Updated Successfully!"<<endl;
            return;
        }
        else if(strcmp(updatednode->key, temp->key) < 0)  
            temp = temp->left;
        else if(strcmp(updatednode->key, temp->key) > 0 )    
            temp = temp->right;
    }
}

node *dictionary :: min(node *successor){
    while(successor -> left != NULL){
        successor = successor -> left;
    }
    return successor;
}

node *dictionary :: del(node *tempnode, char deletekey[]){
    node *deleteNode;

    if(tempnode == NULL){
        cout<<"Dictionary (TREE) is empty!/ Key Not Found\n";
        return tempnode;
    }
    else if(strcmp(deletekey, tempnode -> key) < 0){
        tempnode -> left = del(tempnode -> left, deletekey);
        return tempnode;
    }
    else if(strcmp(deletekey, tempnode -> key) > 0){
        tempnode -> right = del(tempnode -> right, deletekey);
        return tempnode;
    }
    else{
        if(tempnode -> left == NULL && tempnode -> right == NULL){
            deleteNode = tempnode;
            delete deleteNode;
            return 0;
        }
        else if(tempnode -> left != NULL){
            deleteNode = tempnode;
            tempnode = tempnode -> right;
            delete deleteNode;
            return tempnode;
        }
        else if(tempnode -> right != NULL){
            deleteNode = tempnode;
            tempnode = tempnode -> left;
            delete deleteNode;
            return tempnode;
        }
        deleteNode = min(tempnode -> right);
        strcpy(tempnode -> key, deleteNode -> key);
        tempnode -> right = del(tempnode -> right, deleteNode -> key);
    }
    return tempnode;
}

node *updatednode = new node;

int main(){
    char a;
    int ch;
    char x[20];
    dictionary d;
    do{
        cout<<"\n1.Create\n2.Display\n3.Search\n4.Update\n5.Delete\nEnter choice :";
        cin>>ch;
        switch(ch){
            case 1: 
                d.create();
            break;
            case 2: 
                cout<<endl<<"Contents in dictionary :"<<endl;
                d.display(root);
            break;

            case 3: 
                cout<<"Enter the keyword which you want to search :";
                cin>>x;
                if(d.search(x) == 1)
                    cout<<"Keyword found"<<endl;
                else
                    cout<<"Keyword not found"<<endl;
            break;

            case 4: 
                cout<<"Enter the key for the keyword whose meaning you want to update :";
                cin>>updatednode->key;
                if(d.search(updatednode->key) == 1){                        
                    d.update(updatednode);
                }
                else
                cout<<"key not found"<<endl;
            break;

            case 5:
                {
                    char searchkey[20];
                    cout<<"Enter the key which you want to delete :";
                    cin>>searchkey;
                    node* deleteNode = new node();
                    deleteNode = d.del(root, searchkey);
                    cout<<"Node Deleted successfully!"<<endl;
                    cout<<endl<<"Updated dictionary :: "<<endl;
                    d.display(root);
                }
            break;

            default:
                cout<<"Enter correct input!!"<<endl;
            break;
        }
        cout<<"Continue?(y/n) :";
        cin>>a;
    } while (a == 'y' || a == 'Y');
    return 0;
}