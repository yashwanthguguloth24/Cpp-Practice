// https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

// storing inorder traversal of bsts , merge arrays, then convert arr to BBST using above method

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
        void storeBSTnodes(Node* root,vector<int>&BBST)
        {
            if(root == NULL)
            {
                return;
            }
            storeBSTnodes(root->left,BBST);
            BBST.push_back(root->data);
            storeBSTnodes(root->right,BBST);
        }

        vector<int> mergeNodes(vector<int>BBST1,vector<int>BBST2)
        {
            vector<int> CmbBBST;
            int i = 0;
            int j = 0;
            int n = BBST1.size();
            int m = BBST2.size();

            while(i<n && j<m)
            {
                if(BBST1[i] > BBST2[j])
                {
                    CmbBBST.push_back(BBST2[j]);
                    j++;
                }
                else
                {
                    CmbBBST.push_back(BBST1[i]);
                    i++;                    
                }
            }

            while(i<n)
            {
                CmbBBST.push_back(BBST1[i]);
                i++;
            }

            while(j<m)
            {
                CmbBBST.push_back(BBST2[j]);
                j++;
            }
            return CmbBBST;
        }


        Node* convertToBBST(int l,int r,vector<int>CmbBBST)
        {
            if(l>r)
            {
                return NULL;
            }
            if(l == r)
            {
                Node* temp = new Node(CmbBBST[l]);
                return temp;
            }
            int mid = (l+r)/2;
            Node* root = new Node(CmbBBST[mid]);

            root->left = convertToBBST(l,mid-1,CmbBBST);
            root->right = convertToBBST(mid+1,r,CmbBBST);
            return root;
        }

        void printInorder(Node* node)
        {
        if (node == NULL)
            return;

        /* first recur on left child */
        printInorder(node->left);

        cout << node->data << " ";

        /* now recur on right child */
        printInorder(node->right);
        }
            

};



int main()
{
       /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);
 
    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);

    Solution s;
    vector<int> bbst1,bbst2,cmb_bbst;
    s.storeBSTnodes(root1,bbst1);
    s.storeBSTnodes(root2,bbst2);
    cmb_bbst = s.mergeNodes(bbst1,bbst2);
    Node* ans = s.convertToBBST(0,cmb_bbst.size()-1,cmb_bbst);
    s.printInorder(ans);

    return 0;
}
