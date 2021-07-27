// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

// using inorder traversal and sorting and updating node values


/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    int cntr = 0;
    vector<int> trav; // SC:O(n)
    
    void inorderTrav(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        inorderTrav(root->left);
        trav.push_back(root->data);
        inorderTrav(root->right);
    }
    
    void convert(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        convert(root->left);
        root->data = trav[cntr];
        cntr++;
        convert(root->right);
    }
    Node *binaryTreeToBST (Node *root)
    {
        inorderTrav(root);
        sort(trav.begin(),trav.end()); // TC: O(nlogn)
        convert(root);
        return root;
        
    }
};
