#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;

        cin>>n;

        int x[n];

        for(int i=0;i<n;i++) cin>>x[i];

        int j=0;
        int cases[n];
        for(int i=0;i<n;i++) cases[i]=1;

        for(int i=0;i<n-1;i++){

            int dif = (x[i+1]-x[i]);

            if(dif <2 || dif == 2){
                cases[j] = cases[j] + 1;
            }
            else if(dif > 2){
                j++;
            }
        }

        int min= 100, max =0;
        for(int i=0;i<=j;i++){
            if(min>cases[i]){
                min = cases[i];
            }
            if(max<cases[i]){
                max = cases[i];
            }
        }
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}