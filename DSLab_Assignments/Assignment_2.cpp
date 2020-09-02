#include <iostream>
using namespace std;
# define s 20

/* A saddle point is an element of the matrix such that it 
is the minimum element in its row and maximum in its column. */

void saddle_point(int arr[s][s],int m,int n){
    for(int i=0;i<m;i++){
        int min_row = arr[i][0], column_id = 0,j;
        for (j = 1; j < n; j++) { 
            if (min_row > arr[i][j]) { 
                min_row = arr[i][j]; 
                column_id = j; 
            } 
        }
        int k; 
        for(k=0;i<m;k++){
            if (min_row < arr[k][column_id]) 
                break;
        }
        if (k == m) { 
           cout << "\nSaddle Point Of The Given Matrix Is : " << min_row<<endl;
           cout << "At Location : "<<"["<<i+1<<","<<column_id+1<<"]"<<endl;
           return; 
        } 
    }
    cout<<"\nSaddle Point Not Found!\n";
}

int main(){
    int arr[s][s],m,n;
    cout<<"\nEnter Array Dimensions : ";
    cin>>m>>n;
    cout<<"\nEnter Array Elements "<<endl;
    for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Enter Element At " << "[" << i + 1 << "," << j + 1 << "] : ";
			cin >> arr[i][j];
		}
	}
    cout<<"\nYour Matrix :\n"<<endl;
    for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << " "<<arr[i][j]<< " ";
		}
        cout<<endl;
	}
    saddle_point(arr,m,n);
    return 0;
}