// DICTIONARY IMPLEMENTATION USING LINKEDLIST - WITHOUT STL
#include<iostream>
#include <cstring>
using namespace std;
#define max 11

struct list{
    int rno;
    string name;
    list *next;
};

list *root[max];

class Dictionary{
    list *ptr[max], *temp[max];
    public:
        int index;
        Dictionary();
        void insert(int, string);
        void search(int);
        void remove(int);
        void print_Dict();
};

Dictionary :: Dictionary(){
    index = -1;
    for(int i=0; i<max; i++){
        root[i] = NULL;
        temp[i] = NULL;
        ptr[i] = NULL;
    }
}

void Dictionary :: insert(int key, string str){
    index = key%11;
    ptr[index] = new list();
    ptr[index]->rno = key;
    ptr[index]->name = str;
    ptr[index]->next = NULL;

    if(root[index] == NULL){
        root[index] = ptr[index];
        root[index]->next = NULL;
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
    index = key%11;
    temp[index] = new list();
    temp[index] = root[index];

    while(temp[index] != NULL){
        if(temp[index]->rno == key){
            cout << "\nSearch key is found!!\n";
            cout << "\nStudent Name : " << temp[index]->name;
            return;
        }
        else temp[index] = temp[index]->next;
    }
    
    cout << "\nSearch key not found.......";
}

void Dictionary :: remove(int key){
    index = key%11;
    
    temp[index] = root[index];

    if(temp[index] != NULL && temp[index]->rno == key){
        root[index] = temp[index]->next;
        cout << temp[index]->name << " has been deleted.\n";
        delete temp[index];
        return;
    }
    
    while(temp[index] != NULL && temp[index]->rno != key){
        ptr[index] = temp[index];
        temp[index] = temp[index]->next;
    }
    
    if(temp[index] == NULL){ 
        cout << "\nKey not found.";
        return;
    }
    ptr[index]->next = temp[index]->next;
    cout << temp[index]->name << " has been deleted.\n";
    delete temp[index];
}

void Dictionary :: print_Dict(){
    for(int i=0; i<max; i++){
        temp[i] = root[i];
        while (temp[i] != NULL){
            cout << "Roll No.: " << temp[i]->rno << " | Name : " << temp[i]->name << "\n";
            temp[i] = temp[i]->next;
        }
    }
}

int main(){
    int val,ch,n,num;
    string name;
    Dictionary d;
    int t=1;
    while(t){
        cout << "\n\nMENU:\n1.Insert Key & Value";
        cout << "\n2.Search for a Value\n3.Delete a Value\n4.Print Dictionary(Hash Table)\n5.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch(ch){
            case 1:
                cout << "\nEnter No. of Elements to be Inserted:";
                cin >> n;
                for(int i=0; i<n; i++){
                    cout << "\nEnter Roll No. & Name : ";
                    cin >> num >> name;
                    d.insert(num, name);
                }
            break;

            case 2:
                cout << "\nEnter the Key to be Searched:";
                cin >> n;
                d.search(n);
            break;

            case 3:
                cout << "\nEnter the Key to be Deleted:";
                cin >> n;
                cout << "\n";
                d.remove(n);
            break;
            
            case 4:
                cout << "\nDictionary(Hash Table):\n";
                d.print_Dict();
            break;
            
            case 5:
                t = 0;
            break;

            default:
                cout << "\nInvalid Choice.";
            break;
        }
    }

    return 0;
}