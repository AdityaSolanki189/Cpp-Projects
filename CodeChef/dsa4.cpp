#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);     //to speed up I/O process
    cin.tie(NULL);
    long t;
    cin>>t;
    vector<ll> v;
    ll p;
    for(ll i=0;i<t;i++)
    {
        cin>>p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    p=0;
    for(ll i=t;i>0;i--)
    {
        v[p]=v[p]*i;
        p++;
    }
    cout<<*max_element(v.begin(),v.end());
    return 0;
}