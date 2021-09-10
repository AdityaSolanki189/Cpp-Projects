/* There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)).

Example :
Input:  arr1[] = {1, 12, 15, 26, 38}
        arr2[] = {2, 13, 17, 30, 45}
Output: 16
Explanation: After merging two arrays, we get {1, 2, 12, 13, 15, 17, 26, 30, 38, 45}. Middle two elements are 15 and 17. Thus, the average of the middle elements is (15+17)/2 which is equal to 16. */

#include<bits/stdc++.h>
using namespace std;

int get_Median1(int arr1[], int arr2[], int n){
    int i=0, j=0, count=0;
    int m1 = -1, m2 = -1;

    for(count = 0;count <= n;count++){
        //all elements of arr1[] < arr2[0]
        if(i == n){
            m1 = m2;
            m2 = arr[2];
            break; 
        }
        //all elements of arr2[] < arr1[0]
        else if(j == n){
            m1 = m2;
            m2 = arr1[0];
            break;
        }
        // = sign for common elements of arr1[] & arr2[]
        if(arr1[i] <= arr2[j]){ // median 1
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else{ // median 2
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
    }
    return (m1+m2)/2;
}

int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

// Complex Comparing Method (DnC Approach)
int get_median2(int arr1[], int arr2[], int n){ 
    if (n <= 0)
        return -1;
    if (n == 1)
        return (arr1[0] + arr2[0]) / 2;
    if (n == 2)
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;

    int m1 = median(arr1, n); 
    int m2 = median(arr2, n);

    if (m1 == m2) return m1;

    if (m1 < m2){
        if (n % 2 == 0)
            return getMedian(arr1 + n / 2 - 1, arr2, n - n / 2 + 1);
        return getMedian(arr1 + n / 2, arr2, n - n / 2);
    }

    if (n % 2 == 0)
        return getMedian(arr2 + n / 2 - 1, arr1, n - n / 2 + 1);
    return getMedian(arr2 + n / 2, arr1, n - n / 2);
}

int main(){
    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for(int i=0;i<n;i++) cin >> arr1[i];
    for(int i=0;i<n;i++) cin >> arr2[i];

    // Simple Merging method O(n) Time Complexity
    cout << get_Median1(arr1, arr2, n); 

    // Comparing Medians Method O(logn) Time Complexity
    // Divide and Conquer approach
    cout << get_median2(arr1, arr2, n);

    return 0;
}

//https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

