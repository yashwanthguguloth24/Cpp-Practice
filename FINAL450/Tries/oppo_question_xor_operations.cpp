#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    int isend;
    TrieNode* next[2] = {NULL};
    TrieNode(char c,int val)
    {
        data = c;
        isend = val;
    }
};


string to_bin(int val,int max_bits)
{
    // cout << val << endl;
    string ans = "";
    int i = 1;
    while(i <= val)
    {
        if((i&val) != 0)
        {
            ans += "1";
        }
        else
        {
            ans += "0";
        }
        // cout << i << endl;
        i = i << 1;
    }
    reverse(ans.begin(),ans.end());
    string to_pad = "";
    int diff = max_bits-ans.length();
    while(diff)
    {
        to_pad += "0";
        diff--;
    }
    ans = to_pad+ans;
    // cout << ans << endl;
    return ans;
}



void insert(TrieNode* root,string s)
{
    TrieNode* temp = root;
    int n = s.length();
    for(int i = 0;i<n;i++)
    {
        if(i != n-1)
        {
            if(temp->next[s[i]-'0'] == NULL)
            {
                temp->next[s[i]-'0'] = new TrieNode(s[i],0);
                temp = temp->next[s[i]-'0'];
            }
            else
            {
                temp = temp->next[s[i]-'0'];
            }
        }
        else
        {
            if(temp->next[s[i]-'0'] == NULL)
            {
                temp->next[s[i]-'0'] = new TrieNode(s[i],1);
                temp = temp->next[s[i]-'0'];
            }
            else
            {
                temp = temp->next[s[i]-'0'];
            }
        }
    }
}


int to_dec(string b)
{
    int res = 0;
    for(int i = 0;i<b.length();i++)
    {
        res = res*2 + ((b[i] == '0')?0:1);
    }
    // cout << res << endl;
    return res;
    
}


int search(TrieNode* root,string s)
{
    int n = s.length();
    TrieNode* temp = root;
    string res = "";
    for(int i = 0;i<n;i++)
    {
        int val = s[i]-'0';
        if(val == 0){
            if(temp->next[1] != NULL)
            {
                res += "1";
                temp = temp->next[1];
            }
            else
            {
                res += "0";
                temp = temp->next[0];
            }
        }
        else{
            if(temp->next[0] != NULL)
            {
                res += "0";
                temp = temp->next[0];
            }
            else
            {
                res += "1";
                temp = temp->next[1];
            }
        }
    }
    return to_dec(res);
}


int solve(vector<int> A,vector<int> B,int n)
{
    int MXBITS = 4;
    TrieNode* dummyA = new TrieNode('#',0);
    TrieNode* dummyB = new TrieNode('#',0);
    int cnt1 = 0;
    int cnt2 = 0;
    if(A[0] > B[0])
    {
        cnt2++;
        insert(dummyB,to_bin(B[0],MXBITS));
    }
    else if(B[0] > A[0])
    {
        cnt1++;
        insert(dummyA,to_bin(A[0],MXBITS));
    }
    for(int i = 1;i<n;i++)
    {
        int x = A[i];
        int y = B[i];
        int temp1 = -1;
        int temp2 = -1;
        if(cnt1 != 0)
        {
            temp1 = search(dummyA,to_bin(A[i],MXBITS));
        }

        if(cnt2 != 0)
        {
            temp2 = search(dummyB,to_bin(B[i],MXBITS));
        }
        // cout << x << " aa " << temp1 << " sss " << y << " aa " << temp2 << endl; 
        x = max(x,temp1);
        y = max(y,temp2);
        if(x > y)
        {
            cnt2++;
            insert(dummyB,to_bin(B[i],MXBITS));            
        }
        else if(y > x)
        {
            cnt1++;
            insert(dummyA,to_bin(A[i],MXBITS));            
        }
    }
    return cnt2;
}



int main()
{
    int n = 4;
    vector<int> A = {4,8,6,7};
    vector<int> B = {2,8,10,5};
    cout << solve(A,B,n) << endl;
    return 0;
}
