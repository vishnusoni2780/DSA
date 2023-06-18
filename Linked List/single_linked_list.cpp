#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

//Linked List Class

class Linkedlist {
	Node* head;			// Here, head is a pointer which shall store address of any object of type 'Node'.
						// We know addresses are unsigned 'long', so pointer are always allocated 4 or 8 bytes of memory.
						// Here, head will not allocated any memory as we haven't use new to initialize.

public:
	Linkedlist() { head = NULL; }

	int getLength() {
		Node* temp = head;
		int len = 0;

		while (temp != NULL) {
			temp = temp->next;
			len++;
		}
		delete temp;
		return len;
	}

	void insertNode_atStart(int data) {
		Node* newNode = new Node(data);

		if (head == NULL) {
			head = newNode;
			return;
		}

		Node* temp = head;
		newNode->next = temp;
		head = newNode;
	}

	void insertNode_atLast(int data) {
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

	void insertNode_atLoc(int loc,int data) {
		int len = getLength() , i = 1;
		Node* newNode = new Node(data);
		
		if (head == NULL) { head = newNode; return; }
		else if (loc == 1 || loc==0) { insertNode_atStart(data); }
		else if (loc >= len+1) { insertNode_atLast(data); }
		else {
			Node* temp = head;
			while (i < loc - 1) {
				temp = temp->next;
				i++;
			}
			newNode->next = temp->next;
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

	void printLinkedList() {
		Node* temp = head;
		if (head == NULL) { cout << "\nLinked List is Empty!" << endl; return; }
		cout << "\nNodes of Linked List -> ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void deleteNode_atStart() {
		if (head == NULL) { cout << "\nList is Empty" << endl; return; }
		else { head = head->next; }
	}

	void deleteNode_atLast() {
		Node* temp = head;
		Node* prevNode = temp;

		if (temp == NULL) { cout << "\nList is Empty" << endl; }
		else {
			while (temp->next != 0) {
				prevNode = temp;
				temp = temp->next;
			}
			prevNode->next = NULL;
		}

	}

	void deleteNode_byLoc(int loc) {
		Node* temp = head, * prevNode = NULL;
		int len = getLength();

		if (head == NULL) { cout << "\nList empty." << endl; }
		else if (len < loc) { cout << "\nIndex out of range" << endl; }
		else if (loc == 1 || loc==0) {
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
				prevNode = temp;
				temp = temp->next;
			}
			// Change the next pointer of the previous node.
			prevNode->next = temp->next;
			delete temp;
		}
	}

	void deleteNode_byValue(int vdata) {
		Node* temp = head;
		Node* prevNode = temp;

		if (temp == NULL) { cout << "\nList is Empty" << endl; }
		else {
			int ind = 0;
			Node* tp_mid = head;
			while (tp_mid != 0) {
				ind++;
				if (tp_mid->data == vdata) { break; }
				tp_mid = tp_mid->next;
			}
			cout << "\nDeleted from Loc.";
			deleteNode_byLoc(ind);
		}
	}

	void reverse_LL() {
		stack<int> stack_of_data;
		Node* temp = head;
		Node* prevNode = NULL;

		if (temp == NULL) {
			cout << "\nList is Empty\n";
		}
		//using embadded while loop

		// using stack /working fine
		else {
			while (temp != 0) {
				stack_of_data.push(temp->data);
				temp = temp->next;
			}
		}

		cout << "\nReversed Linked List: ";
		while (!stack_of_data.empty()) {
			cout << stack_of_data.top() << " ";
			stack_of_data.pop();
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


// Main()

int main()
{
	Linkedlist obj;
	while (true) {
		bool flag;
		int choice,data,loc,item;
		cout << "\nLinked List operation: ";
		cout << "\n\t1. Insert at Begining ";
		cout << "\n\t2. Insert at End ";
		cout << "\n\t3. Insert at Specific Location ";
		cout << "\n\t4. Search by Value ";
		cout << "\n\t5. Delete at Begining ";
		cout << "\n\t6. Delete at End ";
		cout << "\n\t7. Delete at Specific Location ";
		cout << "\n\t8. Delete by data ";
		cout << "\n\t9. Traverse ";
		cout << "\n\t10. Reverse the LL ";
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
			obj.printLinkedList();
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
			break;
		case 12:
			cout << "\nSigning off...";
			exit(1);
		}
	}
	return 0;
}





/*
class ProjInfo {
public:
	int projId;
	string projName;
	string projDate;
	int noOfMembers;

	ProjInfo() {}

	ProjInfo(int projId, string projName, string projDate, int noOfMembers) {
		this->projId = projId;
		this->projName = projName;
		this->projDate = projDate;
		this->noOfMembers = noOfMembers;
	}
	void DisplayProjInfoObj() {
		//cout << "\n---------------------";
		cout << "\n\nProject ID: " << this->projId;
		cout << "\nProject Name: " << this->projName;
		cout << "\nProject Date: " << this->projDate;
		cout << "\nNo. of Project Members: " << this->noOfMembers;
		cout << "\n---------------------";
	}
};
class Node {
public:
	ProjInfo projInfoObj;
	Node* next;

	Node() {
		next = NULL;
	}
	Node(ProjInfo projInfoObj) {
		this->projInfoObj = projInfoObj;
		this->next = NULL;
	}
};
class Linkedlist {
	Node* head;
public:
	Linkedlist() { head = NULL; }

	int getLengthOfLL() {
		Node* temp = head;
		int len = 0;

		while (temp != NULL) {
			temp = temp->next;
			len++;
		}
		delete temp;
		return len;
	}

	void insertion(int projid, string projname, string startdate, int noofresource) {
		ProjInfo projInfoObj(projid, projname, startdate, noofresource);
		Node* newNode = new Node(projInfoObj);

		if (head == NULL) {
			head = newNode;
			return;
		}

		Node* temp = head;
		newNode->next = temp;
		head = newNode;
	}

	void deletion_atStart() {
		Node* temp = head;
		if (temp == NULL)
			cout << "\nList is Empty";
		else {
			head = head->next;
			delete temp;
		}
	}

	void deletion_byLoc(int loc) {
		Node* temp = head, *prevNode = NULL;
		int len = getLengthOfLL();

		if (head == NULL) {
			cout << "\nList empty." << endl;
			return;
		}
		if (len < loc) {
			cout << "\nIndex out of range" << endl;
			return;
		}

		if (loc == 1) {
			head = head->next;
			delete temp;
			return;
		}

		// Traverse the list to find the node to be deleted.
		while (loc-- > 1) {
			prevNode = temp;
			temp = temp->next;
		}

		// Change the next pointer of the previous node.
		prevNode->next = temp->next;

		delete temp;
	}

	void deletion(int delProjID) {
		Node* temp = head;
		Node* prevNode = temp;

		if (temp == NULL) {
			printf("\nList is Empty");
		}
		else {
			// For getting the index of entered project ID
			int ind = 0;
			Node* tp_mid = head;
			while (tp_mid != 0) {
				ind++;
				if (tp_mid->projInfoObj.projId == delProjID) { break; }
				tp_mid = tp_mid->next;
			}

			if (temp->projInfoObj.projId == delProjID) {
				cout << "\nDeleted from Start.";
				deletion_atStart();
			}
			else {
				cout << "\nDeleted from Loc.";
				deletion_byLoc(ind);
			}
			cout << "\nDeletion Done.";
		}

	}

	void updatation(int updProjID) {
		cout << "\nYou requested for this project & Existing details are:\n";
		getProjDetails_byProjID(updProjID);

		int existingNoOfMembers, newNoOfMembers_int;
		string existingProjName, newProjName, existingProjDate, newProjDate, st, newNoOfMembers_str;

		Node* existingProjInfoObj = getProjObj_byProjID(updProjID);
		existingProjName = existingProjInfoObj->projInfoObj.projName;
		existingProjDate = existingProjInfoObj->projInfoObj.projDate;
		existingNoOfMembers = existingProjInfoObj->projInfoObj.noOfMembers;

		cout << "\nEnter the updated values: "; getline(cin, st);
		cout << "\n-> Project Name: ";			getline(cin, newProjName);
		cout << "-> Project Date: ";			getline(cin,newProjDate);
		cout << "-> Project Members: ";			getline(cin, newNoOfMembers_str);
		// User is supposed to press Enter if they doesn't want to update any attribute
		if (newProjName.empty()) { newProjName = existingProjName; }
		if (newProjDate.empty()) { newProjDate = existingProjDate; }
		if (newNoOfMembers_str.empty()) { newNoOfMembers_int = existingNoOfMembers; }
		else {newNoOfMembers_int = convert_str_to_int(newNoOfMembers_str); }

		ProjInfo newObj(updProjID, newProjName, newProjDate, newNoOfMembers_int);

		Node* temp = head;
		while (temp) {
			if (temp->projInfoObj.projId == updProjID) {
				temp->projInfoObj = newObj;
				break;
			}
			temp = temp->next;
		}
	}

	void traversing() {
		Node* temp = head;

		if (head == NULL) {
			cout << "\nLinked List is Empty!" << endl;
			return;
		}
		cout << "\nNodes of Linked List -> ";

		while (temp != NULL) {
			temp->projInfoObj.DisplayProjInfoObj();
			temp = temp->next;
		}
	}

	bool searchProjID(int projID) {
		bool flag = false;
		Node* temp = head;
		while (temp) {
			if (temp->projInfoObj.projId == projID) {
				flag = true;
				break;
			}
			temp = temp->next;
		}
		return flag;
	}

	void getProjDetails_byProjID(int srcProjID) {
		Node* temp = head;
		while (temp) {
			if (temp->projInfoObj.projId == srcProjID) {
				temp->projInfoObj.DisplayProjInfoObj();
				break;
			}
			temp = temp->next;
		}
	}

	Node* getProjObj_byProjID(int projID) {
		Node* temp = head;
		while (temp) {
			if (temp->projInfoObj.projId == projID) {
				return temp; 
			}
			temp = temp->next;
		}
	}

	int convert_str_to_int(string st)
	{
		int num = 0;
		int len = st.length();

		for (int i = 0; i < len; i++) {
			// Subtract 48 from the current digit as ASCII of 0 - 9 start from 48 – 57
			num = num * 10 + (st[i] - 48);
		}
		return num;
	}
};
int main()
{
	Linkedlist LLobj;
	while (true) {
		int choice, lengthOfLL, srcProjId;
		bool isProjectIdFound;
		int projId, noOfMembers;	// Insertion Variables
		string projName,projDate;
		int delProjId, updProjId;	// Deletion/Upd Variables

		cout << "\n\nLinked List operation: ";
		cout << "\n\t1. Insertion ";
		cout << "\n\t2. Deletion ";
		cout << "\n\t3. Updatation ";
		cout << "\n\t4. Traversing ";
		cout << "\n\t5. Searching By Project ID ";
		cout << "\n\t6. Exit ";

		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter the Project Info: ";
			cout << "\n-> Project Id: ";	cin >> projId;
			cout << "-> Project Name: ";	cin >> projName;
			cout << "-> Project Date: ";	cin >> projDate;
			cout << "-> Project Members: "; cin >> noOfMembers;
			cout<<"\nPerforming Insertion Operation...";
			LLobj.insertion(projId, projName, projDate, noOfMembers);
			cout << "\nInsertion Done.";
			break;
		case 2:
			cout << "\nEnter the Project ID: "; cin >> delProjId;
			isProjectIdFound = LLobj.searchProjID(delProjId);
			if (isProjectIdFound) {
				cout << "\nProject ID found.\nPerforming Deletion Operation...";
				LLobj.deletion(delProjId);
			}
			else { cout << "\nProject doesn't exist!"; }
			break;
		case 3:
			cout << "\nEnter the Project ID: "; cin >> updProjId;
			isProjectIdFound = LLobj.searchProjID(updProjId);
			if (isProjectIdFound) {
				cout << "\nProject ID found.\nPerforming Updatation Operation...";
				LLobj.updatation(updProjId);
			}
			else { cout << "\nProject doesn't exist!"; }
			break;
		case 4:
			lengthOfLL = LLobj.getLengthOfLL();
			cout << "\nLenght of Project Linked List: " << lengthOfLL<<endl;
			LLobj.traversing();
			break;
		case 5:
			cout << "\nEnter the Project ID: "; cin >> srcProjId;
			isProjectIdFound = LLobj.searchProjID(srcProjId);
			if (isProjectIdFound) {
				cout << "\nProject ID found.";
				LLobj.getProjDetails_byProjID(srcProjId);
			}
			else { cout << "\nProject doesn't exist!"; }
			break;
		case 6:
			exit(1);
		default:
			cout << "Invalid choice!";
		}
	}
	return 0;
}
*/