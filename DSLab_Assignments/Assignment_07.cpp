/* 
	PL1 Assignment 7 by Aditya Solanki 
	Roll No. 2193023
	CSE - 3   

    Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third
    and final year can be granted membership on request. Similarly one may cancel the membership of club.
    The First position of list is always reserved for the President of club and last position of list is reserved for
    the Secretary of club. Write C++ program to maintain information of club member‘s using singly linked
    list.Write functions
    1. Add and delete the members.
    2. Compute total number of members of club
    3. Display members
    4. Display list in reverse order
*/
#include<iostream>
using namespace std;

struct Node{
    string data;
    Node *link;
};

class list1{
    public:  
    int pos,count1=0,count2=0;
    string ch1="club";
    string ch2,ch;

    Node *head,*tail,*prev,*cur,*temp;
    Node *create_node();

    void create_list();
    void operation();
    void display();
    void data();

    list1(){
        head=NULL;
        tail=NULL;
    }
};

Node *list1 :: create_node(){
    Node *newNode;
    prev=NULL;
    cur=head;
    newNode=new Node;
    cout<<"Enter member's name: ";
    cin>>newNode->data;
    newNode->link=NULL;
    count1++;
    return(newNode);
}

void list1 :: display(){
    Node *temp;
    temp=head;
    if(temp!=NULL){
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->link;
        }
    }
    else{
        cout<<"List is empty"<<endl;
    }
}

void list1 :: create_list(){
    Node *newNode1;
    char ch='y';
    int choice=1;
    string th1="club";
    string th2;
    string th;
    cout<<"Are you Admin (enter A) or Member (enter M)"<<endl;
    cin>>th2;
    if(th2=="A"|| th2=="a"){
        while(choice==1){
            cout<<"Enter password: ";
            cin>>th;

            if(th==th1){
                while(ch=='y'|| ch=='Y'){
                    newNode1=create_node();
                    if(head==NULL){
                        head=newNode1;
                        tail=newNode1;
                    }
                    else{
                        tail->link=newNode1;
                        tail=newNode1;
                    }
                    cout<<"Do you want to enter more member's names (Y/N): ";
                    cin>>ch;
                }
            }
            else{
                cout<<"Incorrect password"<<endl;
                cout<<"Do you want to continue (1/0): ";
                cin>>choice;
                if(choice==0){
                    exit(0);
                }
            }
            choice=0;
        }
    }
    else{
        cout<<"No authority to enter data"<<endl;
    }
}

void list1 :: operation(){
    int in,ch=1;
    Node *newNode1;
    cout<<'\t'<<"WELCOME TO PINNACLE CLUB"<<'\t'<<endl;
    while(ch){
        cout<<endl;
        cout<<"1.Insert \n2.Delete members \n3.Compute total number of members";
        cout<<"\n4.Display\n5.Display in reverse order \n6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>in;
        
        switch(in){
            case 1:  {
                char ch;
                cout<<"\nAre you Admin (A) or member (M): ";
                cin>>ch;
                if(ch=='A' || ch=='a'){
                    cout<<"\nEnter password to login: ";
                    cin>>ch2;
                    if(ch2==ch1){
                        newNode1=create_node();
                        cout<<"\nEnter the position at which you want to enter: ";
                        cin>>pos;
                        while(count2!=pos){
                            prev=cur;
                            cur=cur->link;
                            count2++;
                        }
                        if(count2==pos){
                                prev->link=newNode1;
                                newNode1->link=cur;
                        }
                        else{
                            cout<<"\nUnable to process"<<endl;
                        }
                    }
                    else{
                        cout<<"\nInvalid password"<<endl;
                    }
                }
                else{
                    cout<<"\nNo authority to insert member"<<endl;
                }
            }
            break;                     

            case 2: {
                string ch1;
                temp=head;
                int count3=0,count4=1;
                cout<<"\nEnter the name you want to delete: ";
                cin>>ch1;
                if(temp!=NULL){
                    while(temp!=NULL){
                        if(temp->data==ch1){
                        count3++;
                            break;
                        }
                        else{
                            temp=temp->link;
                            count3++;
                        }
                    }
                }
                if(count3==1 || count3==count1){
                        cout<<"\nCan not delete trusted members"<<endl;
                        break;
                }
                else{
                    while(count2!=count4){
                        prev=cur;
                        cur=cur->link;
                        count4++;
                    }
                    if(count2==count4){
                        prev->link=cur->link;
                    }
                }
            }
            break;

            case 3: {
                cout<<"\nTotal number of members are: "<<count1<<endl;
            }        
            break;         

            case 4: {
                display();
                break;
            }

            case 5: {
                Node *cur=head;
                Node *prev=NULL;
                Node *link=NULL;
                while(cur!=NULL){
                    link=cur->link;
                    cur->link=prev;
                    prev=cur;
                    cur=link;
                }
                head=prev;
                display();
            }
            break;
                     
            case 6: {
                ch=0;;
            }
            break;
            
            default: 
                cout<<"\nInvalid choice"<<endl;
            break;
        }
    }
}

int main()
{
    list1 obj;
    cout<<"\nWELCOME TO THE PINNACLE CLUB!\n";
    obj.create_list();
    obj.display();
    obj.operation();
    return 0;
}
