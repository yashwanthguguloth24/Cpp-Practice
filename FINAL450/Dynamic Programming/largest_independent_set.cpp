// https://www.geeksforgeeks.org/largest-independent-set-problem-dp-26/

// for memoization keep extra parameter to node naming liss and then use that to update and memoize


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        int liss;

    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
        liss = 0;
    }
};


int largestIndependentSet(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->liss != 0)
    {
        return root->liss;
    }


    if(root->left == NULL && root->right == NULL)
    {
        root->liss = 1;
        return root->liss;
    }
    int incl = 0;
    int excl = 0;
    if(root->left)
    {
        incl += largestIndependentSet(root->left->left)+largestIndependentSet(root->left->right);
        excl += largestIndependentSet(root->left);
    }
    if(root->right)
    {
        incl += largestIndependentSet(root->right->left)+largestIndependentSet(root->right->right);
        excl += largestIndependentSet(root->right);
    }

    incl += 1;
    root->liss = max(incl,excl);

    return root->liss;
}










int main()
{
    Node *root     = new Node(20);
    root->left         = new Node(8);
    root->left->left     = new Node(4);
    root->left->right     = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right         = new Node(22);
    root->right->right     = new Node(25);
    cout << "Size of the Largest Independent Set is " << largestIndependentSet(root) << endl;
    return 0;
}
