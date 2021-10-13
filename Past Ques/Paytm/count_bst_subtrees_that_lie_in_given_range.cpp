#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> ans;

bool solve(Node* root,int mn,int mx)
{
    if(root == NULL) return true;

    bool l = solve(root->left,mn,mx);
    bool r = solve(root->right,mn,mx);
    if(l && r)
    {
        if(root->data >= mn && root->data <= mx)
        {
            ans.push_back(root->data);
            return true;            
        }
        return false;
    }
    else
    {
        return false;
    }

    
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);
    bool a = solve(root,1,45);
    for(int i = 0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
