#include <iostream>
using namespace std;

class Node {
public:
    int data,priority;
    Node* next;

    Node() { data = 0; priority = 0; next = NULL; }
    Node(int data, int priority) { this->data = data; this->priority = priority; next = NULL; }
};

class PriorityQueue {
    Node* front, * rear;
public:
    PriorityQueue() { front = NULL, rear = NULL; }

	void enqueue(int data, int pr) {
		Node* newNode = new Node(data, pr);
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

	void dqueue(int lowestPriority) {
		if (front == NULL && rear == NULL) { cout << "\nQueue is Empty" << endl; return; }
		else if (front == rear) { front = NULL; rear = NULL; }
		else {
			Node* temp = front;
			int highestPriorityInPQ = lowestPriority;
			while (temp) {
				if (temp->priority > highestPriorityInPQ) { highestPriorityInPQ = temp->priority; }
				temp = temp->next;
			}
			cout << "Current Hight Priority: " << highestPriorityInPQ ;

			temp = front;
			Node* prevNode = temp;
			while (temp) {
				if (temp->priority == highestPriorityInPQ) {
					prevNode->next = temp->next;
					break;
				}
				else{
					prevNode = temp;
					temp = temp->next;
				}
			}
		}
	}

	void printQueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is empty..."; return; }
		else {
			Node* temp = front;
			cout << "\nQueue:" << endl;
			while (temp) {
				cout << "Data: " << temp->data << "\t| Priority: " << temp->priority << endl;
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
	int highestPriority, lowestPriority;
	cout << "\nEnter the Lowest & Highest Priorities: "; cin >> lowestPriority >> highestPriority;
	PriorityQueue obj;
	while (true) {
		int choice, data, priority, popedItem;
		cout << "\n\nPriority Queue operation: ";
		cout << "\n\t1. Enqueue ";
		cout << "\n\t2. Dqueue ";
		cout << "\n\t3. Print Queue ";
		cout << "\n\t4. Exit ";

		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter the Data for Node: "; cin >> data;
			cout << "Enter the Priority for Node: "; cin >> priority;
			if (priority >= lowestPriority && priority <= highestPriority) { obj.enqueue(data, priority); }
			else { cout << "Please Enter Valid Priority!"; }
			break;
		case 2:
			obj.dqueue(lowestPriority);
			break;
		case 3:
			obj.printQueue();
			break;
		case 4:
			cout << "\nSigning off...";
			exit(1);
		}
	}
	return 0;
}