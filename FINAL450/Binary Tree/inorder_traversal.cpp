// https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/

// ************************RECURSIVE***********************************
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    vector<int> ans;
    void inOrderRec(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        inOrderRec(root->left);
        ans.push_back(root->data);
        inOrderRec(root->right);
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        inOrderRec(root);
        return ans;
    }
};


// ******************* ITERATIVE *************************************

class Solution {
  public:

    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> stk;
        Node* curr = root;
        while(stk.size() != 0 || curr != NULL)
        {
            if(curr != NULL)
            {
                stk.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stk.top();
                stk.pop();
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        return ans;
        
        
    }
};
