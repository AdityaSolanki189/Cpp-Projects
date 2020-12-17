/* 
	PL1 Assignment 11 by Aditya Solanki 
	Roll No. 2193023
	CSE - 3 

    Write a modular program using object oriented programming features to implement different sorting
    methods. (Insertion Sort, Bubble Sort, Selection Sort)
*/

#include <iostream>
using namespace std;
#define MAX 20

class Sort{
	int array[MAX];
	public:
	void create(int);
	void insertion_sort();
	void bubble_sort();
	void selection_sort();
	void display_sorted(int);
};

void Sort :: create(int num){
	cout<<"\nEnter Elements in the Array :\n";
	for(int i=0;i<num;i++){
		cin>>array[i];
	}
}

void Sort :: insertion_sort(){
	int i,key,N;
	cout<<"\nEnter Number Of Array Elements : ";
	cin>>N;
	if(N>MAX){
		cout<<"Memory Overflow!"<<endl;
		return;
	}
	create(N);
    for(int j = 1;j<N;j++){
        key = array[j];
        i = j-1;
        while((i>=0) && (key<array[i])){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
	display_sorted(N);
}

void Sort :: bubble_sort(){

}

void Sort :: selection_sort(){

}

void Sort :: display_sorted(int N){
	cout<<"\nSorted array :\n";
	for(int i=0;i<N;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	Sort s;
	int t=1,ch;
	while(t){
		cout<<"\nChoose Any One Sorting Algorithm :- \n1. Insertion Sort\n2. Bubble Sort\n3. Selection Sort\n4. Exit\n";
		cin>>ch;
		switch (ch){
			case 1:
                s.insertion_sort();
            break;

            case 2:
                s.bubble_sort();
            break;

            case 3:
                s.selection_sort();
            break;

			case 4:
                t = 0;
            break;

            default:
                cout<<"Invalid Input";
            break;
		}
	}
	return 0;
}