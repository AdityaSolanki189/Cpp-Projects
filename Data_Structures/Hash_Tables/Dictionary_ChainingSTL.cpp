// DICTIONARY IMPLEMENTAION USING CHAINING (USING STL - LIST)
#include <iostream>
#include <list>
using namespace std;

class HashTable{
    int HashSize = 10;
    list<pair<int, string>> table[10];

    public:
        int get_hv(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        void searchTable(int key);
        void printTable(); 
};

int HashTable :: get_hv(int key){
    return int(key  % HashSize);
}

void HashTable :: insertItem(int key, string name){
    int hashValue = get_hv(key);
    table[hashValue].push_back(make_pair(key, name));
    cout << "\n[Key & Value Inserted Successfully!]\n";
}

void HashTable :: removeItem(int key){
    int hashValue = get_hv(key);
    for(auto it=table[hashValue].begin(); it!=table[hashValue].end(); it++){
        if(it->first == key){
            cout << "\n[Key has been Located]\n";
            table[hashValue].erase(it);
            cout << "\n[Key & Value Removed Successfully!]\n";
            return;
        }
    }
    cout << "\n[Key Not Located]\n";
}

void HashTable :: searchTable(int key){
    int hashValue = get_hv(key);
    for(auto it=table[hashValue].begin(); it!=table[hashValue].end(); it++){
        if(it->first == key){
            cout << "\n[Key has been Located]";
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
                cout << "\nEnter Roll No. & Name : ";
                cin >> temp >> name;
                HT.insertItem(temp, name);
            break;
            
            case 2:
                cout << "\nEnter Key You Want to Remove : ";
                cin >> temp;
                HT.removeItem(temp);
            break;

            case 3:
                cout << "\nEnter Key you want to Search : ";
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