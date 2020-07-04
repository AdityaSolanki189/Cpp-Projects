#include <iostream>
#include <math.h>
using namespace std;

//function: f(X,Y,Z) = (X&Z)*(Y&Z):
/*
Subtask #1 (15 points):
    L=0
    R >= 2 ⋅ max(X,Y)
Subtask #2 (25 points): L=0
*/


int main(){
    int T;
    cin>>T;
    while(T--){

        int X,Y,L,R;
        cin>>X>>Y>>L>>R;

        int range = R+1;

        int func[range] = {0};

        int max=0;

        for(int i=0;i<range;i++){
            func[i] = (X&i) * (Y&i);
            if(max < func[i])
                max = i;
        }
        cout<<max<<endl;
    }     
    return 0;
}