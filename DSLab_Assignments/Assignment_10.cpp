/* 
	PL1 Assignment 10 by Aditya Solanki 
	Roll No. 2193023
	CSE - 3  
 
    Write a modular program using object oriented programming features to implement different searching
    methods.(Binary Search, Sequential Search).
	Binary Search - For Sorted Large Arrays
	Sequential Search - For Unsorted Small Arrays  
*/

#include <iostream>
using namespace std;
#define MAX 20

class Search{
	int array[MAX];
	public:
	void create(int);
	void Binary_Search();
	void Sequential_Search();
};

void Search :: create(int num){
	cout<<"\nEnter Elements in the Array :\n";
	for(int i=0;i<num;i++){
		cin>>array[i];
	}
}

void Search :: Binary_Search(){
	int N,key;
	cout<<"\nEnter Number Of Array Elements : ";
	cin>>N;
	if(N>MAX){
		cout<<"Memory Overflow!"<<endl;
		return;
	}
	create(N);
	cout<<"\nEnter The Element You want to search : ";
	cin>>key;
	int low = 0, high = N-1, mid;
	while(low<=high){
		mid=(low+high)/2;
      	if(array[mid]<key){
         	low=mid+1;
      	}
      	else if(array[mid]>key){
         	high=mid-1;
      	}
      	else{
			cout<<"\n"<<key<<" Found at Index "<<mid<<"\n";
			return;
      	}
	}
	cout<<"\nKey Not Found!\n";
}

void Search :: Sequential_Search(){
	int N,key;
	cout<<"\nEnter Number Of Array Elements : ";
	cin>>N;
	if(N>MAX){
		cout<<"Memory Overflow!"<<endl;
		return;
	}
	create(N);
	cout<<"\nEnter The Element You want to search : ";
	cin>>key;
	for(int i=0;i<N;i++){
		if(array[i] == key){
			cout<<"\n"<<key<<" Found at Index "<<i<<"\n";
			return;
		}
	}
	cout<<"\nKey Not Found!\n";
}

int main(){
	Search s;
	int t=1,ch;
	while(t){
		cout<<"\nChoose Any One : \n1. Binary Search\n2. Sequential Search\n3. Exit\n";
		cin>>ch;
		switch (ch){
			case 1:
                s.Binary_Search();
            break;

            case 2:
                s.Sequential_Search();
            break;

            case 3:
                t = 0;
            break;

            default:
                cout<<"Invalid Input";
            break;
		}
	}
	return 0;
}