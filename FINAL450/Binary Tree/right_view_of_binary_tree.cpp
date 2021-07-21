// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

// Exactly reverse of left view of tree. Approach is same. Now right node is travsersed first.

class Solution
{
    public:
    void traversal(Node* root,int level,set<int> &s,vector<int> &ans)
    {
        if(root == NULL) return;
        if(s.find(level) == s.end())
        {
            ans.push_back(root->data);
            s.insert(level);
        }
        traversal(root->right,level+1,s,ans);
        traversal(root->left,level+1,s,ans);
    }
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       set<int> s;
       traversal(root,0,s,ans);
       return ans;
    }
};
