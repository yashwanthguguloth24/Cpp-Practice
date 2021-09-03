// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/?problemStatus=unsolved&difficulty[]=1&page=1&company[]=Flipkart&query=problemStatusunsolveddifficulty[]1page1company[]Flipkart#


// using level order traversal and updating the values at each levels


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            pair<Node*,int> top = q.front();
            q.pop();
            Node* node = top.first;
            int level = top.second;
            mp[level].push_back(node->data);
            if(node->left)
            {
                q.push({node->left,level-1});
            }
            if(node->right)
            {
                q.push({node->right,level+1});
            }
        }
        vector<int> ans;
        for(auto x:mp)
        {
            for(int i = 0;i<x.second.size();i++)
            {
                ans.push_back(x.second[i]);
            }
        }
        return ans;
        
    }
};
