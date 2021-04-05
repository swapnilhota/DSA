#include<bits/stdc++.h>

using namespace std;

class Node
{
public:

    int data;
    Node* next;
};


//adds node at the front
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = *head_ref;

    *head_ref = new_node;
}

//deletes node carrying val iteratively
void deleteNode(Node** head_ref, int val)
{
    Node* temp = *head_ref;
    Node* prev = NULL;

    if(temp!=NULL && temp->data == val)
    {
        *head_ref = temp->next;
        delete temp; //free memory
        return;
    }

    while(temp != NULL && temp->data!=val)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL)
    {
        //this means val not present in list
        return;
    }

    prev->next = temp->next;

    delete temp;

    return;

}

void printList(Node* node)
{
    while(node!=NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{

    Node* head = NULL;

    // Add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printList(head);

    deleteNode(&head, 1);

    printList(head);

    return 0;
}
