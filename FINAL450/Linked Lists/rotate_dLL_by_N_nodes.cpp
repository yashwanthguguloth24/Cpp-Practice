// https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/

// remove head node and attach the node to last


#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next = NULL;
    Node * prev = NULL;
};

Node * newNode(int key)
{
    Node * temp = new Node;
    temp->data = key;
    temp->next = NULL;
    temp->prev = NULL;
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


Node * rotateByN(Node* head,int N)
{
    Node* start = head;
    Node *last = head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    int i = 0;
    while(i<N)
    {
        Node* temp = start;
        start = start->next;
        start->prev = NULL;
        last->next = temp;
        temp->prev = last;
        last = last->next;
        last->next = NULL;
        i++;
    }
    return start;
}

int main()
{
    Node * head = newNode(1);
    Node * tail = head;
    for(int i = 2;i<10;i++)
    {
        Node * temp = newNode(i);
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
    }
    printLL(head);
    int N = 4;
    Node* out = rotateByN(head,N);
    printLL(out);
    return 0;
}
