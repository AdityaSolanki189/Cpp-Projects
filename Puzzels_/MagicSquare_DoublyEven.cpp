/* Magic Square Fill the n × n table with n^2 distinct integers from 1 to n^2 so that the sum of the numbers in each row, column, and corner-to-corner diagonal is the same. */
//This program works only for EVEN values of n. (ex.4,8,12,16,20...)

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
using namespace std;
  
void doublyEven( int n ) {  
    int arr[n][n], i, j; 
  
    // filling matrix with its count value  
    // starting from 1; 
    for ( i = 0; i < n; i++) 
        for ( j = 0; j < n; j++) 
            arr[i][j] = (n*i) + j + 1; 
       
    // change value of Array elements 
    // at fix location as per rule  
    // (n*n+1)-arr[i][j] 
    // Top Left corner of Matrix  
    // (order (n/4)*(n/4)) 
    for ( i = 0; i < n/4; i++) 
        for ( j = 0; j < n/4; j++) 
            arr[i][j] = (n*n + 1) - arr[i][j]; 
     
    // Top Right corner of Matrix  
    // (order (n/4)*(n/4)) 
    for ( i = 0; i < n/4; i++) 
        for ( j = 3 * (n/4); j < n; j++) 
            arr[i][j] = (n*n + 1) - arr[i][j]; 
      
    // Bottom Left corner of Matrix 
    // (order (n/4)*(n/4)) 
    for ( i = 3 * n/4; i < n; i++) 
        for ( j = 0; j < n/4; j++) 
            arr[i][j] = (n*n+1) - arr[i][j]; 
     
    // Bottom Right corner of Matrix  
    // (order (n/4)*(n/4)) 
    for ( i = 3 * n/4; i < n; i++) 
        for ( j = 3 * n/4; j < n; j++) 
            arr[i][j] = (n*n + 1) - arr[i][j]; 
    
    // Centre of Matrix (order (n/2)*(n/2)) 
    for ( i = n/4; i < 3 * n/4; i++) 
        for ( j = n/4; j < 3 * n/4; j++) 
            arr[i][j] = (n*n + 1) - arr[i][j]; 
    
    cout << "\nThe Magic Square for n = "<< n <<"\n\n";

    for (i = 0; i < n; i++) { 
        for ( j = 0; j < n; j++) 
            cout << setw(4) << arr[i][j] << " "; 
        cout << "\n"; 
    } 

    cout << "\nSum of each row or column or diagonal = "<< n * (n * n + 1) / 2 << "\n";
} 
  
int main(){
    int n;
    cout << "\nEnter Any Even Number : ";
    cin >> n; 
    doublyEven(n); 
    return 0; 
}  