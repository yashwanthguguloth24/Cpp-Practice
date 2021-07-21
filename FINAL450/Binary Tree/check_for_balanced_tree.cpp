// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

// solved using pair of isbalanced and height, as we need both for every node

/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


 
 
 
pair<int,bool> BalanceCheck(Node* root)
{
    if(root == NULL)
    {
        pair<int,bool> npr(0,true);
        return npr;
    }
    
    pair<int,bool> leftPr = BalanceCheck(root->left);
    pair<int,bool> rightPr = BalanceCheck(root->right);
    
    pair<int,bool> to_ret;
    to_ret.first = 1+max(leftPr.first,rightPr.first);
    to_ret.second = ((abs(leftPr.first-rightPr.first) <= 1) && leftPr.second && rightPr.second);
    return to_ret;
    
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    pair<int,bool> res = BalanceCheck(root);
    return res.second;
    
}
