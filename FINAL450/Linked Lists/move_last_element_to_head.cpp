// https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

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

Node *  MoveLastElementToHead(Node* head)
{
    // base case
    if(head->next == NULL)
    {
        return head;
    }  
    Node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node * last = temp->next;
    temp->next = NULL;
    last->next = head;
    head = last;
    return head;
}



int main()
{
    Node * head = newNode(1);
    Node * tail = head;
    for(int i = 2;i<10;i++)
    {
        tail->next = newNode(i);
        tail = tail->next;
    }
    printLL(head);
    Node* out = MoveLastElementToHead(head);
    printLL(out);
    return 0;
}
