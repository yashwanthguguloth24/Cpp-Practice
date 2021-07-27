// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

// traverse through the extreme left to min

int minValue(Node* root)
{
    
    while(root->left != NULL)
    {
        root = root->left;        
    }
    return root->data;
}
