// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
// https://www.youtube.com/watch?v=lQIXz5NJYLs&t=886s


// Checking conditions 1.if key is found and root is not leaf then find by extremes according 2. Update pre , suc as we go left and right as they may result to the answer.

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
Node* Inpre(Node* root)
{
    Node* p = root->left;
    while(p->right != NULL)
    {
        p = p->right;
    }
    return p;
}


Node* Insuc(Node* root)
{
    Node* p = root->right;
    while(p->left != NULL)
    {
        p = p->left;
    }
    return p;
}



void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL) return;

    if(root->key == key)
    {
        if(root->left) pre = Inpre(root);
        if(root->right) suc = Insuc(root);
    }
    
    if(key>root->key)
    {
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
    else if(key < root->key)
    {
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
}
