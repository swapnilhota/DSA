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
		cout << head->data << " ";
		head=head->next;
	}
	cout << endl;
	return;
}

void removeDuplicate(Node* head) {
	if(head==NULL) {
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL) {
		if(temp->data == temp->next->data) {
			Node* tmp = temp->next->next;
			free(temp->next);
			temp->next = tmp;
		}
		else {
			temp=temp->next;	
		}		
	}
}

int main() {

	Node* head=NULL;
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	printList(head);

	removeDuplicate(head);

	printList(head);

	return 0;
}