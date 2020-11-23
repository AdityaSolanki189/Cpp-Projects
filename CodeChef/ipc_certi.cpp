#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,M,K;  //n->students, k->lectures, m->min. munites
    cin>>N>>M>>K;
    ll questions;
    ll lectures;
    ll total_time=0;
    ll eligible=0;
    for(ll i=0;i<N;i++){
        total_time=0;
        questions=0;
        for(ll j=0;j<K;j++){
            cin>>lectures;
            total_time += lectures;
        }
        cin>>questions;
        if(total_time>=M && questions<=10){
            eligible++;
        }
    }
    cout<<eligible<<endl;
    return 0;   
}