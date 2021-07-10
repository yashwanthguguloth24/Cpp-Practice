// https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/

// making recursive function calls and taking care of edge cases

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

Node* reverseByGroupsDLL(Node*head,int k)
{
        if(head == NULL) return NULL;
        head->prev = NULL; //  this condition is necessary else every thing will be connected like a circular LL
        Node * next_iter;
        Node * prev = NULL;
        Node * curr = head;
        int cnt = 0;
        while(curr != NULL && cnt < k)
        {
            next_iter = curr->next;
            curr->next = curr->prev;
            curr->prev = next_iter;
            prev = curr;
            curr = next_iter;
            cnt++;
        }
        if(next_iter != NULL)
        {
            head->next = reverseByGroupsDLL(next_iter,k);
            head->next->prev = head;
        }
        return prev;
        
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
    Node* out = reverseByGroupsDLL(head,2);
    printLL(out);
    return 0;
}
