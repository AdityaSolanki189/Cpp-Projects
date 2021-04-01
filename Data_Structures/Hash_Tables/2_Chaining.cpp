/* Chaining Implementation, Where collisions are bound to happen while hasing.
Creating an Array of Linked List.
Using Method,
    hash(key) = Key % (prime number closest to n)
    where, n is the number of keys.
-> whenever, collision occurs insert it at the end of the List of that hash number
*/
#include<iostream>
#include<list>
using namespace std;

struct MyHash{
    int bucket;
    list<int> *table;
    MyHash(int b){
        bucket = b;
        table = new list<int> [b];
    }

    void insert(int key){
        int i = key % bucket;
        table[i].push_back(key);
    }

    bool search(int key){
        int i = key % bucket;
        for(auto x: table[i]){
            if(x == key)
                return true;
        }
        return false;
    }

    void remove(int key){
        int i = key % bucket;
        table[i].remove(key);
    }
};


int main(){
    MyHash mh(7);  // setting bucket size to be 7
    mh.insert(10); // inserting our first key hash table(bucket)
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << "\n";
    mh.remove(15);
    cout << mh.search(15) << "\n";

    return 0;
}

/* 
    # Performance of Chaning,
        m = No. of slots in Hash Table
        n = No. of keys to be inserted
        Load Factor (∝) = n/m   (we want the load factor to be Small)
        Expected Chain Length = ∝
        Expected Time to Search = O(1 + ∝)
        Expected Time to Insert/Delete = O(1 + ∝)

    # Different Data Structures used for Storing Chains,
        1. Linked List -> TC. O(l) l, chain length 
            not cache friendly (nodes are at different locations),
            it uses extra space for storing pointers/references

        2. Dynamic sized Array (Vector) -> TC. O(l)
            cache friendly (continuos locations)
        
        3. Self Balancing BST (AVL trees, Red Black Trees) -> TC. O(logl)
            not cache friendly
*/