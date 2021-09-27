// Dynamic technology question
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int x)
    {
        data = x;
    }
};

void createNode(int i,int n,vector<Node*> &created,vector<int> parent,vector<int> values,Node** root)
{
    if(created[i] != NULL)
    {
        return;
    }


    Node* newNode = new Node(values[i]);
    created[i] = newNode;

    if(parent[i] == -1)
    {
        *root = created[i];
        return;
    }


    if(created[parent[i]] == NULL)
    {
        createNode(parent[i],n,created,parent,values,root);
    }
    if(created[parent[i]]->left == NULL)
    {
        created[parent[i]]->left = created[i];
    }
    else
    {
        created[parent[i]]->right = created[i];
    }

}

Node* genTree(int n,vector<Node*> &created,vector<int> parent,vector<int> values)
{
    Node* root = NULL;
    for(int i = 0;i<n;i++)
    {
        createNode(i,n,created,parent,values,&root);
    }
    return root;
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


int solve(Node* root,int &res)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    int temp = max(max(l,r)+root->data,root->data);
    res = max(res,max(temp,l+r+root->data));
    return temp;

}

int main()
{
    vector<int> parent = {-1,0,1,2,0};
    vector<int> values = {-2,10,10,-3,10};
    int n = parent.size();
    vector<Node*> created(n,NULL);
    Node* root = genTree(n,created,parent,values);
    // inorder(root);
    int res = INT_MIN;
    int ans = solve(root,res);
    cout << res << endl;
    return 0;
}
