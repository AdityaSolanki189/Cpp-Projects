#include <bits/stdc++.h>
using namespace std;
 
int Max_Len(int Array[], int N){
    vector<vector<int> > v;
    for (int i = 0; i < N; i++) {
        if (Array[i] == 1) {
            int s = i, len;
            while (Array[i] == 1 && i < N) {
                i++;
            }
            len = i - s;
            v.push_back({ len, s, i - 1 });
        }
    }
 
    if (v.size() == 0) {
        return 0;
    }

    int length = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        length = max(length, v[i][0]);
        if (v[i + 1][1] - v[i][2] - 1 == 2) {
            length = max(length, v[i][0] + v[i + 1][0]);
        }
        if (v[i + 1][1] - v[i][2] - 1 == 1) {
            length = max(length, v[i][0] + v[i + 1][0] - 1);
        }
    }
 
    length = max(v[v.size() - 1][0], length);
    return length;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++) cin>>arr[i];
        cout << Max_Len(arr, N) << endl;
    }
    return 0;
}