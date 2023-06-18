#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	Node* prev;
	int data;
	Node* next;

	Node()
	{
		prev = NULL;
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->prev = NULL;
		this->data = data;
		this->next = NULL;
	}
};

class Linkedlist {
	Node* head;
	Node* tail;
public:
	Linkedlist() { head = NULL; tail = NULL; }

	int getLength() {
		int len=0;
		Node* temp = head;
		while (temp) {
			len++;
			temp = temp->next;
		}
		return len;
	}

	void insertNode_atStart(int data) {
		Node* newNode = new Node(data);

		if (head == NULL && tail == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = NULL;
			return;
		}

		Node* temp = head;

		newNode->next = temp;
		temp->prev = newNode;
		newNode->prev = NULL;
		head = newNode;
	}

	void insertNode_atLast(int data) {
		Node* newNode = new Node(data);

		if (head == NULL && tail==NULL) {
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

	void insertNode_atLoc(int loc,int data) {
		int len = getLength(), i = 1;
		Node* newNode = new Node(data);
		
		if (head == NULL && tail == NULL) { head = newNode; tail = newNode; return; }
		else if (loc == 0 || loc == 1) { insertNode_atStart(data); }
		else if (loc >= len+1) { insertNode_atLast(data); }
		else {
			Node* temp = head;
			while (i < loc - 1) {
				temp = temp->next;
				i++;
			}
			newNode->prev = temp;
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
		}
	}

	bool search_byValue(int item) {
		bool flag = false;
		Node* temp = head;
		while (temp) {
			if (temp->data == item) {
				flag = true;
				break;
			}
			temp = temp->next;
		}
		return flag;
	}

	void traverseFromFront() {
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

	void traverseFromBehind() {
		Node* temp = tail;

		if (head == NULL && tail == NULL) {
			cout << "\nLinked List is Empty!" << endl;
			return;
		}
		cout << "\nNodes of Linked List -> ";

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
	}

	void deleteNode_atStart() {
		Node* temp = head;
		if (head == NULL && tail == NULL) { cout << "\nList is Empty" << endl; return; }
		else {
			head = temp->next;
			temp->next->prev = NULL;
		}
	}

	void deleteNode_atLast() {
		Node* temp = tail;

		if (head == NULL && tail == NULL) { cout << "\nList is Empty" << endl; return; }
		else {
			tail = temp->prev;
			temp->prev->next = NULL;
		}
	}

	void deleteNode_byLoc(int loc) {
		Node* temp = head;
		int len = getLength();

		if (head == NULL && tail == NULL) { cout << "\nList empty." << endl; }
		else if (len < loc) { cout << "\nIndex out of range" << endl; }
		else if (loc == 1 || loc == 0) {
			cout << "\nDeleting from start.";
			deleteNode_atStart();
		}
		else if (loc == len) {
			cout << "\nDeleting from end.";
			deleteNode_atLast();
		}
		else {
			// Traverse the list to find the node to be deleted.
			while (loc-- > 1) {
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
	}

	void deleteNode_byValue(int vdata) {
		Node* temp = head;
		int ind = 0;
		if (head == NULL && tail == NULL) { cout << "\nList is Empty" << endl; }
		else {
			while (temp != 0) {
				ind++;
				if (temp->data == vdata) { break; }
				else { temp = temp->next; }
			}
			cout << "\nDeleted from Loc.";
			deleteNode_byLoc(ind);
		}
	}

	void update(int data) {
		Node* temp = head;
		int existingDataVal, newDataVal;
		while (temp) {
			if (temp->data == data) { break; }
			else { temp = temp->next; }
		}
		existingDataVal = temp->data;
		cout << "\nEnter the new desired data: ";
		cin >> newDataVal;
		temp->data = newDataVal;
		cout << "\nData Updated.";
	}
};

int main()
{
	Linkedlist obj;
	while (true) {
		int choice,data,loc,item;
		bool flag;
		//cout << "\nLinked List operation: \n\t1. Insert at Begining\n\t2. Insert at End\n\t3. Insert at Specific Location\n\t4. Delete at Begining\n\t5. Delete at End\n\t6. Delete at Specific Location\n\t7. Delete by data\n\t8. Traverse\n\t9. Exit\n";
		cout << "\nLinked List operation: ";
		cout << "\n\t1. Insert at Begining ";
		cout << "\n\t2. Insert at End ";
		cout << "\n\t3. Insert at Specific Location ";
		cout << "\n\t4. Search by Value ";
		cout << "\n\t5. Delete at Begining ";
		cout << "\n\t6. Delete at End ";
		cout << "\n\t7. Delete at Specific Location ";
		cout << "\n\t8. Delete by data ";
		cout << "\n\t9. Traverse From Front";
		cout << "\n\t10. Traverse From Behind";
		cout << "\n\t11. Update Any Data ";
		cout << "\n\t12. Exit\n";

		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//int data;
			cout << "\nEnter the Data for Node: ";
			cin >> data;
			obj.insertNode_atStart(data);
			break;
		case 2:
			//int data;
			cout << "\nEnter the Data for Node: ";
			cin >> data;
			obj.insertNode_atLast(data);
			break;
		case 3:
			//int loc,data;
			cout << "\nEnter the desired location: ";
			cin >> loc;
			cout << "\nEnter the Data for Node: ";
			cin >> data;
			obj.insertNode_atLoc(loc,data);
			break;
		case 4:
			cout << "\nEnter the item to search: ";
			cin >> item;
			flag = obj.search_byValue(item);
			if (flag) { cout << "\nElement found."; }
			else { cout << "\nElement doesn't exist!"; }
			break;
		case 5:
			obj.deleteNode_atStart();
			break;
		case 6:
			obj.deleteNode_atLast();
			break;
		case 7:
			cout << "\nEnter the desired location: ";
			cin >> loc;
			obj.deleteNode_byLoc(loc);
			break;
		case 8:
			cout << "\nEnter the desired data: ";
			cin >> data;
			flag = obj.search_byValue(data);
			if (flag) {
				cout << "\nElement found.";
				obj.deleteNode_byValue(data);
			}
			else { cout << "\nElement doesn't exist!"; }
			break;
		case 9:
			obj.traverseFromFront();
			break;
		case 10:
			obj.traverseFromBehind();
			break;
		case 11:
			cout << "\nEnter the desired data: ";
			cin >> data;
			flag = obj.search_byValue(data);
			if (flag) {
				cout << "\nElement found.";
				obj.update(data);
			}
			else { cout << "\nElement doesn't exist!"; }
			break;
		case 12:
			cout << "\nSigning off...";
			exit(1);
		}
	}
	return 0;
}


