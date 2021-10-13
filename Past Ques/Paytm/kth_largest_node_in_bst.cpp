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


int ans = -1;


void solve(Node* root,int target,int &cnt)
{
    if(root == NULL)
    {
        return ;
    }
    solve(root->right,target,cnt);
    cnt++;
    if(cnt == target)
    {
        ans = root->data;
    }
    solve(root->left,target,cnt);

}


int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(10);
    int prev = 0;
    solve(root,2,prev);
    cout << ans << endl;
    return 0;
}
