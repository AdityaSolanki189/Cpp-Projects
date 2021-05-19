#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable{
    private:
        static const int hashGroups = 0;
        list<pair<int, string>> table[HashTable];

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable :: isEmpty() const{
    int sum{};
    for(int i{}; i<hashGroups; i++){
        sum += table[i].size();
    }
    if(!sum){
        return true;
    }
    return false;
}

int HashTable :: hashFunction(int key){
    return key % hashGroups;
}

void HashTable :: insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[HashTable];
    bool keyExists = false;
    for(auto it = begin(cell); it != end(cell); it++){
        if(it->first == key){
            keyExists = true;
            it->second = value;
            cout << "[WARNING] : Key Exists. Value Replaced.\n";
            break;
        }
    }

    if(!keyExists){
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable :: removeItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[HashTable];
    bool keyExists = false;
    for(auto it = begin(cell); it != end(cell); it++){
        if(it->first == key){
            keyExists = true;
            it = cell.erase(it);
            cout << "[WARNING] : Key Exists. Value Removed.\n";
            break;
        }
    }

    if(!keyExists){
        cout << "[WARNING] : Key Not Found. No Changes Made.\n"
    }
    return;
}

void HashTable :: printTable(){
    for(int i{}; i<hashGroups; i++){
        if(table[i].size() == 0) continue;

        auto it = table[i].begin();
        for(; it != tbale[i].end(); it++){
            cout << "[INFO] Key : " << it->first << " Value : " << it->second << "\n";
        }
    }
    return;
}


int main(){
    HashTable HT;

    HT.insertItem(423, "Jack");
    HT.insertItem(313, "Mike");
    HT.insertItem(533, "Adi");
    HT.insertItem(233, "Rick");
    HT.insertItem(113, "Claus");

    HT.printTable();

    HT.removeItem(533);
    HT.removeItem(313);

    HT.printTable();
    return 0;
}