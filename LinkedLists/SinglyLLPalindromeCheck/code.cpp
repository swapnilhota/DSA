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
	if(head==NULL) {
		cout << "No" << endl;
		return;
	}
	Node* revList = NULL;
	Node* temp = head;
	while(temp!=NULL) {
		push(&revList, temp->data);
		temp=temp->next;
	}
	printList(revList);
	Node* temp2 = revList;
	temp = head;
	while(temp2!=NULL) {
		if((temp->data) != (temp2->data)) {
			cout << "NO" << endl;
			return;
		}
		temp2=temp2->next;
		temp=temp->next;
	}

	cout << "YES" << endl;
	return;
}

int main() {

	Node* head=NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);

	printList(head);

	palindromeCheck(head);

	return 0;
}