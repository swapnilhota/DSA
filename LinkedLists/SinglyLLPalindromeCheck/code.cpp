#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;
	Node(int val) {
		data=val;
		next=NULL;
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
		cout << head->data << " ";
		head=head->next;
	}
	cout << endl;
}

void palindromeCheck(Node* head) {

}

int main() {

	Node* head=NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printList(head);

	palindromeCheck(head);

	return 0;
}