#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){

        int N,Q;

        cin>>N>>Q;

        char S[Q];

        cin>>S;

        int C[Q];

        for(int i=0;i<Q;i++) cin>>C[i];

        int count = 0, order[26] = {0}, k=0;
        while (S[count] != '\0') {
            if (S[count] >= 'a' && S[count] <= 'z') {
                k = S[count] - 'a';
                ++order[k];
            }
            ++count;
        }

        int pending[Q] = {0};
        

        for(int i=0;i<Q;i++){

            int rem[26]={0};

            for(int j=0;j<26;j++){

                if(C[i] > order[j] || C[i] == order[j]){
                    rem[j] = 0;
                } 

                else if(C[i] < order[j]){
                    rem[j] = order[j] - C[i];
                }

                pending[i] += rem[j];

            }
        } 

        for(int i=0;i<Q;i++) cout<<pending[i]<<endl;

    }
    return 0;
}