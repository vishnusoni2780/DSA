#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() { data = 0; next = NULL; }
	Node(int data) { this->data = data; this->next = NULL; }
};

class InputRestrictedQueue {	//Insertion at Rear but Deletion from Both.
	Node* front, * rear;
public:
	InputRestrictedQueue() { front = NULL, rear = NULL; }

	void inputRestrictedQueueMenu() {
		cout << "\n\nInput Restricted Queue Operation: ";
		cout << "\n\t1. Enqueue ";
		cout << "\n\t2. Dqueue From Front";
		cout << "\n\t3. Dqueue From End";
		cout << "\n\t4. Print Queue ";
		cout << "\n\t5. Exit ";
	}

	void enqueue_endInputRestrictedQueue(int data) {
		Node* newNode = new Node(data);
		if (front == NULL && rear == NULL) {
			//cout << "\nInsertion When Queue is Empty";
			front = newNode;
			rear = newNode;
		}
		else if (front == rear) {
			//cout << "\nInsertion When front == rear";
			front->next = newNode;
			rear = newNode;
		}
		else {
			//cout << "\nInsertion at last of Queue";
			Node* temp = rear;
			temp->next = newNode;
			rear = newNode;
		}
	}

	void dqueue_startInputRestrictedQueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is Empty" << endl; return; }
		else if (front == rear) { front = NULL; rear = NULL; }
		else { front = front->next; }
	}

	void dqueue_endInputRestrictedQueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is Empty" << endl; return; }
		else if (front == rear) { front = NULL; rear = NULL; }
		else {
			Node* temp = front;
			Node* prevNode = temp;
			while (temp->next != 0) {
				prevNode = temp;
				temp = temp->next;
			}
			prevNode->next = NULL;
		}
	}

	void printQueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is empty..."; return; }
		else {
			Node* temp = front;
			cout << "\nQueue:\t";
			while (temp) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			int len = getLength();
			cout << "\nLength of Queue is: " << len;
		}
	}

	int getLength() {
		int len = 0;
		Node* temp = front;
		while (temp) {
			len++;
			temp = temp->next;
		}
		return len;
	}

};

class OutputRestrictedQueue {	//Deletion from Front but Insertion from Both.
	Node* front, * rear;
public:
	OutputRestrictedQueue() { front = NULL, rear = NULL; }

	void outputRestrictedQueueMenu() {
		cout << "\n\nOutput Restricted Queue Operation: ";
		cout << "\n\t1. Enqueue From Front";
		cout << "\n\t2. Enqueue From End";
		cout << "\n\t3. Dqueue From Front";
		cout << "\n\t4. Print Queue ";
		cout << "\n\t5. Exit ";
	}

	void enqueue_startOutputRestrictedQueue(int data) {
		Node* newNode = new Node(data);
		if (front == NULL && rear == NULL) {
			//cout << "\nInsertion When Queue is Empty";
			front = newNode;
			rear = newNode;
		}
		else if (front == rear) {
			//cout << "\nInsertion When front == rear";
			newNode->next = front;
			front = newNode;
		}
		else {
			//cout << "\nInsertion at start of Queue";
			Node* temp = front;
			newNode->next = temp;
			front = newNode;

		}
	}

	void enqueue_endOutputRestrictedQueue(int data) {
		Node* newNode = new Node(data);
		if (front == NULL && rear == NULL) {
			//cout << "\nInsertion When Queue is Empty";
			front = newNode;
			rear = newNode;
		}
		else if (front == rear) {
			//cout << "\nInsertion When front == rear";
			front->next = newNode;
			rear = newNode;
		}
		else {
			//cout << "\nInsertion at last of Queue";
			Node* temp = rear;
			temp->next = newNode;
			rear = newNode;
		}
	}

	void dqueue_startOutputRestrictedQueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is Empty" << endl; return; }
		else if (front == rear) { front = NULL; rear = NULL; }
		else { front = front->next; }
	}

	void printQueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is empty..."; return; }
		else {
			Node* temp = front;
			cout << "\nQueue:\t";
			while (temp) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			int len = getLength();
			cout << "\nLength of Queue is: " << len;
		}
	}

	int getLength() {
		int len = 0;
		Node* temp = front;
		while (temp) {
			len++;
			temp = temp->next;
		}
		return len;
	}

};


int main()
{
	int restrictedChoic;
	cout << "Which Queue to create?\n1. Input Restricted\n2. Output Restricted" << endl;
	cin >> restrictedChoic;
	if (restrictedChoic == 1) { 
		InputRestrictedQueue obj; 
		while (true) {
			int choice, data, popedItem;
			obj.inputRestrictedQueueMenu();
			cout << "\nEnter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "\nEnter the Data for Node: "; cin >> data;
				obj.enqueue_endInputRestrictedQueue(data);
				break;
			case 2:
				obj.dqueue_startInputRestrictedQueue();
				break;
			case 3:
				obj.dqueue_endInputRestrictedQueue();
				break;
			case 4:
				obj.printQueue();
				break;
			case 5:
				cout << "\nSigning off...";
				exit(1);
			}
		}
	}
	else {
		OutputRestrictedQueue obj;
		while (true) {
			if (restrictedChoic == 1) { InputRestrictedQueue obj; }
			else { OutputRestrictedQueue obj; }

			int choice, data, popedItem;
			obj.outputRestrictedQueueMenu();

			cout << "\nEnter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "\nEnter the Data for Node: "; cin >> data;
				obj.enqueue_startOutputRestrictedQueue(data);
				break;
			case 2:
				cout << "\nEnter the Data for Node: "; cin >> data;
				obj.enqueue_endOutputRestrictedQueue(data);
				break;
			case 3:
				obj.dqueue_startOutputRestrictedQueue();
				break;
			case 4:
				obj.printQueue();
				break;
			case 5:
				cout << "\nSigning off...";
				exit(1);
			}
		}
	}

	
	return 0;
}