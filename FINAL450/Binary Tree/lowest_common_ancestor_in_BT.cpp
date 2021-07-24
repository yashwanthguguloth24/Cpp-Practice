// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// https://www.educative.io/edpresso/how-to-find-the-lowest-common-ancestor-in-binary-tree


// Using leftSubtree and rightSubtree to get the answer

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL)
       {
           return NULL;
       }
       else if(root->data == n1 || root->data == n2)
       {
           return root;
       }
       
       Node* leftFound = lca(root->left,n1,n2);
       Node* rightFound = lca(root->right,n1,n2);
       if(leftFound != NULL && rightFound != NULL)
       {
           return root;
       }
       else if(leftFound != NULL)
       {
           return leftFound;
       }
       else if(rightFound != NULL)
       {
           return rightFound;
       }
       return NULL;   
       
       
       
    }
};
