// https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/

// using inorder traversal storing prev nodes and manipulate pointers, NOTE: STORE the start point (left most node) for print function as node right pointers are manipulated

#include<iostream>
#include<bits/stdc++.h>
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
        Node* prev = NULL;
        Node* st = NULL;
        void FlattenBST(Node* root)
        {
            if(root == NULL) return ;

            FlattenBST(root->left);
            if(prev != NULL)
            {
                prev->right = root;
                prev->left = NULL;
            }
            else
            {
                st = root;
            }
            prev = root;
            FlattenBST(root->right);
        }

        void printFlatten(Node* root)
        {
            while(root != NULL)
            {
                cout << root->data << " ";
                root = root->right;
            }
        }

};

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    Solution s;
    s.FlattenBST(root);
    s.printFlatten(s.st);
    return 0;
}
