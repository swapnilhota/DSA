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

int main()
{

}
