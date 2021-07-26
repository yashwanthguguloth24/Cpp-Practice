// https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1#

// converting subtree to string to use umap and count the duplicates of substring


string storeAllDups(Node* root,unordered_map<string,int> &ump,vector<Node*> &v)
{
    if(root == NULL)
    {
        string temp = "";
        return temp;
    }
    string temp;
    string l = storeAllDups(root->left,ump,v);
    string r = storeAllDups(root->right,ump,v);
    
    for(int i = 0;i<l.size();i++)
    {
        temp.push_back((char)l[i]-'0');
    }
    temp.push_back(root->data);
    for(int i = 0;i<r.size();i++)
    {
        temp.push_back((char)r[i]-'0');
    }
    if(ump.find(temp) != ump.end() && ump[temp]<2)
    {
        v.push_back(root);
        ump[temp]++;
    }
    else
    {
        ump[temp]++;
    }
    return temp;
}



vector<Node*> printAllDups(Node* root)
{
    unordered_map<string,int> ump;
    vector<Node*> v;
    storeAllDups(root,ump,v);
    return v;
}

// { Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		vector<Node*> res = printAllDups(root);
		
		for(int i=0;i<res.size();i++){
		    preorder(res[i]);
		    cout<<endl;
		}
    }
    return 0;
}
