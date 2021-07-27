// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#

// using BST property to move left and right accordingly


Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }
    
    int temp = root->data;
    if(n1>temp && n2>temp)
    {
        Node* rfound = LCA(root->right,n1,n2);
        return rfound;
    }
    else if(n1<temp && n2<temp)
    {
        Node* lfound = LCA(root->left,n1,n2);
    }
    else
    {
        return root;
    }
    
}
