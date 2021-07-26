#include <iostream>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;

    while(testcase--){
        string A; 
        cin >> A;
        string final = "";
        int length = A.length();
        if(A[0] =='1')
        {
            final = "10" + A.substr(1,length-1);
        }
        else{
            final =  "1" + A;
        }
        cout << final << endl;
    }

    return 0;
}