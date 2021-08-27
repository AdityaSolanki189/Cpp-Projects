//Finding Factorial of large numbers like fact(100).
/* We one by one multiply x with every digit of res[]. The important point to note here is digits are multiplied from rightmost digit to leftmost digit. If we store digits in same order in res[], then it becomes difficult to update res[] without extra space. That is why res[] is maintained in reverse way, i.e., digits from right to left are stored. */

#include<bits/stdc++.h>
using namespace std;
#define MAX 500

int multiply(int x, int res[], int res_size){
    int carry = 0;
    // multiply res[] with 0 to n 
    for(int i=0;i<res_size;i++){
        int prod = res[i]*x + carry;
        // store last digit of prod in res[]
        res[i] = prod%10;
        // store the rest in carry
        carry = prod/10;
    }

    while(carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n){
    int res[MAX];
    res[0] = 1;
    int res_size = 1;

    for(int i=2;i<=n;i++) {
        res_size = multiply(i, res, res_size);
    }

    cout << "Factorial : ";
    for(int i=res_size-1;i>=0;i--) {
        cout << res[i];
    }
    cout << "\n";
}

int main(){
    int num;
    cin >> num;

    factorial(num);
    return 0;
}