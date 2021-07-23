// https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

#include<iostream>
#include<map>
using namespace std;

/*
Using 2 methods
1. Using map to store multiple recursion(DP) or memoization
2. Using tradition pair method with first representing max sum including and second representing max sum excluding
*/

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

    //************METHOD1****************************
    int getMaxSumUtil_Method1(Node* root,map<Node*,int> &mp)
    {
        if(root == NULL)
        {
            return 0;
        }

        if(mp.find(root) != mp.end())
        {
            return mp[root];
        }

        int incl = root->data;
        if(root->left)
        {
            incl += getMaxSumUtil_Method1(root->left->left,mp);
            incl += getMaxSumUtil_Method1(root->left->right,mp);
        }

        if(root->right)
        {
            incl += getMaxSumUtil_Method1(root->right->left,mp);
            incl += getMaxSumUtil_Method1(root->right->right,mp);
        }

        int excl = getMaxSumUtil_Method1(root->left,mp) + getMaxSumUtil_Method1(root->right,mp);

        mp[root] = max(incl,excl);
        return mp[root];
    }


    int getMaxSum_Method1(Node* root)
    {
        map<Node*,int> mp;
        int ans = getMaxSumUtil_Method1(root,mp);
        return ans;
    }

    //************METHOD2****************************
    // USING PAIR

    pair<int,int> getMaxSumUtil_Method2(Node* root)
    {
        if(root == NULL)
        {
            pair<int,int> temp(0,0);
            return temp;
        }

        pair<int,int> l = getMaxSumUtil_Method2(root->left);
        pair<int,int> r = getMaxSumUtil_Method2(root->right);

        pair<int,int> res;
        res.first = root->data + l.second + r.second;
        res.second = max(l.first,l.second) + max(l.first,l.second);
        return res;

    }

    int getMaxSum_Method2(Node* root)
    {
        pair<int,int> ans = getMaxSumUtil_Method2(root);
        return max(ans.first,ans.second);
    }
};



int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);    
    Solution s;
    cout << "METHOD 1 : " << s.getMaxSum_Method1(root) << endl;
    cout << "METHOD 2 : " << s.getMaxSum_Method2(root) << endl;
    return 0;
}
