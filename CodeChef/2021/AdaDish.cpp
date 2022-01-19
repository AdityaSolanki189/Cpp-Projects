#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int N;
	    cin>>N;
	    int C[N]; //time taken for each dish 1-N
	    for(int i=0;i<N;i++) cin>>C[i];
        int burner[2];
        if(N==1){
            cout<<C[0]<<endl;
            continue;
        }
        else if(N==2){
            cout<<max(C[0],C[1])<<endl;
            continue;
        }
        else if(N==3){
            sort(C,C+N);
            cout<<max(C[0]+C[1],C[2])<<endl;
            continue;
        }
        else{
            sort(C,C+N,greater<int>());  //descending
            //two burners burner[0] and burner[1]
            burner[0] = C[0];
            burner[1] = C[1];
            int i=2;
            while(i<N){
                if(burner[1] <= burner[0]){
                    burner[1] += C[i];
                    i++;
                }
                if(burner[0] < burner[1]){
                    burner[0] += C[i];
                    i++;
                }
            }
            cout<<max(burner[0],burner[1])<<endl;
        }
    }
    return 0;
}