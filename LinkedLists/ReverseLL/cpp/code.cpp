#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* next;
	int data;
	Node(int val) {
		next=NULL;
		data=val;
	}
};

void push(Node** headRef, int newData) {
	Node* newNode = new Node(newData);
	if(*headRef==NULL) {
		*headRef=newNode;
		return;
	}
	newNode->next=*headRef;
	*headRef=newNode;
	return;
}

void printList(Node* head) {
	while(head!=NULL) {
		cout << head->data <<  " ";
		head=head->next;
	}
	cout << endl;
}

int main() {

	Node* head=NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);

	printList(head);

	return 0;
}