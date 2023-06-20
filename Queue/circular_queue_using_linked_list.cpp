#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() { data = 0; next = NULL; }
	Node(int data) { this->data = data; this->next = NULL; }
};

class CircularQueue {
	Node* front, * rear;
public:
	CircularQueue() { front = NULL, rear = NULL; }

	void enqueue(int data) {
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
			newNode->next = front;
		}
		else {
			//cout << "\nInsertion at last of Queue";
			Node* temp = rear;
			temp->next = newNode;
			rear = newNode;
			rear->next = front;
		}
	}

	void dqueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is Empty" << endl; return; }
		else if (front == rear) { front = NULL; rear = NULL; }
		else { 
			front = front->next;
			rear->next = front;
		}
	}

	void printQueue() {
		if (front == NULL && rear == NULL) { cout << "\nQueue is empty..."; return; }
		else if (front == rear) { cout << "Circular Queue: " << front->data; }
		else {
			Node* temp = front;
			while (temp->next != front) {
				cout << temp->data << " " ;
				temp = temp->next;
			}
			cout << temp->data;
			
			int len = getLength();
			cout << "\nLength of Queue is: " << len;
		}
	}

	int getLength() {
		int len = 0;
		Node* temp = front;
		while (temp->next != front) {
			len++;
			temp = temp->next;
		}
		len++;
		return len;
	}

};

int main()
{
	CircularQueue obj;
	while (true) {
		int choice, data, popedItem;
		cout << "\nQueue operation: ";
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
			obj.enqueue(data);
			break;
		case 2:
			obj.dqueue();
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