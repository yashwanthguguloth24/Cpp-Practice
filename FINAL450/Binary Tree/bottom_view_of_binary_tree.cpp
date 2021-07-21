// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// same code as above(Top view) but not restricting to the first occurred node at a width

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.size() != 0)
        {
            pair<Node*,int> front = q.front();
            q.pop();

            mp[front.second] = (front.first)->data;

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
