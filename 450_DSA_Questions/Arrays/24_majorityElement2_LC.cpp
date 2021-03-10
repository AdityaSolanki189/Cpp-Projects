/* Given an integer array of size n, find all elements that appear more than [n/3] or [n/2] times.
Given an array of size n and a number k, find all elements that appear more than " n/k " times.
Follow-up: Could you solve the problem in linear time and in O(1) space?
Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1] */

#include<bits/stdc++.h>
using namespace std;

void get_output(vector<int> &array, int n, int k){
    sort(array.begin(), array.end());
    int t = n/k;

    unordered_map<int, int> freq;

    for(int i=0;i<n;i++){
        freq[array[i]]++;
    }
    // first -> key/element
    // second -> count/frequency of the key 
    for(auto i:freq){
        if(i.second > t){
            cout << i.first << " ";
        }
    }
}

int main(){
    int num, val=0, k;
    cin >> num >> k;
    vector<int> array;
    for(int i=0;i<num;i++) {
        cin >> val;
        array.push_back(val);
    }
    get_output(array, num, k);

    return 0;
}

/* // A structure to store an element and its current count
struct eleCount {
    int e; // Element
    int c; // Count
};
 
// Prints elements with more 
// than n/k occurrences in arr[]
// of size n. If there are no 
// such elements, then it prints
// nothing.
void moreThanNdK(int arr[], int n, int k)
{
    // k must be greater than
    // 1 to get some output
    if (k < 2)
        return;
 
    // Step 1: Create a temporary array of size k-1. 
    // Initialize count of all
    // elements as 0 
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;
 
    // Step 2: Process all elements of input array 
    for (int i = 0; i < n; i++) 
    {
        int j;
 
        // If arr[i] is already present in
        //   the element count array, 
        //   then increment its count

        for (j = 0; j < k - 1; j++) 
        {
            if (temp[j].e == arr[i]) 
            {
                temp[j].c += 1;
                break;
            }
        }
 
        // If arr[i] is not present in temp[]
        if (j == k - 1) {
            int l;
 
            // If there is position available 
            // in temp[], then place arr[i] in 
            // the first available position and 
            // set count as 1
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].c == 0) 
                {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }
 
            // If all the position in the 
            // temp[] are filled, then decrease 
            // count of every element by 1 
            if (l == k - 1)
                for (l = 0; l < k; l++)
                    temp[l].c -= 1;
        }
    }
 
    //Step 3: Check actual counts of potential candidates in temp[]
    for (int i = 0; i < k - 1; i++)
    {
        // Calculate actual count of elements
        int ac = 0; // actual count
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;
 
        // If actual count is more than n/k,
       // then print it
        if (ac > n / k)
            cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
    }
} */