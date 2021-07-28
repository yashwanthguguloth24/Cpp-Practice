// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

// Direct inorder check to increase counter

void inorderTrav(Node *root, int l, int h,int &cnt)
{
    if(root == NULL) return;
    
    inorderTrav(root->left,l,h,cnt);
    if(root->data >= l && root->data <= h)
    {
        cnt++;
    }
    inorderTrav(root->right,l,h,cnt);
}

//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
    int cnt = 0;
    inorderTrav(root,l,h,cnt);
    return cnt;
}

