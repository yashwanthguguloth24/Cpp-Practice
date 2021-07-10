// Using recursive approach to reverse a Linked List


#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next = NULL;
};

Node * newNode(int key)
{
    Node * temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printLL(Node * head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout << temp-> data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* newhead = NULL;
void Reverse_REC(Node **prev,Node **curr)
{
    if(*curr == NULL)
    {
        newhead = *prev;
        return;
    }
    Node* temp = (*curr)->next;
    (*curr)->next = *prev;
    *prev = *curr;
    *curr = temp;
    // Node** newprev = prev;
    // Node** newcurr = curr;
    Reverse_REC(prev,curr);
}

int main()
{
    Node * head = newNode(1);
    Node * tail = head;
    for(int i = 2;i<5;i++)
    {
        tail->next = newNode(i);
        tail = tail->next;
    }
    printLL(head);
    Node* prev = NULL;
    Node *curr = head;
    // reversing the LL
    Reverse_REC(&prev,&curr);
    // print the reversed linked list using recursion
    printLL(newhead);
    return 0;
}
