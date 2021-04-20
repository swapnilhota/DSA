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

}

void push(Node** head, int new_data) {
	Node* new_node = new Node(new_data);
	if(*head==NULL) {
		*head=new_node;
		return;
	}
	new_node->next=*head;
	*head = new_node;
	return;
}

void printList(Node* head) {
	while(head!=NULL) {
		cout << head->data << " ";
		head=head->next;
	}
	cout << endl;
}

void removeDuplicate(Node* head) {
	map<int, int> mp;
	Node* temp = head;
	Node* prev = NULL;

	while(temp!=NULL) {
		if(mp[temp->data]>1) {

		}
		else {
			mp[temp]++;

		}
		prev=temp;
		temp=temp->next;
	}
}

int main() {

	Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);

	printList(head);

	removeDuplicate(head);

	printList(head);

	return 0;
}