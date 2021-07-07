// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#

// iterate from end(so reverse it,since it is singly LL) to keep updating the max value and checking with the max value

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    Node* reverseList(Node *head)
    {
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
    
    
    Node *compute(Node *head)
    {
        head = reverseList(head);
        Node*prev = NULL;
        Node*curr = head;
        int max_val = -1;
        while(curr != NULL)
        {
            if(curr->data < max_val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                max_val = curr->data;
                prev = curr;
                curr = curr->next;
            }
        }
        head = reverseList(head);
        return head;
        
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends

