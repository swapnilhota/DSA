#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
	Node* next;
	int data;
	 Node() {
	 	next = NULL;
	 	data = 0;
	 }
	
};

void push(Node** headRef, int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	if(*headRef == NULL) {
		*headRef = newNode;
		return;
	}

	newNode->next = *headRef;
	*headRef = newNode;
	return;
}

void printList(Node* head) {
	if(head==NULL) {
		return;
	}

	Node* temp = head;

	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

	return;
}

void listLength(Node* head) {
	int len=0;
	while(head!=NULL) {
		len++;
		head=head->next;
	}
	cout << "Length of List = " << len << endl;
	return;
}

int main() {

	Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);

	printList(head);

	listLength(head);

	return 0;

}