#include <iostream>
using namespace std;

int main(){

    int testcase;
    cin >> t;

    while(testcase--){
        int c1,c2,c3,c4;
        cin >> c1>>c2>>c3>>c4;
        if((c1 + c3 == 180) && (c2 + c4== 180)){
            cout << "Yes"<<endl;
        }    
        else{
            cout << "No"<<endl;
        }
    }

    return 0;
}