// https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/

// Post Order Traversal with global variable ANS, and sum from root , root left and root right node

#include<iostream>
using namespace std;


class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }

};

class Solution
{
    public:
        int ans = -1;

        int LargestSubtreeSum(Node* root)
        {
            if(root == NULL)
            {
                return 0;
            }
            int l = LargestSubtreeSum(root->left);
            int r = LargestSubtreeSum(root->right);

            int sm = l+r+root->data;
            ans = max(ans,sm);
            return sm;
        }
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    Solution s;
    int a = s.LargestSubtreeSum(root);
    cout << s.ans << endl;
    return 0;
}
