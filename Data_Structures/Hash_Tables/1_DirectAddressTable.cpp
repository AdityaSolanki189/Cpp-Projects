/* 
Imagine a situation where you have 1000 keys with values from (0 to 999), how would you implement following in O(1) time Complexity;
1. Search
2. Insert
3. Delete
*/
#include<iostream>
using namespace std;

void insert(int array[], int key){
    if(array[key] == 1) 
        cout << "Key Already Present\n";
    else{
        array[key] = 1;
        cout << key << " Inserted!\n";
    }
}

void remove(int array[], int key){
    if(array[key] == 0) 
        cout << "Key Already Deleted\n";
    else{
        array[key] = 0;
        cout << key << " Deleted!\n";
    }
}

void search(int array[], int key){
    if(array[key] == 1)
        cout << key << " Found!\n";
    else    
        cout << key << " Not Found!\n";
}

int main(){
    int array[1000]={0};
    insert(array, 10);
    insert(array, 20);
    insert(array, 119);
    search(array, 10);
    search(array, 20);
    remove(array, 119);
    search(array, 119);
    return 0;
}

// Problem with this approach, cannot handle large numbers like 10digit phone numbers
// Problems with string values like names, employee ids etc.