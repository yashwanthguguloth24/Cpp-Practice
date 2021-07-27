// https://leetcode.com/problems/delete-node-in-a-bst/

// Considering conditions of the found node 1.No child 2.Only left or right 3.Both child

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int FindMax(TreeNode* root)
    {
        while(root->right)
        {
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->val < key)
        {
            root->right = deleteNode(root->right,key);
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }
        else
        {
            if(root->right != NULL && root->left != NULL)
            {
                int Lmax = FindMax(root->left);
                root->val = Lmax;
                root->left = deleteNode(root->left,Lmax);
            }
            else if(root->left != NULL)
            {
                return root->left;
            }
            else if(root->right != NULL)
            {
                return root->right;
            }
            else
            {
                return NULL;
            }
        }
        return root;
    }
};
