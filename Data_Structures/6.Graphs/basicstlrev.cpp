#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    cout << "\n";
    // vector<data type> name;
    vector<int> Age;   // Dynamic array: Array that can be modified at runtime.

    int input = 1;

    while(input){
        cout << "Enter Your Age (0 to quit) : ";
        cin >> input;
        if(input){
            Age.push_back(input);
        }    
    }

    cout << "\n\nAges : "; 
    for(int ages = 0; ages < Age.size(); ages++){
        cout << Age[ages] << " ";
    }
    // Sort in Ascending
    sort(Age.begin(), Age.end()); // Quick sort : O(nlogn)
    
    cout << "\n\nAges : "; 
    for(int ages = 0; ages < Age.size(); ages++){
        cout << Age[ages] << " ";
    }

    // Sort in Descending
    sort(Age.begin(), Age.end(), greater<int>()); // greater is comparison function that puts the greater element first.

    cout << "\n\nAges : "; 
    for(int ages = 0; ages < Age.size(); ages++){
        cout << Age[ages] << " ";
    }

    //Binary Search Algorithm : O(logn) [Only works on sorted array]
    sort(Age.begin(), Age.end()); // Quick sort : O(nlogn)

    int find;
    cout << "\n\nEnter Age to Search : ";
    cin >> find;
    if(binary_search(Age.begin(), Age.end(), find)){
        cout << "\nAge Found !";
    }
    else{
        cout << "\nAge Not Found!";
    }
    cout << "\n";
    
    return 0;
}