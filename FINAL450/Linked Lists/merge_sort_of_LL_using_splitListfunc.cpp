// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* splitList(Node **head)
    {
        // base condition
        if(*head == NULL)
        {
            return NULL;
        }
        Node * slow = *head;
        Node *fast = *head;
        fast = fast->next;
    
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node* merge(Node* l1,Node* l2)
    {
        Node* temp1 = l1;
        Node* temp2 = l2;
        Node* newList = new Node(0);
        Node* temp = newList;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data > temp2->data)
            {
                Node* dummy = new Node(temp2->data);
                temp->next = dummy;
                temp2 = temp2->next;
            }
            else
            {
                Node* dummy = new Node(temp1->data);
                temp->next = dummy;
                temp1 = temp1->next;
            }

            temp = temp->next;
        }
        
        while(temp1 != NULL)
        {
            Node* dummy = new Node(temp1->data);
            temp->next = dummy;
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2 != NULL)
        {
            Node* dummy = new Node(temp2->data);
            temp->next = dummy;
            temp = temp->next;
            temp2 = temp2->next;
        }
        // printL(newList);
        return newList->next;
    }
    
    void printL(Node* head)
    {
        while(head != NULL)
        {
            cout << head->data << " ";
        }
        cout << endl;
    }
    
    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        Node* slow = splitList(&head);
        Node* newhead = slow->next;
        slow->next = NULL;
        return merge(mergeSort(head),mergeSort(newhead));
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
