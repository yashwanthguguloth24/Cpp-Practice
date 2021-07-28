// https://www.geeksforgeeks.org/find-median-bst-time-o1-space/

// Find counting then calculating k using count to find kth node in inorder traversal


#include<iostream>
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
        int FindNumNodes(Node* root)
        {
            if(root == NULL)
            {
                return 0;
            }
            int lcnt = FindNumNodes(root->left);
            int rcnt = FindNumNodes(root->right);
            return 1+lcnt+rcnt;
        }

        void KthNode(Node* root,int & cnt,int k,int &ans)
        {
            if(root == NULL) return;

            KthNode(root->left,cnt,k,ans);
            cnt++;
            if(cnt == k)
            {
                ans = root->data;
            }
            KthNode(root->right,cnt,k,ans);
        }

        int FindMedian(Node* root)
        {
            int n = FindNumNodes(root);
            int res;
            if(n%2 != 0)
            {
                int k = (n/2)+1;
                int cnt = 0;
                KthNode(root,cnt,k,res);
            }
            else
            {
                int l,r;
                int cnt = 0;
                int k = (n/2);
                // cout << n << endl;
                KthNode(root,cnt,k,l);
                int cnt1 = 0;
                int k1 = (n/2)+1;
                KthNode(root,cnt1,k1,r);
                // cout << k << " " << l << " " << r << endl;
                res = (l+r)/2;
            }
            return res;
        }
};





int main()
{
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    root->right->right->right = new Node(90);
    root->right->right->right->right = new Node(100);
    Solution s;
    cout << s.FindMedian(root) << endl;
    return 0;
}
