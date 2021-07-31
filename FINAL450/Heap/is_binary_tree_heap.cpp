// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#

// Checking conditions recursively bottom up


//Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(struct Node * tree)
    {
        if(tree == NULL)
        {
            return true;
        }
        
        if(tree->right && tree->left)
        {
            return ((tree->data > tree->right->data) && (tree->data > tree->left->data) && isHeap(tree->right) && isHeap(tree->left)); 
        }
        else if(tree->right)
        {
            return false; // it should be a complete binary tree
        }
        else if(tree->left)
        {
            return ((tree->data > tree->left->data) && isHeap(tree->right) && isHeap(tree->left)); 
        }
        else
        {
            return (isHeap(tree->right) && isHeap(tree->left)); 
        }
    }
};
