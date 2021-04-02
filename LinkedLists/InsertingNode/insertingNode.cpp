#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

//insert a node in the front of the list
void addFront(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{

    if(prev_node==NULL)
    {
        cout << "Given node is null" << endl;
        return;
    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

int main()
{
    return 0;
}
