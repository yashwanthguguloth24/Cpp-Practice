// https://www.geeksforgeeks.org/deletion-circular-linked-list/

// checking and deleting and taking care of base cases.

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
    while(temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}

Node * removeNode(Node * head,int k)
{
    Node * curr = head;
    Node * prev = NULL;
    if(head->next == head)
    {
        return NULL;
    }
    if(head->data == k)
    {
        Node * last = head;
        while(last->next != head)
        {
            last = last->next;
        }
        prev = head->next;
        last->next = prev;
        return prev;
    }
    while(curr->next != head)
    {
        if(curr->data == k)
        {
            break;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    prev->next = curr->next;
    return head;
}



int main()
{
    Node * head = newNode(1);
    Node * tail = head;
    for(int i = 2;i<8;i++)
    {
        tail->next = newNode(i);
        tail = tail->next;
    }
    tail->next = head; // looping..
    printLL(head);
    Node *out = removeNode(head,7);
    printLL(out);
    return 0;
}
