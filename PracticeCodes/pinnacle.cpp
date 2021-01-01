#include <iostream>
using namespace std;

struct Node{
    string data;
    Node *link;
};

class list1{
public:
    int pos, count1 = 0, count2 = 0;
    string ch1 = "club";
    string ch2, ch;

    Node *head, *tail, *prev, *cur, *temp;
    Node *create_node();

    void create_list();
    void operation();
    void display();
    void data();

    list1()
    {
        head = NULL;
        tail = NULL;
    }
};

Node *list1 ::create_node(){
    Node *newNode;
    prev = NULL;
    cur = head;
    newNode = new Node;
    cout << "Enter member's name: ";
    cin >> newNode->data;
    newNode->link = NULL;
    count1++;
    return (newNode);
}

void list1 ::display(){
    Node *temp;
    temp = head;
    if (temp != NULL)    {
        while (temp != NULL)    {
            cout << temp->data << endl;
            temp = temp->link;
        }
    }
    else    {
        cout << "List is empty" << endl;
    }
}

void list1 ::create_list(){
    Node *newNode1;
    char ch = 'y';
    int choice = 1;
    string th1 = "club";
    string th2;
    string th;
    cout << "Are you Admin (enter A) or Member (enter M)" << endl;
    cin >> th2;
    if (th2 == "A" || th2 == "a")    {
        while (choice == 1)    {
            cout << "Enter password: ";
            cin >> th;

            if (th == th1)    {
                while (ch == 'y' || ch == 'Y')    {
                    newNode1 = create_node();
                    if (head == NULL)    {
                        head = newNode1;
                        tail = newNode1;
                    }
                    else    {
                        tail->link = newNode1;
                        tail = newNode1;
                    }
                    cout << "Do you want to enter more member's names (Y/N): ";
                    cin >> ch;
                }
            }
            else    {
                cout << "Incorrect password" << endl;
                cout << "Do you want to continue (1/0): ";
                cin >> choice;
                if (choice == 0)    {
                    exit(0);
                }
            }
            choice = 0;
        }
    }
    else{
        cout << "No authority to enter data" << endl;
    }
}

void list1 ::operation(){
    int in, ch = 1;
    Node *newNode1;
    cout << '\t' << "WELCOME TO PINNACLE CLUB" << '\t' << endl;
    while (ch)    {
        cout << endl;
        cout << "1.Insert \n2.Delete members \n3.Compute total number of members \n4.Display" << endl;
        cout << "5.Display in reverse order \n6.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> in;
        cout << endl;

        switch (in)    {
            case 1:
        
            char ch;
            cout << "Are you Admin (A) or member (M): ";
            cin >> ch;
            if (ch == 'A' || ch == 'a')
            {
                cout << "Enter password to login: ";
                cin >> ch2;
                if (ch2 == ch1)
                {
                    newNode1 = create_node();
                    cout << "Enter the position at which you want to enter: ";
                    cin >> pos;
                    while (count2 != pos)
                    {
                        prev = cur;
                        cur = cur->link;
                        count2++;
                    }
                    if (count2 == pos)
                    {
                        prev->link = newNode1;
                        newNode1->link = cur;
                    }
                    else
                    {
                        cout << "Unable to process" << endl;
                    }
                }
                else
                {
                    cout << "Invalid password" << endl;
                }
            }
            else
            {
                cout << "No authority to insert member" << endl;
            }
            break;
        

            case 2:
        
            string ch1;
            temp = head;
            int count3 = 0, count4 = 1;
            cout << "Enter the name you want to delete: ";
            cin >> ch1;
            if (temp != NULL)
            {
                while (temp != NULL)
                {
                    if (temp->data == ch1)
                    {
                        count3++;
                        break;
                    }
                    else
                    {
                        temp = temp->link;
                        count3++;
                    }
                }
            }

            if (count3 == 1 || count3 == count1)
            {
                cout << "Can not delete trusted members" << endl;
                break;
            }
            else
            {
                while (count2 != count4)
                {
                    prev = cur;
                    cur = cur->link;
                    count4++;
                }
                if (count2 == count4)
                {
                    prev->link = cur->link;
                }
            }
            break;
        

            case 3:
        
            cout << "Total number of members are: " << count1 << endl;
            break;
        

            case 4:
        
            display();
            break;
        

            case 5:
        
            Node *cur = head;
            Node *prev = NULL;
            Node *link = NULL;
            while (cur != NULL)
            {
                link = cur->link;
                cur->link = prev;
                prev = cur;
                cur = link;
            }
            head = prev;
            display();
            break;
        

            case 6:
        
            exit(0);
            break;
        

            default:
        
            cout << "Invalid choice" << endl;
            break;
        

            cout << "Do you want to continue (1/0)" << endl;
            cin >> ch;
        }
    }
}

int main(){
    list1 obj;
    cout << '\n\t' << "Welcome to pinnacle club" << '\t\n' << endl;
    obj.create_list();
    obj.display();
    obj.operation();
    return 0;
}
