/* Merge Without Extra Space 
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.  */ 

#include<bits/stdc++.h>
using namespace std;

int nextGap(int gap){
    if (gap <= 1){
        return 0;
    }
    return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int n, int m) {
	    
	int gap = n + m;
	int i, j;
	
	gap = nextGap(gap);
	for(; gap > 0 ; gap = nextGap(gap) ){
		
	    //Comparing elements in first array arr1[]
	    for(i = 0; i + gap < n; i++){
	        if(arr1[i] > arr1[i+gap])
	     	   swap(arr1[i], arr1[i+gap]);
	    }

	    //Comparing elements in both array arr1[] and arr2[]
	    for(j = (gap > n) ? (gap - n) : 0; i < n && j < m; i++, j++ ){
	        if(arr1[i] > arr2[j])
	            swap(arr1[i], arr2[j]);
	    }
	      
	    //Comparing elements in second array arr2[]
	    if(j < m){
	        for(j = 0; j + gap < m; j++){
	            if(arr2[j] > arr2[j + gap])
	                swap(arr2[j], arr2[j+gap]);
	        }
	    }
	}
}

int main() {
	int n,m,i,j;
	cin >> n >> m;
	int arr1[n], arr2[m];
	for(i=0;i<n;i++) cin >> arr1[i];
	for(i=0;i<m;i++) cin >> arr2[i];
	    
	/* Method 2: 
	int ptr1 = n-1, ptr2=0;
	while(ptr1>=0 && ptr2<m){
        if(arr1[ptr1]>arr2[ptr2]){
	        swap(arr1[ptr1], arr2[ptr2]);
	    }
	    ptr1--;
	    ptr2++;
	}
	sort(arr1,arr1+n);
    sort(arr2,arr2+m);
	    
	for(i=0;i<n;i++) cout << arr1[i] << " ";
	cout << endl;
	for(i=0;i<m;i++) cout << arr2[i] << " "; */

	merge(arr1,arr2,n,m);

	for(i=0;i<n;i++) cout << arr1[i] << " ";
	cout << endl;
	for(i=0;i<m;i++) cout << arr2[i] << " ";

	return 0;
}