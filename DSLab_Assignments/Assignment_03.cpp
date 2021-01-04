/* 
	PL1 Assignment 3 by Aditya Solanki 
	Roll No. 2193023
	CSE - 3  
 
    A set S=(1,3, a, s, t, i} represent alphanumeric characters. Write a program in C++ to generate all possible passwords
    of length 4.
    We can form n^4 passwords, with repetition. (here, n=6  So, 6^4 = 1296)
    But without REPETITION, we get No of possible outcomes = 360
*/

#include <iostream>
using namespace std;

class Password{
    char a[6];
    public:
        void pass_function();
};

void Password :: pass_function(){
    int count = 0;
    cout<<"Enter Any 6 Alphanumeric Values : "<<endl;
    for(int i=0;i<6;i++) cin>>a[i];

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<6;k++){
                for(int l=0;l<6;l++){
                    if(a[i]==a[j]||a[i]==a[k]||a[i]==a[l]||a[j]==a[k]||a[j]==a[l]||a[k]==a[l]){
                        continue;
                    }
                    cout<<a[i]<<a[j]<<a[k]<<a[l]<<endl;
                    count++;
                }
            }
        }
    }
    cout<<"\nTotal No. of Passwords Formed : "<<count<<"\n";
}

int main(){
    Password p;
    p.pass_function();
    return 0;
}