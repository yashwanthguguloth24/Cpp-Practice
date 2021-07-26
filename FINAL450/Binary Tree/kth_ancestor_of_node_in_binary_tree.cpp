// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/

// traversing through depth and backtracking from the node found till kth ancestor

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
        bool flag = false;
        int foundLevel = -1;
        int counter = 0;
        int k;
        Solution(int K)
        {
            k = K;
        }

        void Kth_ancestorUtil(Node* root,int node,int level)
        {
            if(root == NULL)
            {
                return;
            }

            if(root->data == node)
            {
                foundLevel = level;
                flag = true;
                return;
            }

            
    
            Kth_ancestorUtil(root->left,node,level+1);
            if(flag == true)
            {
                counter++;
                if(counter == k)
                {
                    cout << "kth ancestor is :" << root->data;
                    return;
                }
                return;
            }
            Kth_ancestorUtil(root->right,node,level+1);
            if(flag == true)
            {
                counter++;
                if(counter == k)
                {
                    cout << "kth ancestor is :" << root->data;
                    return;
                }
                return;
            }

        }
};



int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int K = 1;
    Solution s(K);
    int node = 2;
    s.Kth_ancestorUtil(root,node,2);
    return 0;
}
