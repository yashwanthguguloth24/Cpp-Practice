// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// Hint section of above GFG problem

// Interesting problem can be solved using queue.Our intention will be to go right. And store the left nodes which will be processed later.

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   /*
   Interesting problem can be solved using queue.
   Our intention will be to go right
   And store the left nodes which will be processed later.
   */
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   while(q.size() != 0)
   {
       Node* curr = q.front();
       q.pop();
       while(curr)
       {
           ans.push_back(curr->data);
           if(curr->left)
           {
               q.push(curr->left);
           }
           curr = curr->right;
       }

   }
   return ans;
   
