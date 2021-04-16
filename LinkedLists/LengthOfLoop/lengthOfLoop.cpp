#include <bits/stdc++.h>
using namespace std;

//Floyd's cycle detection

class Node
{
public:
	Node* next;
	int data;

	Node(int val) {
		data = val;
		next=NULL;
	}	
};

void push(Node** headRef, int val) {
	Node* newNode = new Node(val);

	if(*headRef==NULL) {
		*headRef=newNode;
		return;
	}

	newNode->next = *headRef;
	*headRef = newNode;
	return;
}

int countNodes(Node* n) {
	int res=1;
	Node* temp = n;
	while(temp->next!=n) {
		res++;
		temp=temp->next;
	}
	return res;
}

int countNodesInLoop(Node* list) {
	Node* slow_p = list;
	Node* fast_p = list;

	while(slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if(slow_p==fast_p) {
			return countNodes(slow_p);
		}
	}

	return 0;
}

void printList(Node* head) {
	while(head!=NULL) {
		cout << head->data << " ";
		head=head->next;
	}
	cout << endl;
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

	head->next->next->next->next->next = head->next;

	cout << countNodesInLoop(head) << endl;

	return 0;
}