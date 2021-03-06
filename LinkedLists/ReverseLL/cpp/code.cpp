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

void reverse(Node** head) {
	Node* curr = *head;
	Node* prev=NULL;
	Node* next=NULL;

	while(curr!=NULL) {
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}

	*head=prev;
}

int main() {

	Node* head=NULL;
	push(&head, 78);
	push(&head, 2);
	push(&head, 33);
	push(&head, 41);
	push(&head, 59);

	printList(head);

	reverse(&head);

	printList(head);

	return 0;
}