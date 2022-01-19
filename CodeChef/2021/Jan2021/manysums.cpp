/* You are given a range of integers {L,L+1,…,R}. An integer X is said to be reachable if it can be represented as a sum of two not necessarily distinct integers in this range. Find the number of distinct reachable integers. */


#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
    int l,r; cin>>l>>r;
    l=2*l;
    r=2*r;

    int ans=r-l+1;

    cout<<ans<<"\n";
}

int main(){
    fastio();
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


/* 
The first observation that we can make is that the, number of distinct integers that are possible will lie in a continuous range since the given range is continuous.

Proof :-
Now, as we know that the integers will be in continuous range hence we are only left with finding out the endpoints of the range. The endpoints of any continuous range are minimum and maximum integers possible.

Here the Minimum integer that can be obtained will be 2*L2∗L.
And the Maximum integer that can be obtained will be 2*R2∗R.
Since now as be know our range i.e.i.e. [2*L,2*R][2∗L,2∗R], we can easily count the number of integers in this range.

Hence the number of distinct integers are (2*R-2*L+1)(2∗R−2∗L+1). 
*/