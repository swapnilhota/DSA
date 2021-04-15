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

void push(Node** headRef, int val) {
	Node* newNode = new Node();
	newNode->data = val;
	newNode->next = NULL;

	if(*headRef==NULL) {
		*headRef = newNode;
		return;
	}

	newNode->next = *headRef;
	*headRef = newNode;
	return;
}

void printList(Node* head) {
	cout << "-------LIST-------" << endl;
	while(head!=NULL) {
		cout << head->data << " ";
		head=head->next;
	}
	cout << endl;
	return;
}

void deleteList(Node** headRef) {
	if(*headRef==NULL) {
		return;
	}
	Node* current = *headRef;
	Node* next = NULL;

	while(current!=NULL) {
		next = current->next;
		free(current);
		current=next;
	}

	*headRef=NULL;
	return;
}

int main() {

	Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	printList(head);

	deleteList(&head);

	printList(head);

	return 0;
}