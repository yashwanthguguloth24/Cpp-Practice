// https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/

// Follow the approach similar to Backtrack,1.push element 2.recur to left and right 3. remove element

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


class Solution
{
    public:
        int K;
        Solution(int k)
        {
            K = k;
        }

        void PrintPath(int i,vector<int> path)
        {
            for(int j = i;j<path.size();j++)
            {
                cout << path[j] << " ";
            }
            cout << endl;
        }

        void kSumPathsUtil(Node* root, vector<int> &path)
        {
            if(root == NULL)
            {
                return;
            }
            // backtrack now

            path.push_back(root->data);

            kSumPathsUtil(root->left,path);
            kSumPathsUtil(root->right,path);

            int s = 0;
            for(int i = path.size()-1;i>=0;i--)
            {
                s += path[i];

                if(s == K)
                {
                    PrintPath(i,path);
                }
            }

            path.pop_back();
        }

        void kSumPath(Node* root)
        {
            vector<int> path;
            kSumPathsUtil(root,path);
        }
};


int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    Solution s(5);
    s.kSumPath(root);    
    return 0;
}
