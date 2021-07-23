// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

// top down traversal , with variable CURRSUM,LEVEL and global variable MAXSUM,MAXLEVEL and check conditions

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int max_level = -1;
    int max_sum = -1;
    
    void LongPathUtil(Node* root,int level,int curr_sum)
    {
        if(root == NULL)
        {
            return ;
        }
        curr_sum += root->data;
        if(root->left == NULL && root->right == NULL)
        {
            // leaf node
            if(level >= max_level)
            {
                max_level = level;
                max_sum = max(max_sum,curr_sum);
            }
        }
        LongPathUtil(root->left,level+1,curr_sum);
        LongPathUtil(root->right,level+1,curr_sum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        LongPathUtil(root,0,0);
        return max_sum;
    }
};
