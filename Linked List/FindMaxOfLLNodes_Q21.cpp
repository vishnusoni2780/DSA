#include <iostream>
using namespace std;

class Node {
public:
	Node* prev;
	int data;
	Node* next;
	Node() { prev = NULL; data = 0; next = NULL; }
	Node(int data) { this->prev = NULL; this->data = data; this->next = NULL; }
};

class Linkedlist {
	Node* head;
	Node* tail;
public:
	Linkedlist() { head = NULL; tail = NULL; }

	void insertNode_atLast(int data) {
		Node* newNode = new Node(data);

		if (head == NULL && tail == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = NULL;
			return;
		}

		Node* temp = tail;

		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next = newNode;

		tail = newNode;
	}

	void printLinkedList() {
		Node* temp = head;

		if (head == NULL && tail == NULL) {
			cout << "\nLinked List is Empty!" << endl;
			return;
		}
		cout << "\nNodes of Linked List -> ";

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void getMaxNodeValue() {
		Node* temp = head;
		int maxVal = head->data;
		while (temp) {
			if (temp->data > maxVal) { maxVal = temp->data; }
			else { temp = temp->next; }
		}
		cout << "\nMax Node Value is: " << maxVal;
	}
};

int main()
{
	Linkedlist obj;
	int n,data;
	cout << "Enter number of Nodes: ";
	cin >> n;
	while (n > 0) {
		cout << "Enter Data for Node: ";
		cin >> data;
		obj.insertNode_atLast(data);
		n--;
	}
	obj.printLinkedList();
	obj.getMaxNodeValue();

	return 0;
}
