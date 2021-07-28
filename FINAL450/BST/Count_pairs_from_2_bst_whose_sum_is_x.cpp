// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

// storing inorder traversal of both trees, then iterating the vectors to store counts




//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
void storeBSTnodes(Node* root,vector<int>&BST)
{
    if(root == NULL)
    {
        return;
    }
    storeBSTnodes(root->left,BST);
    BST.push_back(root->data);
    storeBSTnodes(root->right,BST);
}


vector<int> mergeNodes(vector<int>BBST1,vector<int>BBST2)
{
    vector<int> CmbBBST;
    int i = 0;
    int j = 0;
    int n = BBST1.size();
    int m = BBST2.size();

    while(i<n && j<m)
    {
        if(BBST1[i] > BBST2[j])
        {
            CmbBBST.push_back(BBST2[j]);
            j++;
        }
        else if(BBST1[i] == BBST2[j])
        {
            CmbBBST.push_back(BBST1[i]);
            CmbBBST.push_back(BBST2[j]);
            i++;
            j++;
        }
        else
        {
            CmbBBST.push_back(BBST1[i]);
            i++;
        }
    }

    while(i<n)
    {
        CmbBBST.push_back(BBST1[i]);
        i++;
    }

    while(j<m)
    {
        CmbBBST.push_back(BBST2[j]);
        j++;
    }
    return CmbBBST;
}





int countPairs(Node* root1, Node* root2, int x)
{
    int cnt = 0;
    vector<int> bst1;
    storeBSTnodes(root1,bst1);
    
    vector<int> bst2;
    storeBSTnodes(root2,bst2);
    
    // vector<int> merged = mergeNodes(bst1,bst2);
    int n = bst1.size();
    int m = bst2.size();
    int i = 0;
    int j = m-1;
    while(i<n && j>=0)
    {
        int s = bst1[i]+bst2[j];
        if(s == x)
        {
            // cout << bst1[i] << "  " <<  bst1[j] << endl;
            cnt++;
            i++;
            j--;
        }
        else if(s > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return cnt;
    
