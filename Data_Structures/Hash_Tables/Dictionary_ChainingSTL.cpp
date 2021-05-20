// DICTIONARY IMPLEMENTAION USING CHAINING (USING STL - LIST)

/* Chaining Implementation, Where collisions are bound to happen while hasing.
Creating an Array of Linked List.
Using Method,
    hash(key) = Key % (prime number closest to n)
    where, n is the number of keys.
-> whenever, collision occurs insert it at the end of the List of that hash number
*/

#include <iostream>
#include <list>
using namespace std;

class HashTable{
    int HashSize = 7, key;  // Lower Closest Prime Number (To more likely distribute the elements in the table (avoiding clusters and more optimal utilization of space))
    list<pair<int, string>> table[10];

    public:
        int get_key(int);
        void insertItem(int, string);
        void removeItem(int);
        void searchTable(int);
        void printTable(); 
};

int HashTable :: get_key(int rno){
    return int(rno  % HashSize);
}

void HashTable :: insertItem(int rno, string name){
    key = get_key(rno);
    table[key].push_back(make_pair(rno, name));
    cout << "\n[Key & Value Inserted Successfully!]\n";
}

void HashTable :: removeItem(int rno){
    key = get_key(rno);
    for(auto it=table[key].begin(); it!=table[key].end(); it++){
        if(it->first == rno){
            table[key].erase(it);
            cout << "\n[Key & Value Removed Successfully!]\n";
            return;
        }
    }
    cout << "\n[Key Does not Exist]\n";
}

void HashTable :: searchTable(int rno){
    key = get_key(rno);
    for(auto it=table[key].begin(); it!=table[key].end(); it++){
        if(it->first == rno){
            cout << "\n[Key Exists]";
            cout << "\nRoll No. : " << it->first;
            cout << "\nName : " << it->second << "\n";
            return;
        }
    }
    cout << "\n[Key Does not Exist]\n";
}

void HashTable :: printTable(){
    cout << "\nDictionary :\n";
    for(int i=0; i<HashSize; i++){
        for(auto it: table[i]){
            cout << "Roll No. : " << it.first << " Name : " << it.second << "\n";
        }
    }
}

int main(){ 
    HashTable HT;

    cout << "\nDictionary Using Chaining :-\n";
    int t=1, op, temp;
    string name;
    while (t){
        cout << "\nSelect Option :\n1. Insert Key & Value\n2. Delete Key\n3. Search Key\n4. Print Dictionary\n5. Exit\n";
        cin >> op;
        switch (op){
            case 1:
                cout << "\nEnter Student's Roll No. & Name : ";
                cin >> temp >> name;
                HT.insertItem(temp, name);
            break;
            
            case 2:
                cout << "\nEnter Student's Roll No. You Want to Remove : ";
                cin >> temp;
                HT.removeItem(temp);
            break;

            case 3:
                cout << "\nEnter Student's Roll No. You Want to Search : ";
                cin >> temp;
                HT.searchTable(temp);
            break;

            case 4:
                HT.printTable();
            break;
            
            case 5:
                t = 0;
            break;

            default:
                cout << "\n[WARNING: INVALID INPUT]\n";
            break;
        }
    }
    return 0;
}