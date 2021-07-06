// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#

// iteration and if conditions

// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverseList(struct Node *head)
    {
        // code here
        Node * curr = head;
        Node * prev = NULL;
        while(curr != NULL)
        {
            Node * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        Node * headOld = new Node(0);
        Node * head = headOld;
        int carry = 0;
        int to_set;
        while(first != NULL && second != NULL)
        {
            int curr_sum = 0;
            curr_sum = first->data+second->data;
            if(curr_sum+carry > 9)
            {
                curr_sum += carry;
                to_set = curr_sum%10;
                carry = curr_sum/10;
            }
            else
            {
                to_set = curr_sum+carry;
                carry = 0;
            }
            Node * temp = new Node(to_set);
            head->next = temp;
            head = head->next;
            first = first->next;
            second = second->next;
        }
        while(first != NULL)
        {
            int curr_sum = 0;
            curr_sum = first->data;
            if(curr_sum+carry > 9)
            {
                curr_sum += carry;
                to_set = curr_sum%10;
                carry = curr_sum/10;
            }
            else
            {
                to_set = curr_sum+carry;
                carry = 0;
            }
            Node * temp = new Node(to_set);
            head->next = temp;
            head = head->next;
            first = first->next;
        }
        
        
        while(second != NULL)
        {
            int curr_sum = 0;
            curr_sum = second->data;
            if(curr_sum+carry > 9)
            {
                curr_sum += carry;
                to_set = curr_sum%10;
                carry = curr_sum/10;
            }
            else
            {
                to_set = curr_sum+carry;
                carry = 0;
            }
            Node * temp = new Node(to_set);
            head->next = temp;
            head = head->next ;
            second = second->next;
        }
        if(carry != 0)
        {
            Node * temp = new Node(carry);
            head->next = temp;
            head = head->next;
        }
        headOld = reverseList(headOld->next);
        return headOld;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
