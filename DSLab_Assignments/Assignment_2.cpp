#include <iostream>
using namespace std;
# define s 20

/* A saddle point is an element of the matrix such that it 
is the minimum element in its row[m] and maximum in its column[n]. */

void saddle_point(int arr[s][s],int m,int n){
    int count=0;
    for(int i=0;i<m;i++){
        int min_row = arr[i][0], column_index = 0,j,k;
        //finding minimum of the row[m]
        for (j = 1; j < n; j++) { 
            if (min_row > arr[i][j]) { 
                min_row = arr[i][j]; 
                column_index = j; 
            } 
        }
        //finding maximum of the column[n]        
        for(k=0;i<n;k++){
            if (min_row < arr[k][column_index]) {
                break;
            }
            //After Checking all the elements in that column
            if (k == n-1) { 
                cout << "\nSaddle Point Of The Given Matrix Is : " << min_row<<endl;
                cout << "At Location : "<<"["<<i+1<<","<<column_index+1<<"]"<<endl; 
                count++;
            } 
        }
    }
    if(count == 0){
        cout<<"\nSaddle Point Not Found In The Given Matrix!\n";
    }
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