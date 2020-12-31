/* 
	PL1 Assignment 9 by Aditya Solanki 
	Roll No. 2193023
	CSE - 3 

    Write a program to implement priority queue. Add job and delete job from queue based on it's time priority
    value. If there is lesser the time value then higher the priority for addition and deletion. 
*/

#include <iostream>
using namespace std;

struct Node{
	int time;
	int job;
	Node *link;
};

class Priority_Queue{
	Node *front;
	public:
	void insert_job(int,int);
	void delete_job();
	void display();
	Priority_Queue(){
		front = NULL;
	}
};

void Priority_Queue :: insert_job(int job, int time){

}

void Priority_Queue :: delete_job(){

}

void Priority_Queue :: display(){

}

int main(){
	Priority_Queue obj;
	int t=0, job, priority, ch;
	while(t){
		cout<<"Enter Any One Choice :\n";
		cout<<"1. Insert Value in Priority Queue\n";
		cout<<"2. Delete Value from Priority Queue\n";
		cout<<"3. Display the Priority Queue\n";
		cout<<"4. Exit.\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter The Job Value : ";
				cin>>job;
				cout<<"Enter The Time Priority : ";
				cin>>priority;
				obj.insert_job(job,priority);
			break;

			case 2:
				obj.delete_job();
			break;

			case 3:
				obj.display();
			break;

			case 4:
				t=0;
			break;

			default:
				cout<<"Wrong Input!";
			break;
		}
	}
	return 0;
}