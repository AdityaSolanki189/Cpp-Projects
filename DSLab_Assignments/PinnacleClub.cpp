#include <iostream>
using namespace std;

struct Node{
    string name;
    Node *next;
};

Node *head;

class Club{
    public:
        void create(string);
        void operate();
        void display();
        void reverse();
        Club(){
            head = NULL;
        }
};

void Club :: create(){
    Node *newNode = new Node();
    cout<<"Enter Your Name : ";
    getline(cin,newNode->name);
    cin.ignore();
    
}

int main(){
    Club obj;
    cout<<"            Welcome To Pinnacle Club\n"<<endl;
    obj.create();
    cout<<"\nPinnacle Club Operations :\na) Add or Delete a Member\nb) Compute Total Memebrs OF Club\nc)Display All Members\nd) Display List in Reverse Order\ne) Exit!"<<endl;

    return 0;
}
