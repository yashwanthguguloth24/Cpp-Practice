#include<bits/stdc++.h>
using namespace std;
 
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
 
// A utility function to create a new node
Node *newNode(int data)
{
    struct Node* new_node = new Node;
    new_node->data  = data;
    new_node->next = NULL;
    return new_node;
}
 

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "add" << temp << "  ";
        temp = temp->next;
    }
}
// Function to make two separate lists and return
// head after concatenating
struct Node *partition(struct Node *head, int x)
{
    /* Let us initialize first and last nodes of
      three linked lists
        1) Linked list of values smaller than x.
        2) Linked list of values equal to x.
        3) Linked list of values greater than x.*/
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;
    struct Node *root = head;
    // Now iterate original list and connect nodes
    // of appropriate linked lists.
    while (head != NULL)
    {
        // If current node is equal to x, append it
        // to the list of x values
        if (head->data == x)
        {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else
            {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }
 
        // If current node is less than X, append
        // it to the list of smaller values
        else if (head->data < x)
        {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else
            {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else // Append to the list of greater values
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else
            {
                greaterLast->next  = head;
                greaterLast = head;
            }
        }
 
        head = head->next;
    }
    printList(root);
    cout << endl;
    // Fix end of greater linked list to NULL if this
    // list has some nodes
    if (greaterLast != NULL)
        greaterLast->next = NULL;
 
    // Connect three lists
 
    // If smaller list is empty
    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }

    // cout << "here1" << endl;
    printList(root);
    // cout << "here2" << endl;
    cout << endl;  
 
    // If smaller list is not empty
    // and equal list is empty
    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        printList(root);
    // cout << "here2" << endl;
        cout << endl;
        return smallerHead;
    }
 
    // If both smaller and equal list
    // are non-empty
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;

  
    return  smallerHead;
}
 
/* Function to print linked list */

 
// Driver program to run the case
int main()
{
    /* Start with the empty list */
    struct Node* head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(2);
    head->next->next->next = newNode(10);
    // head->next->next->next->next = newNode(2);
    // head->next->next->next->next->next = newNode(50);
 
    int x = 3;
    head = partition(head, x);
    printList(head);
    return 0;
}
