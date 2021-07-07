// https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#

// read value from linked lists and multiply.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
 
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    
    return new_Node;
}
 
 
 Node *reverse(Node **r)
{
    Node *prev =NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}


void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {

        temp=Node;
        Node = Node->next;
        free(temp);
    }

}

 
/* Multiply contents of two linked lists */
long long  multiplyTwoLists (struct Node* , struct Node*);
 
// A utility function to print a linked list
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
 
/* Driver program to test above function */
int main(void)
{


   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {

    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }

	     reverse(&first);
	     reverse(&second);
		 long long res = multiplyTwoLists(first,second);
	    
	    cout<<res<<endl;
        freeList(first);
        freeList(second);

   }
   return 0;
}
// } Driver Code Ends


/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/




/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/



/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    // long long s1 = CalcLength(l1);
    // long long s2 = CalcLength(l2);
    Node * temp1 = l1;
    Node * temp2 = l2;
    long long val1 = 0;
    long long val2 = 0;
    long long N = 1000000007;
    while(temp1 != NULL)
    {
        val1 = (((val1%N)*10)%N)+temp1->data;
        temp1 = temp1->next;
    }


    //val1 = val1%N;
    while(temp2 != NULL)
    {
        val2 = ((val2%N)*10)%N+temp2->data;
        temp2 = temp2->next;
    }   

    //val2 = val2%N;
    long long ans = ((val1%N)*(val2%N))%N;
    // ans = ans%(pow(10,9)+7);
    return ans;
    
}
