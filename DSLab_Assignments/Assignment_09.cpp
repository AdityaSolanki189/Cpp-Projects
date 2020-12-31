/* 
	PL1 Assignment 9 by Aditya Solanki 
	Roll No. 2193023
	CSE - 3 

    Write a program to implement priority queue. Add job and delete job from queue based on it's time priority
    value. If there is lesser the time value then higher the priority for addition and deletion. 
	Here, we are using a Min_Priority Queue.
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
	Node *q, *temp = new Node();
	temp->job = job;
	temp->time = time;
	if(front == NULL || time < front->time){
		temp->link = front;
		front = temp;
	}
	else{
		q = front;
		while(q->link != NULL && q->link->time <= true){
			q = q->link;
		}
		temp->link = q->link;
		q->link = temp;
	}
}

void Priority_Queue :: delete_job(){
	Node *temp;
	if(front == NULL){
		cout<<"Queue Underflow!\n";
	}
	else{
		temp = front;
		cout<<"Deleted Job is : "<<temp->job<<"\n";
		front = front->link;
		delete(temp);
	}
}

void Priority_Queue :: display(){
	Node *temp = front;
	if(temp == NULL){
		cout<<"Queue Is Empty!\n";
	}
	else{
		cout<<"The Queue is :\n";
		cout<<"Time\tJob\n";
		while(temp!=NULL){
			cout<<temp->time<<"\t"<<temp->job<<"\n";
			temp = temp->link;
		}
	}
}

int main(){
	Priority_Queue obj;
	int t=1, job, time, ch;
	while(t){
		cout<<"Enter Any One Choice :\n";
		cout<<"1. Insert Value in Priority Queue\n";
		cout<<"2. Delete Value from Priority Queue\n";
		cout<<"3. Display the Priority Queue\n";
		cout<<"4. Exit.\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter The Job Number : ";
				cin>>job;
				cout<<"Enter its Time Value : ";
				cin>>time;
				obj.insert_job(job,time);
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