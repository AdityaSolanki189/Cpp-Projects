#include<fstream> 
#include<iostream> 
#include<iomanip> 
#include<string.h>
#define SIZE 10     
using namespace std;

struct student{
    int rollno;             
    char name[20];
    float marks;
    int status;
    int link;
};

class linear_probe{
    char table[30];     
    fstream tab;
    student rec;
    
    public:
        linear_probe();
        void displayall();
        void insert(student);    
        int search(int);
        void display(int);
        void read(int);
        void write(int);
        int modify(int);
};

linear_probe::linear_probe(){
    int i;
    cout<<"\nEnter Filename : ";           
    cin>>table;
    rec.status = 1;
    rec.link = -1;
    tab.open(table, ios::binary | ios::out);    
    tab.close();                                   
    for(i=0; i<SIZE; i++)                                
        write(i);
}

void linear_probe::displayall(){
    int i =1;
    cout<<"SrNo.\tRoll No.\tName\tMarks\n";
    for(i = 0; i< SIZE; i++)
        display(i);
    cout<<"\n";
}

void linear_probe::insert(student s){ 
    int n, i, j, start, k;       
    s.status = 0;           
    s.link = -1;
    start = s.rollno % SIZE;  
    
    for(i =0; i< SIZE; i++){
        j = (start + i)% SIZE; 
        read(j);
        if(rec.status == 0 && (rec.rollno % SIZE) == start) 
            break;
    }

    if(i < 10){
        while(rec.link != -1){
            j = rec.link;
            read(j);
        }

        for(i=0; i< SIZE; i++){
            k = (start + i)%SIZE; 
            read(k);
            if(rec.status){
                rec = s;          
                write(k);
                read(j);
                rec.link = k;
                write(j);
                return;
            }
        }

        cout<<"\nTable is FULL!"; 
    }
    else{
        for(i=0; i< SIZE; i++){
            k = (start + i)%SIZE;
            read(k);
            if(rec.status){
                rec = s;
                write(k);
                return;
            }
        }

        cout<<"\nTable is FULL!";
    }
}

int linear_probe::search(int rno){
    int start, i, j;
    start = rno % SIZE;
    
    for(i =0; i< SIZE; i++){
        j = (start + i)% SIZE;
        read(j);
        if(rec.status == 0 && (rec.rollno % SIZE) == start)
            break;
    }
    
    if(i < 10){
        while(rec.rollno != rno && rec.link != -1){
            j = rec.link;
            read(j);
        }
        
        if(rec.rollno == rno)
            return j;           
        else
            return -1;          
    }
    else
        return -1;
}
void linear_probe::display(int rno){
    int i = rno;
    tab.open(table, ios::binary | ios::in);
    tab.seekg(rno*sizeof(student), ios::beg);  
    tab.read((char*)&rec,sizeof(student)); 

    if(rec.status == 0){
        cout<<i<<"\t"<<rec.rollno<<"\t\t"<<rec.name<<"\t"<<rec.marks<<"\t"<<rec.link<<"\n";
    }
    
    else
        cout<<i<<"\t|-------------Empty-------------|\n";
    tab.close();
}

void linear_probe::read(int rno){
    tab.open(table, ios::binary | ios::in);
    tab.seekg(rno * sizeof(student), ios::beg);
    tab.read((char*)&rec, sizeof(student));
    tab.close();
}

void linear_probe::write(int rno){
    tab.open(table, ios::binary | ios::in | ios::out);
    tab.seekp(rno * sizeof(student), ios::beg);
    tab.write((char*)&rec, sizeof(student));
    tab.close();
}

int linear_probe::modify(int rno){
    int start, i, j;
    start = rno % SIZE;
    
    for(i =0; i< SIZE; i++){
        j = (start + i)% SIZE;
        read(j);
        if(rec.status == 0 && (rec.rollno % SIZE) == start)
            break;
    }
    
    if(i < 10){
        while(rec.rollno != rno && rec.link != -1){
            j = rec.link;
            read(j);
        }
        
        if(rec.rollno == rno){
            tab.open(table, ios::binary | ios::in | ios::out);
            tab.seekg(rno * sizeof(student), ios::beg);
            cout<<"\nEnter modifeied details: ";
            cout<<"\nEnter Roll Number : ";
            cin >>rec.rollno;
            cout<<"Enter Name : ";
            cin >>rec.name;
            cout<<"Enter Marks : ";
            cin >>rec.marks;
            tab.write((char*)&rec, sizeof(student));
            tab.close();
            cout<<"\nRecord Modified Successfully.\n";
            return j;
        }
        
        else
            return -1;
    }
    else
        return -1;
}

int main(){
    int choice, rno, check;
    student rs;
    linear_probe lp;
    
    while(1){
        cout<<"\n   # File Operations # ";
        cout<<"\n1. Create Database";
        cout<<"\n2. Display Database";
        cout<<"\n3. Add a Record";
        cout<<"\n4. Search a Record";
        cout<<"\n5. Modify a Record";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\nEnter the Following Details :- ";
                    cout<<"\nEnter Roll Number : ";
                    cin >>rs.rollno;
                    cout<<"Enter Name : ";
                    cin >>rs.name;
                    cout<<"Enter Marks : ";
                    cin >>rs.marks;
                    lp.insert(rs);
                    break;
            case 2: lp.displayall();
                    break;
            case 3: cout<<"\nEnter details: ";
                    cout<<"\nEnter Roll Number : ";
                    cin >>rs.rollno;
                    cout<<"Enter Name : ";
                    cin >>rs.name;
                    cout<<"Enter Marks : ";
                    cin >>rs.marks;
                    lp.insert(rs);
                    break;
            case 4: cout<<"\nEnter Roll Number to be Searched : ";
                    cin>>rno;
                    check = lp.search(rno);
                    if(check >= 0){
                        cout<<"\nRecord Number : "<<check;
                        lp.display(check);
                        cout<<"\n";
                    }
                    else
                        cout<<"\nRecord NOT FOUND!";
                    break;
            case 5: cout<<"\nEnter Roll Number to be Modified : ";
                    cin>>rno;
                    check = lp.modify(rno);
                    if(check >= 0){
                        cout<<"\nRecord Number : "<<check;
                        lp.display(check);
                    }
                    else
                        cout<<"\nRecord NOT FOUND!";
                    break;
            case 6: return 0;
        }
    }
    return 0;
}
