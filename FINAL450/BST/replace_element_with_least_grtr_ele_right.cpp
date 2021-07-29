// https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/

// Using BST to insert and finding inorder successor

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
        Node* InsertToBST(Node* root,int val,Node* &succ)
        {
            if(root == NULL)
            {
                Node* temp = new Node(val);
                return temp;
            }

            if(val < root->data)
            {
                succ = root;
                root->left = InsertToBST(root->left,val,succ);
            }
            else if(val > root->data)
            {
                root->right = InsertToBST(root->right,val,succ);
            }
            return root;
        }


        void replace(int arr[],int n)
        {
            Node* root = NULL;
            for(int i = n-1;i>=0;i--)
            {
                Node* succ = NULL;
                root = InsertToBST(root,arr[i],succ);

                if(succ)
                {
                    arr[i] = succ->data;
                }
                else
                {
                    arr[i] = -1;
                }
            }
        }
};

int main()
{
    int arr[] = { 8,  58, 71, 18, 31, 32, 63, 92,43, 3,  91, 93, 25, 80, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution s;
    s.replace(arr, n);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
