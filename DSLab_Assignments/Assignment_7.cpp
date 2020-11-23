//Pinnacle Club Problem using singly linked list

#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    Node *link;
};

class List{
    public:
        int pos,count1=0,cont=0;
        string ch2,ch;
        Node *head,*tail,*prev,*cur;
        Node *create_node();
        void create_list();
        void operation();
        void display();
        void data();
        List(){
            head = NULL;
            tail = NULL;
        }
};

Node *List :: create_node(){
    Node *new_node = new Node();
    prev = NULL;
    cur= head;
    cout<<"Enter Member's Name : "<<endl;
    cin.ignore();
    getline(cin,new_node->data);
    new_node->link = NULL;
    count1= count1+1;
    return (new_node);
}

void List :: display(){
    Node *temp;
    temp = head;
    if(temp==NULL){
        cout<<"list Is Empty"<<endl;
        return;
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<" "<<endl;
            temp = temp->link;
        }
    }
}

void List :: create_list(){ 
    Node *new_Node;
    char choice_am;
    char temp = 'y';
    string pswd_user;
    string pswd = "club";
    cout<<"Are You Admin or Memeber? (A/M)"<<endl;
    cin>>choice_am;
    if(choice_am == 'A'|| choice_am == 'a'){
        cout<<"Enter Club's Password : ";
        cin>>pswd_user;
        while(temp == 'y'){
            if(pswd == pswd_user){
                cout<<"Access Granted!"<<endl;
                while(temp == 'y'){
                    new_Node = create_node();
                    if(head == NULL){
                        head = new_Node;
                        tail = new_Node;
                    }
                    else{
                        tail->link = new_Node;
                        tail = new_Node;    
                    }
                    cout<<"Do you want to Enter More Members ? (y/n)"<<endl;
                    cin>>temp;
                }
            }
            else{
                temp = 'y';
                cout<<"Incorrect Password!"<<endl;
                cout<<"Do you want to TRY AGAIN ? (y/n)";
                cin>>temp;
                if(temp == 'n') return;
            }
        }
    }
    else{
        cout<<"You Cannot Edit The Members List!"<<endl;
    }
}

int main(){
    List obj;
    cout<<"            Welcome To Pinnacle Club\n"<<endl;
    while(t!=0){
        cout<<"\nPinnacle Club Operations :\na) Create A List\nb) Compute Total Memebrs OF Club\nc) Display All Members\nd) Display List in Reverse Order\ne) Exit(0)"<<endl;
        int ch;
        cin>>ch;
        switch (ch){
            case 1:
                obj.insert_begg();
                obj.display();
            break;

            case 2:
                obj.insert_end();
                obj.display();
            break;

            case 3:
                obj.insert_n();
                obj.display();
            break;

            case 4:
                obj.delete_begg();
                obj.display();
            break;

            case 5:
                obj.delete_end();
                obj.display();
            break;

            case 6:
                obj.delete_n();
                obj.display();
            break;

            case 7:
                obj.reverse();
            break;

            case 8:
                t = 0;
            break;

            default:
                cout<<"Invalid Input";
            break;

        }
    }
    return 0;
}
