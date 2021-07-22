// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

// Use 2 methods using hashing and without using hashing
// Solving recursively, prreorder to iterate, inorder to get left and right(solved 2 approaches)

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int pre_ind = 0;
    int findIndex(int in[],int st,int end,int val,int n)
    {

        for(int i = st;i<=end;i++)
        {
            if(in[i] == val)
            {
                return i;
            }
            
        }
        // return -1;
        // return index; // this should not happen
    }
    
    // LINEAR SEARCH : METHOD 1
    Node* buildTreeUtil(int in[],int in_st,int in_end,int pre[],int n)
    {
        // static int pre_ind = 0;
        if(in_end < in_st || pre_ind >= n)
        {
            return NULL;
        }
        // cout << in_st << in_end << pre_ind << endl;
        Node* node = new Node(pre[pre_ind]);
        // node->data = pre[pre_ind];
        pre_ind++;
        // cout << in_st << in_end << node->data << endl;
        if(in_st == in_end)
        {
            return node;
        }
        
        int index = findIndex(in,in_st,in_end,node->data,n);
        // cout << index << endl;
        // if(index == -1) return node;
        node->left = buildTreeUtil(in,in_st,index-1,pre,n);
        // cout << "done" << endl;
        node->right = buildTreeUtil(in,index+1,in_end,pre,n);
        return node;


    }
    
    // USING MAP : METHOD 2
    Node* buildTreeUtil_Map(int in[],int in_st,int in_end,int pre[],int n,unordered_map<int,int> &mp)
    {
        if(in_end < in_st || pre_ind >= n)
        {
            return NULL;
        }

        Node* node = new Node(pre[pre_ind]);

        pre_ind++;

        if(in_st == in_end)
        {
            return node;
        }
        
        int index = mp[node->data];

        node->left = buildTreeUtil(in,in_st,index-1,pre,n);

        node->right = buildTreeUtil(in,index+1,in_end,pre,n);
        return node;        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            mp[in[i]] = i;
        }
        Node* root = buildTreeUtil_Map(in,0,n-1,pre,n,mp);
        return root;
        // Node* root = buildTreeUtil(in,0,n-1,pre,n);
        // return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
