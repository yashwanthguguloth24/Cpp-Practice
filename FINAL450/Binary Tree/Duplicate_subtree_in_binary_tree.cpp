// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#

// storing all the subtrees in a set to get constant time search to find duplicates


/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    bool isDup = false;
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    vector<int> SubTrees(Node* root,set<vector<int>> &res)
    {
        if(root == NULL)
        {
            vector<int> tmp;
            tmp.push_back(-1);
            return tmp;
        }
        vector<int> temp;
        vector<int> l = SubTrees(root->left,res);
        vector<int> r = SubTrees(root->right,res);
        
        for(int i = 0;i<l.size();i++)
        {
            temp.push_back(l[i]);
        }
        temp.push_back(root->data);
        for(int i = 0;i<r.size();i++)
        {
            temp.push_back(r[i]);
        }
        if(res.find(temp) != res.end() && temp.size() > 3)
        {
            isDup = true;
        }
        else
        {
            res.insert(temp);
        }
        return temp;
        
    }
    
    
    int dupSub(Node *root) {
        set<vector<int>> res;
        vector<int> ans = SubTrees(root,res);
        return isDup;
    }
};
