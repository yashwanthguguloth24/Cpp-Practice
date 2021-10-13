class Solution {
public:
    int ans = INT_MIN;
    int solve(Node* root)
    {
        if(root == NULL) return INT_MIN;
        
        if(root->left == NULL and root->right == NULL)
        {
            return root->data;
        }
        
        int l = solve(root->left);
        int r = solve(root->right);
        int res = max(l,r)+root->data;
        if(root->left != NULL and root->right != NULL)
        {
            ans = max(ans,l+r+root->data);
        }
        return res;

    }
    
    
    int maxPathSum(Node* root)
    {
        int a = solve(root);
        if(ans == INT_MIN)
        {
            return a;
        }
        return ans;
    }
};
