// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#

// As extra space is allowed, we use different LL's to store even and odd nodes seperately and finally combine both of them to get the answer.

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:

    
    Node* divide(int N, Node *head){
        Node* even_LL = new Node(0);
        Node* odd_LL = new Node(0);
        Node* even_ptr = even_LL;
        Node* odd_ptr = odd_LL;
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data%2 == 0)
            {
                Node* eve_temp = new Node(temp->data);
                even_ptr->next = eve_temp;
                even_ptr = eve_temp;
            }
            else
            {
                Node* odd_temp = new Node(temp->data);
                odd_ptr->next = odd_temp;
                odd_ptr = odd_temp;               
            }
            temp = temp->next;
        }
        if(even_LL->next == NULL && odd_LL->next != NULL)
        {
            return odd_LL->next;
        }
        else if(even_LL->next != NULL && odd_LL->next == NULL)
        {
            return even_LL->next;
        }
        else
        {
            even_LL = even_LL->next;
            odd_LL = odd_LL->next;
            even_ptr->next = odd_LL;
            return even_LL;
        }
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
