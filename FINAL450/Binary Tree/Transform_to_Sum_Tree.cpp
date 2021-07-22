// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

// Used that pair method, as we need both changedSum and originalSum, created a class Node with orgVal,ChangeVal

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


// custom created.
class NewNode
{
    public:
        int ChangeVal;
        int OrgVal;
        
        NewNode(int a,int b)
        {
            ChangeVal = a;
            OrgVal = b;
        }
};


class Solution {
  public:
    NewNode* toSumTreeUtil(Node* node)
    {
        if(node == NULL)
        {
            NewNode* temp = new NewNode(0,0);
            return temp;
        }
        NewNode* LeftNode = toSumTreeUtil(node->left);
        NewNode* RightNode = toSumTreeUtil(node->right);
        
        int temp = node->data;
        node->data = (LeftNode->ChangeVal)+(LeftNode->OrgVal)+(RightNode->ChangeVal)+(RightNode->OrgVal);
        
        NewNode* res = new NewNode(node->data,temp);
        return res;
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        NewNode* ans = toSumTreeUtil(node);
    }
};
