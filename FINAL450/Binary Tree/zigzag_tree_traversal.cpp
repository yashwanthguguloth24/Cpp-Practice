// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

// Level order traversal using 2 stacks
// solved using 2 stacks , taking them as curr and next stacks

/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;
	stack<Node*> curr_stk;
	curr_stk.push(root);
	stack<Node*> next_stk;
	while(curr_stk.size() != 0 || next_stk.size() != 0)
	{
	    while(curr_stk.size() != 0)
	    {
	        Node* top = curr_stk.top();
	        ans.push_back(top->data);
	        curr_stk.pop();
	        if(top->left)
	        {
	            next_stk.push(top->left);
	        }
	        if(top->right)
	        {
	            next_stk.push(top->right);
	        }
	    }
	    
	    // this time we will reverse first right then left
	    // this change is the key..
	    while(next_stk.size() != 0)
	    {
	        Node* top = next_stk.top();
	        ans.push_back(top->data);
	        next_stk.pop();
	        if(top->right)
	        {
	            curr_stk.push(top->right);
	        }
	        if(top->left)
	        {
	            curr_stk.push(top->left);
	        }
	    }	    
	}
	return ans;
	
	
