/* Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, in O(log n + log m) time complexity, when n is the number of elements in the first array, and m is the number of elements in the second array.
This is an extension of median of two sorted arrays of equal size problem. Here we handle arrays of unequal size also. 
Example: 
Input: ar1[] = {-5, 3, 6, 12, 15}
        ar2[] = {-12, -10, -6, -3, 4, 10}
Output : The median is 3.
Explanation : The merged array is :
        ar3[] = {-12, -10, -6, -5 , -3,
                 3, 4, 6, 10, 12, 15},
       So the median of the merged array is 3

Input: ar1[] = {2, 3, 5, 8}
        ar2[] = {10, 12, 14, 16, 18, 20}
Output : The median is 11.
Explanation : The merged array is :
        ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
        if the number of the elements are even, 
        so there are two middle elements,
        take the average between the two :
        (10 + 12) / 2 = 11.
*/

#include<bits/stdc++.h>
using namespace std;

/* Linear and simpler approach.
Time Complexity: O(m + n). 
To merge both the arrays O(m+n) time is needed.
Space Complexity: O(1). 
No extra space is required. */
int get_median1(int arr1[], int arr2[], int n, int m){
    int i = 0, j = 0, count; 
    int m1 = -1, m2 = -1; 

    if((m + n) % 2 == 1) { 
        for (count = 0; count <= (n + m)/2; count++){ 
            if(i != n && j != m) { 
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++]; 
            } 
            else if(i < n){ 
                m1 = ar1[i++]; 
            }
            else{ 
                m1 = ar2[j++]; 
            } 
        } 
        return m1; 
    } 
    else { 
        for (count = 0; count <= (n + m)/2; count++) { 
            m2 = m1; 
            if(i != n && j != m){ 
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++]; 
            } 
            else if(i < n){ 
                m1 = ar1[i++]; 
            } 
            else{ 
                m1 = ar2[j++]; 
            } 
        } 
        return (m1 + m2)/2; 
    }  
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    for(int i=0;i<n1;i++) cin >> arr1[i];
    for(int i=0;i<n2;i++) cin >> arr2[i];
        
    cout << get_Median1(arr1, arr2, n1, n2); 

    return 0;
}