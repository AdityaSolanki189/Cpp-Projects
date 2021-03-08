/* Rearrange array in alternating positive & negative items with O(1) extra space.
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

Examples : 
Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}  */

#include<bits/stdc++.h>
using namespace std;

void arrange_alternate(int array[], int n){
    int negative=0,positive=1,i=0;
    // check for negative no. at even index (0,2,4...)
    while(i < n){
        if(array[i] < 0 && negative < n){
            swap(array[i],array[negative]);
            negative += 2;
        }
        i++;
    }
    i = 0;

    // check for positive no. at odd index (1,3,5...)
    while(i < n){
        if(array[i] >= 0 && positive < n){
            swap(array[i], array[positive]);
            positive += 2;
        }
        i++;
    }
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];

    arrange_alternate(array,n);

    cout << "Output Array : ";
    for(int i=0;i<n;i++) cout << array[i] << " ";

    return 0;
}
/* 
Another Approach.

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
 
void rearrange(int arr[], int n)
{
    int outofplace = -1;
 
    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is negative then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
            // -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            
            if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);
 
                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
 
        // if no entry has been flagged out-of-place
        if (outofplace == -1) {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    }
} 
*/