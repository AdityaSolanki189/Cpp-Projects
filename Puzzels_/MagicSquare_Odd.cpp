/* Magic Square Fill the 3 × 3 table with nine distinct integers from 1 to 9 so that the
sum of the numbers in each row, column, and corner-to-corner diagonal is the same */
//This program works only for ODD values of n.

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
using namespace std;

void generateSquare(int n){
    int magicSquare[n][n];
 
    // set all slots as 0
    memset(magicSquare, 0, sizeof(magicSquare));
 
    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;
 
    // One by one put all values in magic square
    for (int num = 1; num <= n * n;) {

        if (i == -1 && j == n){ // 3rd condition, 
        //  if (-1, n), then (0, n-2)
            j = n - 2;
            i = 0;
        }
        else {
            // 1st condition, if next number
            // goes to out of square's right side
            // ie. j > n-1, then j = 0
            if (j == n)
                j = 0;

            // 1st condition, if next number
            // is goes to out of square's upper side
            // ie. i < 0, then i = n-1
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j]){ // 2nd condition,
        //  if already occupied ie.(i, j) then (i+1, j-1) 
            j -= 2;
            i++;
            continue;
        }
        else{
            magicSquare[i][j] = num++; // set number
        }
        j++;
        i--; // 1st condition
    }
 
    cout << "\nThe Magic Square for n = "<< n <<"\n\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            // setw(7) is used so that the matrix gets
            // printed in a proper square fashion.
            cout << setw(4) << magicSquare[i][j] << " ";
        cout << endl;
    }

    cout << "\nSum of each row or column or diagonal = "<< n * (n * n + 1) / 2 << "\n";
}
 
int main(){ 
    int n;
    cout << "\nEnter Any Odd Number : ";
    cin >> n; 
    generateSquare(n);
    return 0;
}