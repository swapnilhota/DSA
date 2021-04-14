#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;

	Node() {
		next=NULL;
		data=0;
	}	
};

void push(Node** headRef, int newData) {
	Node* newNode = new Node();
	newNode->data=newData;
	newNode->next=NULL;

	if(*headRef==NULL) {
		*headRef=newNode;
		return;
	}

	newNode->next=*headRef;
	*headRef=newNode;
	return;
}

void printList(Node* head) {
	if(head==NULL) {
		return;
	}

	while(head!=NULL) {
		cout << head->data << " ";
		head=head->next;
	}
	cout << endl;
}

void findVal(Node* head, int val) {
	if(head==NULL) {
		cout << "Head provided is NULL" << endl;
		return;
	}

	while(head!=NULL) {
		if(head->data == val) {
			cout << "FOUND" << endl;
			break;
		}
		head=head->next;
	}

	if(head==NULL) {
		cout << "NOT FOUND" << endl;
	}
}

int main() {

	Node* head=NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);

	printList(head);

	findVal(head, 100);

	return 0;
}