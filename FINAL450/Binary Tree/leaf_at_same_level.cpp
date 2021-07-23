// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

// storing the levels of all leaf nodes and checking if they are equal or not

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    vector<int> levels;
    
    void checkSameLevel(Node* root,int level)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->right == NULL && root->left == NULL)
        {
            levels.push_back(level);
        }
        checkSameLevel(root->left,level+1);
        checkSameLevel(root->right,level+1);
    }
    
    
    bool check(Node *root)
    {
        checkSameLevel(root,0);
        for(int i = 0;i<levels.size()-1;i++)
        {
            if(levels[i] != levels[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
