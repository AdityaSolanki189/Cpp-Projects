/* Find the Union and Intersection of the two sorted arrays. */
// considering elements of array are distinct

#include <iostream>
using namespace std;

void getUnion(int a[], int b[], int m, int n){
    int i=0,j=0;
    while(i<n && j<m){
    	if(a[i] < b[j])
           cout << a[i++] << " ";

	    else if(b[j] < a[i])
	       cout << b[j++] << " ";

        else{
    	    cout << b[j++] << " ";
    	    i++;
		}
    }
    while(i < n){
        cout << a[i++] << " ";
    }
    while(j < m){
        cout << b[j++] << " ";
    }
	cout<<endl;     
}

void getIntersection(int a[], int b[], int m, int n){
    int i=0,j=0;
    while(i<n && j<m){
    	if(a[i] < b[j])
	        i++;	

	    else if(b[j] < a[i])
            j++;

        else{
            cout << b[j++] << " ";
            i++;
	    }
    }
    cout << endl;
}

int main(){
    int m,n,val;
    cin >> m >> n;
    int A[m], B[n];
    for(int i=0;i<m;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> B[i];

    cout << "Union Of Arrays : ";
    getUnion(A,B,m,n); 

    cout << "Intersection of Arrays : ";
    getIntersection(A,B,m,n);

    return 0;
}