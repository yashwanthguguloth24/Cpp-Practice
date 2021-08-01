// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

// create huffman tree using min heap.lowest frequency char having more bits is the greedy approach here

class HuffmanNode
{
    public:
        char ch;
        int cnt;
        HuffmanNode* left;
        HuffmanNode* right;
        HuffmanNode(char x,int y,HuffmanNode* l,HuffmanNode* r)
        {
            ch = x;
            cnt = y;
            left = l;
            right = r;
        }
};

class myComparator
{
public:
    bool operator()(HuffmanNode* e1,HuffmanNode* e2)
    {
        return (e1->cnt > e2->cnt);
    }
};


class Solution
{
	public:
	    string str = "";
	    vector<string> res;
	    void preOrder(HuffmanNode* root)
	    {
	        if(root == NULL)
	        {
	            return;
	        }
	        if(root->left == NULL && root->right == NULL)
	        {
	            res.push_back(str);
	            str.pop_back();
	            return;
	        }
	        
	        str += "0";
	        preOrder(root->left);
	        str += "1";
	        preOrder(root->right);
	        str.pop_back();
	    }
	    
	    
	    HuffmanNode* BuildTree(string S,vector<int> f,int N)
	    {
	        priority_queue<HuffmanNode* ,vector<HuffmanNode* >,myComparator> mnheap;
	        for(int i = 0;i<S.length();i++)
	        {
	            mnheap.push(new HuffmanNode(S[i],f[i],NULL,NULL));
	        }
	        
	        while(mnheap.size() != 1)
	        {
	            HuffmanNode* top1 = mnheap.top();
	            mnheap.pop();
	            HuffmanNode* top2 = mnheap.top();
	            mnheap.pop();
	            HuffmanNode* res = new HuffmanNode('#',((top1->cnt)+(top2->cnt)),top1,top2);
	            mnheap.push(res);
	        }
	        return mnheap.top();
	    }
	        
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    HuffmanNode* root = BuildTree(S,f,N);
		    preOrder(root);
		    return res;
		}
};
