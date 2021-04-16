#include <bits/stdc++.h>
using namespace std;

//Floyd's cycle detection

class Node
{
public:
	Node* next;
	int data;
	bool visited;
	int sn;

	Node(int data) {
		this.data = data;
		next=NULL;
		visited=false;
	}	
};

void push(Node** headRef, int val) {
	Node* newNode = new Node(val);

	if(*headRef==NULL) {
		headRef=newNode;
		return;
	}

	newNode->next = *headRef;
	*headRef = newNode;
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

int main() {

	Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);

	return 0;
}