// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

// Using iteration and skkiping common elements

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            Node * temp1 = temp;
            while(temp->next != NULL && temp->data == temp->next->data)
            {
                temp = temp->next;
            }
            if(temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                temp = NULL;
            }
            temp1->next = temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
