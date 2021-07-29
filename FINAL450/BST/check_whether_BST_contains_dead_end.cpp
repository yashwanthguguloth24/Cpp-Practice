// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

// Using bottom up approach and using BST conditions to chcek when root is null


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

bool checkDeadEnd(Node* root,int mn,int mx,bool &indc)
{
    
    if(root == NULL && (mn >= mx-1 || mx == 1))
    {
        return true;
    }
    else if(root == NULL)
    {
        return false;
    }
    
    

    bool fl = checkDeadEnd(root->left,mn,root->data,indc);
    bool fr = checkDeadEnd(root->right,root->data,mx,indc);
    if(fl && fr) 
    {
        indc = true;
    }
    return (fl && fr);
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    bool flag;
    bool indc = false;
    flag = checkDeadEnd(root,INT_MIN,INT_MAX,indc);
    return indc;
}
