/* Company maintains employee information as employee ID, name, designation and salary. 
Allow user to add, delete information of employee. Display information of particular employee. 
If employee does not exist an appropriate message is displayed. If it is, then the system displays 
the employee details. Use sequential file to maintain the data.*/


#include <iostream>  
#include <fstream>   
#include <iomanip>   
#define SIZE 100
using namespace std;

class Employee{
    private:
        int empno;        
        int salary;
        char name[SIZE];
        char designation[SIZE];

    public:
        void accept();      
        void display();     
        void modify();      
        int geteno();      
};                    

void Employee::accept(){
    cout << "Enter the Employee's ID : ";
    cin >> empno;
    cin.ignore();
    cout << "Enter the Name of the Employee : ";
    cin.getline(name, SIZE);
    cout << "Enter the Employee's Designation : ";
    cin.getline(designation, SIZE);
    cout << "Enter the Employee's salary : ";
    cin >> salary;
}

void Employee::display(){
    cout << "\t"<<empno<<"\t\t"<<name<<"\t\t"<<designation<<"\t\t"<<salary<<"\n";
}

void Employee::modify(){
    cin.ignore();
    cout << "Enter new name of Employee : ";
    cin.getline(name, SIZE);
    cout << "Enter the new Designation of the Employee : ";
    cin.getline(designation, SIZE);
    cout << "Enter the new salary:- ";
    cin >> salary;
}

int Employee::geteno(){
    return empno;
}

int create(int);
void display(int);
int add(int);
void deleterec(int);
void modifyrec(int);

int main(){
    int choice, i, flag, cntr = 0;

    while (1){
        cout << "\nEmployees Database" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Add" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Modify" << endl;
        cout << "6. Exit program" << endl;
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice){
            case 1:{
                cntr = create(cntr);
                break;
            }

            case 2:{
                display(cntr);
                break;
            }

            case 3:{
                if (cntr == 0)
                    cout << "\n[Please build a master table first]" << endl;
                else
                    cntr = add(cntr);
                break;
            }

            case 4:{
                if (cntr == 0)
                    cout << "\n[Please build a master table first]" << endl;
                else
                    deleterec(cntr);
                break;
            }

            case 5:{
                if (cntr == 0)
                    cout << "\n[Please build a master table first]" << endl;
                else
                    modifyrec(cntr);
                break;
            }

            case 6:{
                cout << "\n[Program Terminated]\n";
                return 0;
                break;
            }
            default:
                cout << "Error in choice,try again!" << endl;
        }
    }
    return 0;
}

int create(int cntr){
    int eno;
    Employee m;
    ofstream fout("recs.dat", ios::binary | ios::out);  //Write into file 'recs.dat' in binary format
    cntr = 0;
    char ask = 'y';
    while (ask == 'y' || ask == 'Y'){
        m.accept();
        fout.write((char *)&m, sizeof(m));
        cntr++;
        cout << "\nDo you want to add another record?(y/n):- ";
        cin >> ask;
    }
    fout.close();
    return cntr;
}

void display(int cntr){
    int i;
    Employee m;
    if (cntr == 0)
        cout << "\nPlease build a master table first" << endl;
    else{
        ifstream fin("recs.dat", ios::binary | ios::in);  //Read file 'recs.dat' data in binary format
        cout << "\n-----------------------------------------------------------------" << endl;
        cout << "\tEmployee ID "<< "\tName " << "\t\tDesignation " << "\tSalary \n";
        cout << "\n-----------------------------------------------------------------" << endl;
        i = 1;
        while (fin.read((char *)&m, sizeof(m)))
        {
            cout << "  " << i << "  ";
            m.display();
            i++;
        }
        fin.close();
    }
}

int add(int cntr){
    Employee m;
    ofstream fout("recs.dat", ios::binary | ios::app);
    cout << "Enter the Following Details : \n";
    m.accept();
    fout.write((char *)&m, sizeof(m));      //Write into file 'recs.dat' in binary format
    fout.close();
    cntr++;
    cout << "\n[Record Inserted Successfully]\n";
    return cntr;
}

void deleterec(int cntr){
    Employee m;
    int flag;
    int eno;
    ifstream fin("recs.dat", ios::binary | ios::in);    //Read file 'recs.dat' data in binary format
    cout << "Enter the Employee ID of the Record you want to Delete : ";
    cin >> eno;
    flag = 0;

    while (fin.read((char *)&m, sizeof(m))){     //Traverse through all the records.
        if (eno == m.geteno()){
            flag = 1;
            cntr--;
            break;
        }
    }

    fin.close();

    if (!flag)
        cout << "\n[Record with Employee ID " << eno << " NOT FOUND]" << endl;
    else{
        ofstream fout("temp.dat", ios::binary | ios::out);      //Create a Temparary Binary File to Write on.
        ifstream fin("recs.dat", ios::binary | ios::in);       //Read file 'recs.dat' data in binary format.
        fin.seekg(0, ios::beg);
        fin.read((char *)&m, sizeof(m));

        while (!fin.eof()){         //While Traversing the File till End of File
            if (m.geteno() != eno)
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();

        cout << "\n[Record with Employee ID " << eno << " has been DELETED Successfully]" << endl;
        remove("recs.dat");                 //old file with deleted record
        rename("temp.dat", "recs.dat");     //new file without the deleted record
    }
}

void modifyrec(int cntr){
    Employee m;
    int eno;
    int flag;
    ifstream fin("recs.dat", ios::binary | ios::in); 
    cout << "Enter the Employee ID of the Record you want to Modify : ";
    cin >> eno;
    flag = 0;

    while (fin.read((char *)&m, sizeof(m))){
        if (eno == m.geteno()){
            flag = 1;
            cntr--;
            break;
        }
    }
    fin.close();

    if (!flag)
        cout << "\n[Record with Employee ID " << eno << " NOT FOUND]" << endl;
    else{
        ofstream fout("temp.dat", ios::binary | ios::out);
        ifstream fin("recs.dat", ios::binary | ios::in);
        fin.read((char *)&m, sizeof(m));
        while (!fin.eof()){
            if (m.geteno() == eno){
                m.modify();
                fout.write((char *)&m, sizeof(m));
            }
            else
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();
        cout << "\n[Record with Employee ID " << eno << " has been MODIFIED Successfully]" << endl;
        remove("recs.dat");                 //Old file with Old Record Information
        rename("temp.dat", "recs.dat");     //New file with Modified Record Information
    }
}