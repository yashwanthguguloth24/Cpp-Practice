// https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/

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

void FindTripletsGivenSum(Node* head,int k)
{
    Node* first = head;
    Node* last = head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    Node* temp1;
    Node* temp2;
    int s;
    while(first->data != last->data)
    {
        temp1 = first->next;
        temp2 = last;
        s = k-first->data;
        while(temp1->data < temp2->data)
        {
            if(temp1->data+temp2->data == s)
            {
                cout << "(" << first->data << "," << temp1->data << "," << temp2->data << ")" << endl;
                temp1 = temp1->next;
                temp2 = temp2->prev;
            }
            else if(temp1->data+temp2->data < s)
            {
                temp1 = temp1->next;
            }
            else
            {
                temp2 = temp2->prev;
            }
        }
        first = first->next;
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
    int k = 17;
    FindTripletsGivenSum(head,k);
    return 0;
}
