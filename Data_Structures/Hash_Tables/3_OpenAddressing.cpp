/* 
    Open Addressing Implementation, using a single array.
    req,
    No. of Slots in Hash Table >= No. of keys to be Inserted
    Cache Friendly (no. pointers or such)

    Linear Probing -> Linearly search (in a circular manner) for the next empty slot in case of collision in the Array.It is a Circular array traversal.

    Problem Occured - During Linear Probing - Primary Clustering
        -> h(key) = (h(key) + i) % 7

    How to handle Clustering problem with Linear Probing ?
    1. Quadratic Probing - still causing secondary clusters
        -> hash(key, i) = (h(key) + i^2) % m, 
        -> load factor < 0.5 & m is a prime

    2. Double Hashing - No Clustering Issue, gauranteed finds free slot
        -> hash(key) = (h1(key) + i*h2(key)) % m, i = 0 initially
        -> h1(key) = (key % 7)
        -> h2(key) = 6 - (key % 6)
        -> The value of i will increase each probe, as there are collisions
        -> distributes keys more uniformly as there are no clustering
        -> h2(key) and m should be relatively prime
*/

#include<iostream>
using namespace std;

struct MyHash{
    int *arr;   // dynamic array
    int cap, size;
    
    MyHash(int c){
        cap = c;
        size = 0;
        arr = new int[cap];
        for(int i=0; i<cap; i++){
            arr[i] = -1;
        }    
    }
    
    int hash(int key){
        return key % cap;    // hash(key) = key % 7 
    }

    bool insert(int key){
        // return true if key is inserted else false
        if(size == cap)
            return false;

        int i = hash(key);

        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key){
            i = (i+1)%cap;
        }    
        if(arr[i] == key)
            return false;
        else{
            arr[i] = key;
            size++;
            return true;
        }
    }

    bool search(int key){
        int h = hash(key);
        int i = h;  // begin from the hash index for the key
        while(arr[i] != -1){   // traverse till hash table is empty
            if(arr[i] == key)
                return true;

            i = (i+1) % cap;

            if(i == h)   // returning back to the beginning after one loop
                return false;
        }
        return false;
    }
    
    bool erase(int key){   
        int h = hash(key);
        int i = h;
        while(arr[i] != -1){
            if(arr[i] == key){
                arr[i] = -2;
                return true;
            }
            i = (i+1) % cap;
            if(i == h)
                return false;
        }
        return false;
    }
};

int main(){
    MyHash mh(7);
    cout << mh.insert(49);
    cout << mh.insert(56);
    cout << mh.insert(72);

    if(mh.search(56) == true)
        cout << "Yes\n";
    else
        cout << "No\n";
    
    cout << mh.erase(56);
    
    if(mh.search(56) == true)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}


/* Problem : We have used -1 and -2 keys to indicate empty slot and deleted slot respectively. So what happends when -1 and -2 are the keys which are input by the user?

Solution: Using pointers/references. Delete function in library functions use a Dummy node when we delete a slot to indicate deleted.  */
