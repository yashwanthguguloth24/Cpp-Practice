// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

// merge such that every time K reduces to K/2

// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

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

class Solution{
  public:
    //Function to merge K sorted linked list.
    // recursive function to merge.
    Node* mergeBoth(Node* l1,Node* l2)
    {
        Node* res = NULL;
        if(l1 == NULL) return (l2);
        else if(l2 == NULL) return (l1);
        if(l1->data <= l2->data)
        {
            res = l1;
            res->next = mergeBoth(l1->next,l2);
        }
        else
        {
            res = l2;
            res->next = mergeBoth(l1,l2->next);            
        }
        return res;
    }
    /* Iterative function for merge works correct
    */
    // Node* mergeBoth(Node* l1,Node* l2)
    // {
    //     Node* temp1 = l1;
    //     Node* temp2 = l2;
    //     Node* newList = new Node(0);
    //     Node* temp = newList;
    //     while(temp1 != NULL && temp2 != NULL)
    //     {
    //         if(temp1->data > temp2->data)
    //         {
    //             Node* dummy = new Node(temp2->data);
    //             temp->next = dummy;
    //             temp2 = temp2->next;
    //         }
    //         else
    //         {
    //             Node* dummy = new Node(temp1->data);
    //             temp->next = dummy;
    //             temp1 = temp1->next;
    //         }

    //         temp = temp->next;
    //     }
        
    //     while(temp1 != NULL)
    //     {
    //         Node* dummy = new Node(temp1->data);
    //         temp->next = dummy;
    //         temp = temp->next;
    //         temp1 = temp1->next;
    //     }
    //     while(temp2 != NULL)
    //     {
    //         Node* dummy = new Node(temp2->data);
    //         temp->next = dummy;
    //         temp = temp->next;
    //         temp2 = temp2->next;
    //     }
    //     // printL(newList);
    //     return newList->next;
    // }

    
    Node * mergeKLists(Node *arr[], int K)
    {
        int f = 0;
        int last = K-1;
        int curr_last;
        while(last)
        {
            f = 0;
            curr_last = last;
            while(f<curr_last)
            {
                arr[f] = mergeBoth(arr[f],arr[curr_last]);
                f++;
                curr_last--;
            }
            if(f>=curr_last) last = curr_last;
        }
        return arr[0];
        
        
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends
