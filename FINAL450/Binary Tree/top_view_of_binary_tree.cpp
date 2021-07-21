// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

// Using level order traversal and map to store width and value corresponding to that width


class Solution
{
    public:
    /*
    width:
        -2        -1      0(root)    1     2
    
    */
    
    // By default MAP container is sorted in key wise order

    
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.size() != 0)
        {
            pair<Node*,int> front = q.front();
            q.pop();
            if(!mp[front.second])
            {
                mp[front.second] = (front.first)->data;
            }
            if((front.first)->left)
            {
                q.push({(front.first)->left,front.second-1});
            }
            if((front.first)->right)
            {
                q.push({(front.first)->right,front.second+1});
            }
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
        
    }


};
