// https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

// storing inorder nodes of BST then converting those nodes to BBST


#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }

};



class BST_to_BBST
{
    public:
        vector<int> BSTnodes;
        void storeBSTnodes(Node* root)
        {
            if(root == NULL)
            {
                return;
            }
            storeBSTnodes(root->left);
            BSTnodes.push_back(root->data);
            storeBSTnodes(root->right);
        }



        Node* convertToBBST(int l,int r)
        {
            if(l>r)
            {
                return NULL;
            }
            if(l == r)
            {
                Node* temp = new Node(BSTnodes[l]);
                return temp;
            }
            int mid = (l+r)/2;
            Node* root = new Node(BSTnodes[mid]);

            root->left = convertToBBST(l,mid-1);
            root->right = convertToBBST(mid+1,r);
            return root;
        }

        void preOrder(Node* node)
        {
            if (node == NULL)
                return;
            printf("%d ", node->data);
            preOrder(node->left);
            preOrder(node->right);
        }
};





int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    BST_to_BBST obj;
    obj.storeBSTnodes(root);
    Node* ans = obj.convertToBBST(0,obj.BSTnodes.size()-1);
    obj.preOrder(ans);
    return 0;
}
