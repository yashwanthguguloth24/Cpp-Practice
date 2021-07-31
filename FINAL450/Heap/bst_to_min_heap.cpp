// https://www.geeksforgeeks.org/convert-bst-min-heap/

// Inorder traversal to get sorted array, then preoder traversal to replace values with inorder stored values

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
    void inorderTraversal(Node *root, vector<int>& arr)
    {
        if (root == NULL)
            return;

        // first recur on left subtree
        inorderTraversal(root->left, arr);

        // then copy the data of the node
        arr.push_back(root->data);

        // now recur for right subtree
        inorderTraversal(root->right, arr);
    }

    void BSTToMinHeap(Node *root, vector<int> arr, int *i)
    {
        if (root == NULL)
            return;

        // first copy data at index 'i' of 'arr' to
        // the node
        root->data = arr[++*i];

        // then recur on left subtree
        BSTToMinHeap(root->left, arr, i);

        // now recur on right subtree
        BSTToMinHeap(root->right, arr, i);
    }

    void convertToMinHeapUtil(Node *root)
    {
        // vector to store the data of all the
        // nodes of the BST
        vector<int> arr;
        int i = -1;
    
        // inorder traversal to populate 'arr'
        inorderTraversal(root, arr);
    
        // BST to MIN HEAP conversion
        BSTToMinHeap(root, arr, &i);
    }


    void preorderTraversal(Node *root)
    {
        if (!root)
            return;
    
        // first print the root's data
        cout << root->data << " ";
    
        // then recur on left subtree
        preorderTraversal(root->left);
    
        // now recur on right subtree
        preorderTraversal(root->right);
    }
};






int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    Solution s;
    s.convertToMinHeapUtil(root);
    s.preorderTraversal(root);
}
