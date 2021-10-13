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
bool flag = false;

void solve(Node* root,int target,int &prev)
{
    if(root == NULL)
    {
        return ;
    }
    solve(root->left,target,prev);
    prev = root->data;
    if(flag == true)
    {
        ans = prev;
        flag = false;
    }
    if(root->data == target)
    {
        flag = true;
    }
    solve(root->right,target,prev);

}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int prev = -1;
    solve(root,4,prev);
    cout << ans << endl;
    return 0;
}
