// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

// using slow ptr and fast ptr and the extra distance covered 

// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node* detectLoop(Node* head)
    {
        // your code here
        struct Node * fast_ptr = head;
        struct Node * slow_ptr = head;
        while(fast_ptr->next != NULL && fast_ptr->next->next != NULL && slow_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(fast_ptr == slow_ptr)
            {
                return slow_ptr;
            }
        }
        return NULL;
    }
    
    
    
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node * fast_ptr = detectLoop(head);
        Node * start_ptr;
        if(fast_ptr != NULL)
        {
            if(fast_ptr == head)
            {
                start_ptr = head;
                while(start_ptr->next != head)
                {
                    start_ptr = start_ptr->next;
                }
                start_ptr->next = NULL;
            }
            else
            {
                start_ptr = head;
                while(start_ptr->next != fast_ptr->next)
                {
                    start_ptr = start_ptr->next;
                    fast_ptr = fast_ptr->next;
                }
                fast_ptr->next = NULL;
            }
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends
