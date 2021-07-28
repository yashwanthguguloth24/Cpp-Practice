// https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

// Solved using 2 approaches 1.direct rec 2. using BST prop in rec


#include<iostream>
#include <bits/stdc++.h>
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

class Solution
{
    public:

    int preind = 0;

    Node* CreateBST(int pre[],int l,int r,int n)
    {
        if(l>r || preind >= n)
        {
            return NULL;
        }

        Node* root = new Node(pre[preind]);
        preind++;

        int i;
        for(i = l;l<=r;i++)
        {
            if(pre[i] > root->data)
            {
                break;
            }
        }

        root->left = CreateBST(pre,preind,i-1,n);
        root->right = CreateBST(pre,i,r,n);
        
        return root;
    }

    int preInd = 0;
    Node* createBST_optm(int pre[],int key,int mn,int mx,int n)
    {
        // cout << preInd << key << endl;
        if(preInd >= n)
        {
            return NULL;
        }

        Node* root = NULL;

        if(key > mn && key < mx)
        {
            root = new Node(key);
            preInd++;

            if(preInd < n)
            {
                root->left = createBST_optm(pre,pre[preInd],mn,key,n);
            }

            if(preInd < n)
            {
                root->right = createBST_optm(pre,pre[preInd],key,mx,n);
            }
        }
        return root;
    }




    void printInorder(Node* node)
    {
        if (node == NULL)
            return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
};





int main()
{
    int pre[] = {10, 5,1,7,40,50 };
    int n = sizeof(pre) / sizeof(pre[0]);
    Solution s;
    Node* root = s.CreateBST(pre,0,n-1,n);
    Node* root_opt = s.createBST_optm(pre,pre[0],INT_MIN,INT_MAX,n);
    cout << "First Method  :  ";
    s.printInorder(root);
    cout << endl;
    cout << "Second Method  :  ";
    s.printInorder(root_opt);
    cout << endl;
    return 0;
}
