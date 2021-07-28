// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

// Do inorder traversal while decrementing K


/*Complete the function below

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

class Solution{
  public:
    int ans = -1;
    void Inorder(Node *root, int &K)
    {
        if(root == NULL)
        {
            return;
        }
        Inorder(root->left,K);
        K--;
        if(K == 0)
        {
            ans = root->data;
        }
        else if(K < 0)
        {
            return;
        }
        Inorder(root->right,K);
    }
    int KthSmallestElement(Node *root, int K)
    {
        Inorder(root,K);
        return ans;        
    }
};
