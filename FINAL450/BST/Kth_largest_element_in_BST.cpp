// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#

// Do reverse inorder traversal while decrementing K

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int ans = -1;
    void Inorder(Node *root, int &K)
    {
        if(root == NULL)
        {
            return;
        }
        Inorder(root->right,K);
        K--;
        if(K == 0)
        {
            ans = root->data;
        }
        else if(K < 0)
        {
            return;
        }
        Inorder(root->left,K);
    }
    
    int kthLargest(Node *root, int K)
    {
        Inorder(root,K);
        return ans;
    }
};
