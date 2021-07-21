// https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/
// https://practice.geeksforgeeks.org/problems/postorder-traversal/1#

//****************** RECURSIVE ****************************************
vector<int> postOrderRec(Node* root,vector<int>&ans)
{
    if(root == NULL)
    {
        return ans;
    }
    postOrderRec(root->left,ans);
    postOrderRec(root->right,ans);
    ans.push_back(root->data);
    return ans;
}
//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
    vector<int>ans;
    postOrderRec(root,ans);
    return ans;
}

//********************** ITERATIVE **************************************

vector <int> postOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> stk;
    stk.push(root);
    stack<int> out;
    Node* curr = root;
    while(stk.size() != 0)
    {
        Node* curr = stk.top();
        stk.pop();
        out.push(curr->data);
        
        if(curr->left)
        stk.push(curr->left);
        
        if(curr->right)
        stk.push(curr->right);

    }
    
    while(out.size() != 0)
    {
        ans.push_back(out.top());
        out.pop();
    }
    return ans;
}


