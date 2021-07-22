// https://practice.geeksforgeeks.org/problems/sum-tree/1

// using PAIR approach, similar ro BINARY TREE TO SUM TREE problem, create a class NewNode with int Sum and bool isSumST

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class NewNode
{
    public:
        int SumVal;
        bool isSumST;
        
        NewNode(int a,bool b)
        {
            SumVal = a;
            isSumST = b;
        }
};


class Solution
{
    public:
    
    NewNode* isSumTreeUtil(Node* root)
    {
        if(root == NULL)
        {
            NewNode* temp = new NewNode(0,true);
            return temp;
        }
        
        NewNode* leftNode = isSumTreeUtil(root->left);
        NewNode* rightNode = isSumTreeUtil(root->right);
        
        int sumval = leftNode->SumVal + rightNode->SumVal + root->data;
        bool isSubsumtree;
        if(root->left == NULL && root->right == NULL)
        {
            isSubsumtree = true;
        }
        else
        {
            isSubsumtree = (leftNode->isSumST && rightNode->isSumST && (leftNode->SumVal + rightNode->SumVal == root->data));
        }
        
        NewNode* res = new NewNode(sumval,isSubsumtree);
        return res;
        
    }

    
    
    bool isSumTree(Node* root)
    {
        NewNode* ans = isSumTreeUtil(root);
        return ans->isSumST;
    }
};
