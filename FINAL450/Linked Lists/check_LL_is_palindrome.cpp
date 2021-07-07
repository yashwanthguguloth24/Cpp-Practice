// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// reverse half LL and traverse on either sides to check for palindrome.

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int ll_len = 0;
        Node * temp = head;
        while(temp != NULL)
        {
            ll_len++;
            temp = temp->next;
        }
        if(ll_len == 1)
        return 1;
        
        int nums = ll_len/2;
        Node * curr = head;
        Node * prev = NULL;
        int i = 0;
        Node * temp1;
        Node * temp2;
        if(ll_len%2 != 0)
        {
            while(i<=nums)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                i++;
            }
            temp1 = curr;
            temp2 = prev->next;
        }
        else
        {
            while(i<nums)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                i++;
            }
            temp1 = curr;
            temp2 = prev;            
        }
        for(int k = 0;k<nums;k++)
        {
            if(temp1->data != temp2->data)
            {
                return 0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return 1;
        
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
