#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;
	bool visited;

	Node() {
		next=NULL;
		data=0;
		visited=false;
	}

	Node(int val) {
		next = NULL;
		data = val;
		visited=false;
	}
	
};

void push(Node** headRef, int val) {
	Node* newNode = new Node(val);
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

void detectLoop(Node* head) {
	if(head==NULL) {
		cout << "No Loop" << endl;
		return;
	}

	while(1) {
		if(head->next==NULL) {
			cout << "No Loop" << endl;
			break;
		}
		if(head->visited==true) {
			cout << "Loop Found" << endl;
			break;
		}
		head->visited=true;
		head=head->next;
	}

	return;
}

int main() {

	Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);

	//head->next->next->next->next->next=head;

	detectLoop(head);

	return 0;
}