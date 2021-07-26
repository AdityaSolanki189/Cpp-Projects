#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

struct Pair{
    string name;
    ll ph_no;
};

class HashMap{
    Pair dir[10];
    int size;

    public:
    HashMap(int size){
        this->size = size;

        for(int i=0;i<10;i++){
            dir[i].ph_no = 0;
            dir[i].name = "";
        }
    }

    void insert_Info(string name, ll number){
        ll sum;
        int hashvalue=0, end_point;
        for(int i=0; i<name.length(); i++){
            sum += name[i];
        }
            
        hashvalue = (sum/name.length())%size;
        end_point = hashvalue;

        while(true){

            if(dir[hashvalue].ph_no == 0){
                dir[hashvalue].name = name;
                dir[hashvalue].ph_no = number;
                break;
            }

            hashvalue = (hashvalue+1)%size;
            
            if(hashvalue == end_point){
                cout << "\nHash table is FULL.";
                break;
            }
        }
    }

    void search_dir(string name){
        ll sum;

        int hashvalue,end_point;

        for(int i=0; i<name.length(); i++){
            sum += name[i];
        }
        
        hashvalue = (sum/name.length())%size;
        end_point = hashvalue;

        while(true){
            if(dir[hashvalue].name == name){
                cout << "\nNumber Found : "<<dir[hashvalue].ph_no << endl;
                break;
            }

            hashvalue = (hashvalue+1)%size;

            if(hashvalue == end_point){
                cout << "\nNot Found!";
                break;
            }
        }
    }

    void display(){
        cout << "\tName\t|\tPhone Number\n";
        for(int i=0; i<size; i++){
            cout << "\t" << dir[i].name << "\t\t" << dir[i].ph_no << "\n"; 
        }
    }

};



int main() {

    string Name;
    ll phNumber;
    int size, choice;
    cout << "\n    ##  Telephone Directory  ##\n";
    cout << "\nEnter Telephone Book Size : ";
    cin >> size;

    HashMap Dir(size);

    while(1){
        cout << "\nSelect an Option : ";
        cout << "\n1. Insert Information\n2. Find a Phone Number\n3. Display the Table\n4. Exit";
        cout << "\nEnter : ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "\nEnter the Details :";
                for(int i=0; i<size; i++){
                    cin.ignore();
                    cout << "\nEnter the Name (All Caps.) : ";
                    getline(cin, Name);
                    cout << "Enter Phone Number : ";
                    cin >> phNumber;

                    Dir.insert_Info(Name, phNumber);
                    cout << "[Data added to Directory]\n";
                }
            break;
            
            case 2:
                cin.ignore();
                cout << "\nEnter the Name of the Phone Number Holder : ";
                getline(cin, Name);
                Dir.search_dir(Name);       
            break;

            case 3:
                cout << "\nThe Telephone Directory : \n";
                Dir.display();
            break;
            
            case 4:
                return 0;
            break;

            default:
                cout << "\nEnter Valid Input.";
            break;
        }
    }       

	return 0;
}