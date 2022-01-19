#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
    int m,n,k;
    cin >> m>> n>>k;
    unordered_set<int> array;
    int total;
    int summ=0;
    for(int i=0;i<k;i++){
        summ += array[i];
    }
    int min = summ;
    for(int i=k;i<array.size();i++){
        summ += array[i]-array[i-k];
        min = min(min, summ);
    }
    total = 0;
    for(int i=0;i<array.size();i++){
        if(array[i] == 1){
            total++;
        }
    }
    int ans =  (min*(min+1)/2)+total-min;
}

int main(){
    fastio();
    int t; cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
    return 0;
}


for _ in range(testcase):
    n, k = [int(x) for x in input().split()]
    array = list(map(int, input().split()))
    sum_one = 0
    for i in range(k):
        sum_one += array[i]

    min_one = sum_one
    for i in range(k, len(array)):
        sum_one += array[i] - array[i-k]
        min_one = min(min_one, sum_one)
    
    total_one = 0
    for i in range(len(array)):
        if array[i]==1:
            total_one+=1
    answer = (min_one*(min_one+1)//2)+total_one-min