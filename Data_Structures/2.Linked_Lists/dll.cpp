// Doubly Linked List

#include <iostream>

using namespace std;

class Node
{
	public :
	string data;
	Node *prev, *next;
};

class DLL
{
	public :
	Node *head, *temp, *tail;
	int nodeCount = 0;
	
	Node *createNode();
	void displayList();
	void addNode();
	void addFirstNode();
	void addAtHead();
	void addAtTail();
	void addAtPosition(int, int);
	void deleteNode();
	void deleteAtHead();
	void deleteAtTail();
	void deleteAtPosition(int, int);
	void reverseDisplay();
	
	DLL()	// Constructor
	{
		head = NULL;
		tail = NULL;
	}
};

Node *DLL :: createNode()
{
	Node *newNode = new Node;
	
	cout << "\nPlease enter a string - ";
	cin >> newNode -> data;
	newNode -> prev = NULL;
	newNode -> next = NULL;
	nodeCount++;
	
	return newNode;
}

void DLL :: addNode()
{
	int nodePosition = 0, count = 1;
	temp = NULL;
	
	if(head == NULL)
	{
		addFirstNode();
	}
	else
	{
		cout <<"\nPlease enter the position you would like to enter the node at - ";
		cin >> nodePosition;
		
		if(nodePosition > nodeCount)
			cout << "\nThere exist only " << nodeCount << " nodes. Try again.";
		else if(nodePosition == 1)	// If head needs to be added
			addAtHead();
		else if(nodePosition == nodeCount)	// If tail needs to be added
			addAtTail();
		else if(nodePosition > 1)	// Some place in between the head and the tail
			addAtPosition(count, nodePosition);
		else
			cout << "\nA valid number was not entered.";
	}
}
void DLL :: addFirstNode()
{
	cout << "\nPlease enter the first node into the list :";
	temp = createNode();
	temp -> prev = NULL;
	temp -> next = NULL;
	head = temp;
	tail = head;
}

void DLL :: addAtHead()
{
	temp = createNode();
	head -> prev = temp;
	temp -> next = head;
	temp -> prev = NULL;
	head = temp;
}

void DLL :: addAtTail()
{
	temp = createNode();
	tail -> next = temp;
	temp -> prev = tail;
	temp -> next = NULL;
	tail = temp;
}

void DLL :: addAtPosition(int count, int nodePosition)
{
	temp = head;
	while(temp != NULL && count <= nodeCount)
	{
		if(count == nodePosition)	// When the required position is reached 
		{
			Node *newNode = createNode();
			Node *temp2;	// Temporary node 2
					
			temp2 = temp -> next;	// Changes in the interlinkages
			temp2 -> prev = newNode;
			newNode -> next = temp2;
			temp -> next = newNode;
			newNode -> prev = temp;
		}
		temp = temp -> next;
		count++;
	}
}

void DLL :: deleteNode()
{
	int deletePosition = 1, count = 1;
	cout << "\nPlease enter the position you would like to delete from - ";
	cin >> deletePosition;
	
	if(head == NULL)
		cout << "\nThe list empty. Deletion cannot be carried out.";
	else if(deletePosition > nodeCount)
		cout << "\nThere is no position " << deletePosition;
	else if(deletePosition == 1)
		deleteAtHead();
	else if(deletePosition == nodeCount)
		deleteAtTail();
	else if(deletePosition > 1)
		deleteAtPosition(count, deletePosition);
	else
		cout << "\nA valid number was not entered.";
}

void DLL :: deleteAtHead()
{
	if(head -> next != NULL)
	{
		temp = head -> next;
		temp -> prev = NULL;
		temp = head;
		head = head -> next;
		
		delete temp;
	}
	else
		delete head;
	
	nodeCount--;
}

void DLL :: deleteAtTail()
{
	if(head -> next == NULL)
		deleteAtHead();
	else
	{
		temp = tail -> prev;
		temp -> next = NULL;
		temp = tail;
		tail = tail -> prev;
		
		delete temp;
	}
	
	nodeCount--;
}

void DLL :: deleteAtPosition(int count, int deletePosition)
{
	temp = head;
	while(temp != NULL && count <= deletePosition)
	{
		if(count == deletePosition)
		{
			Node *temp2;
			
			temp2 = temp -> prev;		// Assigning prev node to temp2
			temp2 -> next = temp -> next;	// Connecting 1st link of prev to next
			temp2 = temp2 -> next;	// Assigning next node to temp2
			temp2 -> prev = temp -> prev;	// Connecting 2nd link of prev to next
			
			delete temp;
		}
		
		temp = temp -> next;
		count++;
	}
	
	nodeCount--;
}

void DLL :: displayList()
{
	temp = head;
	
	cout << endl;
	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

void DLL :: reverseDisplay()
{
	temp = tail;
	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> prev;
	}
}

int main()
{
	cout << "\n\n Doubly Linked List Application \n";
	cout << "\n Enter 1 to enter a new node into the list \n2 to display the list \n3 to delete a node \n4 to display the list in reverse \n5 to exit the application.\n";

	DLL obj;
	int num;
	
	while(true)
	{
		cout << "\nEnter a number - ";
		cin >> num;
		
		if(num == 5)
			break;
		
		switch(num)
		{
			case 1:
				obj.addNode();
				break;
			case 2:
				obj.displayList();
				break;
			case 3:
				obj.deleteNode();
				break;
			case 4:
				obj.reverseDisplay();
				break;
			default:
				cout << "\n Please enter a valid number.";
		}
	}
	
	cout << "\nThank you for using the DLL Aplication\n";
	
	return 0;
}
