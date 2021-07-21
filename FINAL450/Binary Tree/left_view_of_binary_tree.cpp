//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
// https://www.youtube.com/watch?v=AIokcTT0LuE


// pick up the first element in every level using inorder traversal

void inorderTrav(Node* root,int level,set<int> &s,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    if(s.find(level) == s.end())
    {
        s.insert(level);
        ans.push_back(root->data);
    }
    inorderTrav(root->left,level+1,s,ans);
    inorderTrav(root->right,level+1,s,ans);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   set<int> s;
   inorderTrav(root,0,s,ans);
   return ans;
//   while(root->left != NULL || root->right != NULL)
//   {
//       ans.push_back(root->data);
//       if(root->left)
//       {
//           root = root->left;
//       }
//       else
//       {
//           root = root->right;
//       }
//   }
//   ans.push_back(root->data);
//   return ans;
}
