#include<iostream>
#include <cstring>
using namespace std;
#define max 11

struct list{
    int data;
    list *next;
};

list *ptr[max],*root[max],*temp[max];

class Dictionary{
    public:
        int index;
        Dictionary();
        void insert(int);
        void search(int);
        void remove(int);
        void print_Dict();
};

Dictionary :: Dictionary(){
    index = -1;
    for(int i=0; i<max; i++){
        root[i] = NULL;
        ptr[i] = NULL;
        temp[i] = NULL;
    }
}

void Dictionary :: insert(int key){
    index = int(key%11);
    ptr[index] = new list();
    ptr[index]->data = key;

    if(root[index] == NULL){
        root[index] = ptr[index];
        root[index]->next = NULL;
        temp[index] = ptr[index];
    }
    else{
        temp[index] = root[index];
        while(temp[index]->next != NULL){
            temp[index] = temp[index]->next;
        }    
        temp[index]->next = ptr[index];
    }
}

void Dictionary :: search(int key){
    int flag = 0;
    index = int(key%11);
    temp[index] = root[index];

    while(temp[index] != NULL){
        if(temp[index]->data == key){
            cout << "\nSearch key is found!!";
            flag = 1;
            break;
        }
        else temp[index] = temp[index]->next;
    }
    if(flag==0){
        cout << "\nSearch key not found.......";
    }
}

void Dictionary :: remove(int key){
    index = int(key%11);
    temp[index] = root[index];

    while(temp[index]->data != key && temp[index] != NULL){
        ptr[index] = temp[index];
        temp[index] = temp[index]->next;
    }

    ptr[index]->next = temp[index]->next;
    cout << "\n" << temp[index]->data << " has been deleted.";
    
    temp[index]->data = -1;
    temp[index] = NULL;
    delete temp[index];
}

void Dictionary :: print_Dict(){
    for(int i=0; i<max; i++){
        while (root[i] != NULL){
            cout << root[i]->data << "\n";
            root[i] = root[i]->next;
        }
    }
}

int main(){
    int val,ch,n,num;
    char c;
    Dictionary d;
    do{
        cout<<"\nMENU:\n1.Create";
        cout<<"\n2.Search for a value\n3.Delete an value\n4.Print Dictionary";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\nEnter the number of elements to be inserted:";
                cin>>n;
                cout<<"\nEnter the elements to be inserted:";
                for(int i=0; i<n; i++){
                    cin>>num;
                    d.insert(num);
                }
            break;

            case 2:
                cout<<"\nEnter the element to be searched:";
                cin>>n;
                d.search(n);
            break;

            case 3:
                cout<<"\nEnter the element to be deleted:";
                cin>>n;
                d.remove(n);
            break;
            
            case 4:
                cout << "\nDictionary:\n";
                d.print_Dict();
            break;

            default:
                cout<<"\nInvalid Choice.";
        }
        cout<<"\nEnter y to Continue:";
        cin>>c;
    }while(c=='y' || c=='Y');
    
    return 0;
}