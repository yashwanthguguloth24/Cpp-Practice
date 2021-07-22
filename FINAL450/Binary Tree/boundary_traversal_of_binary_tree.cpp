// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Dividing into 3 sub problems. 1.left boundary 2.leaf nodes 3.right boundary

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void LeftBoundary(Node* root,vector<int> &ans)
    {
        if(root == NULL) return;
        
        if(root->left)
        {
            ans.push_back(root->data);
            LeftBoundary(root->left,ans);
            
        }
        else if(root->right)
        {
            ans.push_back(root->data);
            LeftBoundary(root->right,ans);
        }
    }

    void LeafNode(Node* root,vector<int> &ans)
    {
        if(root == NULL) return ;
        // inorder traversal
        LeafNode(root->left,ans);
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        LeafNode(root->right,ans);
    }
    
    void rightBoundary(Node* root,vector<int> &ans)
    {
        // BottomUp
        if(root == NULL) return ;
        
        if(root->right)
        {
            rightBoundary(root->right,ans);
            ans.push_back(root->data);
        }
        else if(root->left)
        {
            rightBoundary(root->left,ans);
            ans.push_back(root->data);
        }
    }
    
    vector <int> printBoundary(Node *root)
    {
        /*
        1.Left boundary
        2.Leaf nodes
        3.Right boundary
        */
        vector<int> ans;
        ans.push_back(root->data);
        LeftBoundary(root->left,ans);
        LeafNode(root,ans);
        rightBoundary(root->right,ans);
        return ans;
        
        
        
    }
};
