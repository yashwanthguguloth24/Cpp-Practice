// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

// Solved using 2 approaches 1.direct rec 2. using BST prop in rec

Node* constructTreeUtil(int pre[],int &preind,int key,int mn,int mx,int size)
{
    if(preind >= size)
    {
        return NULL;
    }

    Node* root = NULL;
    if(key > mn && key < mx)
    {
        root = newNode(key);
        preind++;
        
        if(preind < size)
        root->left = constructTreeUtil(pre,preind,pre[preind],mn,key,size);
        
        if(preind < size)
        root->right = constructTreeUtil(pre,preind,pre[preind],key,mx,size);
        
    }
    return root;
}



Node* constructTree(int pre[], int size)
{
    int preind = 0;
    Node* root = constructTreeUtil(pre,preind,pre[preind],INT_MIN,INT_MAX,size);
    return root;
}
