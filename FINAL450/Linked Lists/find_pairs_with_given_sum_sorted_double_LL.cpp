// https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/

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

void FindPairsGivenSum(Node* head,int k)
{
    Node* first = head;
    Node* last = head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    while(first->data < last->data)
    {
        if(first->data+last->data == k)
        {
            cout << "(" << first->data << "," << last->data << ")" << endl;
            first = first->next;
            last = last->prev;
        }
        else if(first->data+last->data < k)
        {
            first = first->next;
        }
        else
        {
            last = last->prev;
        }
    }
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
    int k = 5;
    FindPairsGivenSum(head,k);
    return 0;
}
