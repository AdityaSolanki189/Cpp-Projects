//Problem: Find the minimum value K, such that when we divide all the elements of a given array by it has the summation less than equal to given Sum. [the given array is sorted]

#include<bits/stdc++.h>
using namespace std;

//TC : O(max*n)
void bruteforce(int n, int arr[], int sum){
    int k,summa=0;
    for(k=2;k<arr[n-1]+1;k++){
        summa=0;
        for(int i=0;i<n;i++){
            summa += (arr[i]/k);
        }
        if(summa <= sum){
            cout<<k<<endl;
            break;
        }
    }
}
z
//TC : O(log max*n)
void binarys_method(int n, int arr[], int sum){ 
    int k = arr[n-1] + 1;
    int l=1, h=k,mid;
    while(l<=h){
        mid = (l+h)/2;
        int summa=0;
        for(int i=0;i<n;i++){
            summa += (arr[i]/mid);
        }
        if(summa <= sum){
            k=mid;
            h = mid-1;
        }
        else   
            l = mid+1;
    }
    cout<<k;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int i,n,k,sum,cur_sum=0;
    cin>>n;

    int arr[n];
    for(i=0;i<n;i++){ 
        cin>>arr[i];
        cur_sum+=arr[i];
    }
    
    cin>>sum;

    if(cur_sum <= sum)
        cout<<1;
    else{    
        //bruteforce(n,arr,sum);
        binarys_method(n, arr, sum);
    }
	return 0 ; 
}