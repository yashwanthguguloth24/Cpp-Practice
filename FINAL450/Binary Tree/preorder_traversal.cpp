// https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/
// https://practice.geeksforgeeks.org/problems/preorder-traversal/1#


// **************************RECURSIVE**********************************

void preorderRec(Node* root,vector <int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    preorderRec(root->left,ans);
    preorderRec(root->right,ans);
}
//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    vector <int> ans;
    preorderRec(root,ans);
    return ans;
}


//*************************** ITERATIVE **************************************

vector <int> preorder(Node* root)
{
    vector<int> ans;
    stack<Node*> stk;
    Node* curr = root;
    while(stk.size() != 0 || curr != NULL)
    {
        if(curr != NULL)
        {
            ans.push_back(curr->data);
            stk.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
    }
    return ans;
}
