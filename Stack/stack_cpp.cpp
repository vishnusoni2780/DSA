#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
	Node* head;
public:
    Stack() { head = NULL; }

    void push(int data) { // Insert at end
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

    int pop() { // Delete at last
		Node* temp = head;
		Node* prevNode = head;
		int len = getLength();
		int popedEle;
		if (head == NULL) {
			cout << "\nStack is empty...";
			popedEle = NULL;
		}
		else if ( len + 1 == 1) { 
			popedEle = temp->data;
			head = NULL;
		}
		else {
			while (temp->next != NULL) {
				prevNode = temp;
				temp = temp->next;
			}
			prevNode->next = NULL;
			popedEle = temp->data;
		}
		return popedEle;
	}

	void peek() {
		if (head == NULL) {
			cout << "\nStack is empty...";
			return;
		}
		Node* temp = head;
		while (temp->next!=NULL) { temp = temp->next; }
		cout << "\nTop Element is: " << temp->data;
	}

	void printStack() {
		Node* temp = head;
		if (head == NULL) {
			cout << "\nStack is empty...";
			return;
		}
		cout << "\nStack:\t";
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		int len = getLength();
		cout << "\nLength of stack is: " << len+1;
	}

    int getLength() {
        int len = -1;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

int main()
{
	Stack obj;
	while (true) {
		int choice, data, popedItem;
		cout << "\n\nStack operation: ";
		cout << "\n\t1. Push ";
		cout << "\n\t2. Pop ";
		cout << "\n\t3. Peak ";
		cout << "\n\t4. Print Stack ";
		cout << "\n\t5. Exit ";

		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter the Data for Node: "; cin >> data;
			obj.push(data);
			break;
		case 2:
			popedItem = obj.pop();
			cout << "\nPoped Element: " << popedItem;
			obj.printStack();
			break;
		case 3:
			obj.peek();
			break;
		case 4:
			obj.printStack();
			break;
		case 5:
			cout << "\nSigning off...";
			exit(1);
		}/*
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
		
		case 10:
			obj.reverse_LL();
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
			break;*/
		}
	return 0;
}