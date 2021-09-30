// https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/

// https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

// HARDD

void swap(Node**n1,Node**n2)
{
    int temp = (*n1)->data;
    (*n1)->data = (*n2)->data;
    (*n2)->data = temp;
    
}



void CalcPointers(Node* root,Node**start,Node**mid,Node**end,Node**prev)
{
    if(root == NULL)
    {
        return;
    }
    CalcPointers(root->left,start,mid,end,prev);
    if((*prev != NULL) && (root->data < (*prev)->data))
    {
        if(*start != NULL)
        {
            *end = root;
        }
        else
        {
            *mid = root;
            *start = *prev;
        }
    }
    *prev = root;
    CalcPointers(root->right,start,mid,end,prev);
}



class Solution {
  public:
    
    void correctBST( struct Node* root )
    {
        Node *prev,*start,*end,*mid;
        prev = start = end = mid = NULL;
        CalcPointers(root,&start,&mid,&end,&prev);
        
        if(start && end)
        {
            swap(&start,&end);
        }
        else
        {
            swap(&start,&mid);
        }
    }
};
