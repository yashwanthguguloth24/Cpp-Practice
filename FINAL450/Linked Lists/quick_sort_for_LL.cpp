// https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1#

// Using Quicksort algorithm and using pointers instead of indices to iterate.swaping values of nodes because Quick sort doesnt take extra space unlike mergesort

// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
void printL(node* head)
{
    // for debugging.  
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* partition(node* left,node* right)
{
    // cout << "partition called" << endl;
    // printL(left);
    // taking last element as PIVOT
    node* pivotptr = left;
    node* temp2 = left;
    int pivot = right->data;
    while(temp2 !=  right)
    {
        if(temp2->data <= pivot)
        {
            int tempval = temp2->data;
            temp2->data = pivotptr->data;
            pivotptr->data = tempval;
            pivotptr = pivotptr->next;
            
        }
        temp2 = temp2->next;
    }
    int ntemp = pivotptr->data;
    pivotptr->data = right->data;
    right->data = ntemp;
    // cout << "partition ended" << endl;
    return pivotptr;
}

void quickSortImpl(node *head,node *tail)
{
    // cout << "quicksort Impl called" << endl;
    if(head == tail || head == NULL || tail == NULL)
    {
        return;
    }
    node* piv = partition(head,tail);
    // printL(piv);
    node* temp1 = head;
    // cout << "temp loop start" << endl;
    while(temp1 != piv && temp1->next != piv)
    {
        temp1 = temp1->next;
    }
    // cout << "temp  loop endl " << endl;
    quickSortImpl(head,temp1);
    if(piv != tail)
    {
        quickSortImpl(piv->next,tail);
    }
}

void quickSort(node **headRef) {
    // cout << "quicksort called" << endl;
    node* head = *headRef;
    node*tail = *headRef;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    quickSortImpl(head,tail);
}
