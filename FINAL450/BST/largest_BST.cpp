// https://practice.geeksforgeeks.org/problems/largest-bst/1

// Creating new BSTPair call with properties isbst,root,size,min,max and recurse

class BSTPair
{
    public:
        bool isBST;
        Node* root;
        int size;
        int mn;
        int mx;
        BSTPair(bool isbst,Node* r,int sz,int min_val,int max_val)
        {
            isBST = isbst;
            root = r;
            size = sz;
            mn = min_val;
            mx = max_val;            
        }
};






BSTPair isBST_util(Node* root,int &cnt)
{
    if(root == NULL)
    {
        BSTPair temp(true,NULL,0,INT_MAX,INT_MIN);
        return temp;
    }
    
    
    BSTPair lp = isBST_util(root->left,cnt);
    BSTPair rp = isBST_util(root->right,cnt);
    
    BSTPair res(true,NULL,0,INT_MAX,INT_MIN);
    
    res.isBST = (lp.isBST && rp.isBST && root->data > lp.mx && root->data < rp.mn);
    
    res.mn = min(root->data,min(lp.mn,rp.mn));
    res.mx = max(root->data,max(lp.mx,rp.mx));
    
    if(res.isBST)
    {
        res.root = root;
        res.size = lp.size + rp.size +1;
        cnt = max(cnt,res.size);
    }
    else if(lp.isBST)
    {
        res.root = lp.root;
        res.size = lp.size;
        cnt = max(cnt,res.size);
    }
    else
    {
        res.root = rp.root;
        res.size = rp.size;
        cnt = max(cnt,res.size);
    }
    return res;
    
}
    
    


int largestBst(Node *root)
{
    int cnt = 0;
    BSTPair ans = isBST_util(root,cnt);
    return cnt;
}
