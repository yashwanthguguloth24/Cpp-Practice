// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

// Approach similar to "MERGE K SORTED ARRAYS" , pushing head node first then poping min node and pushing next node of min node  and continue..

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

class myComparator
{
public:
    bool operator()(Node* n1,Node* n2)
    {
        return (n1->data > n2->data);
    }
};
 




class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        Node* head = new Node(0);
        Node* root = head;
        
        priority_queue<Node*,vector<Node*>,myComparator> mnheap;
        
        for(int i = 0;i<K;i++)
        {
            Node* node = arr[i];
            mnheap.push(node);
        }
        
        while(!mnheap.empty())
        {
            Node* top_pair = mnheap.top();
            mnheap.pop();
            Node* newnode = new Node(top_pair->data);
            root->next = newnode;
            root = newnode;
            
            if(top_pair->next != NULL)
            {
                mnheap.push(top_pair->next);
            }
            
        }
        
        return (head->next);
        
        
    }
};
