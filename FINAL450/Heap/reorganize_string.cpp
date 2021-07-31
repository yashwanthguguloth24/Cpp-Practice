// https://leetcode.com/problems/reorganize-string/

// Using greedy approach,pick top 2most occuring char add to string, dec count and push , continue this until you reach a single char or empty.if the left char count is greater than it is not possible ,else possible.

class ele
{
    public:
    char ch;
    int cnt;
    ele(char a,int b)
    {
        ch = a;
        cnt = b;
    }
};


class myComparator
{
public:
    bool operator()(ele e1,ele e2)
    {
        return (e1.cnt < e2.cnt);
    }
};


class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> counts;
        // store counts in map
        for(int i = 0;i<s.length();i++)
        {
            counts[s[i]]++;
        }
        
        priority_queue<ele,vector<ele>,myComparator> mxheap;
        map<char, int>::iterator itr;
        for(itr = counts.begin();itr != counts.end();itr++)
        {
            mxheap.push(ele(itr->first,itr->second));
        }
        string res;
        while(mxheap.size() > 1)
        {
            ele top1 = mxheap.top();
            mxheap.pop();
            ele top2 = mxheap.top();
            mxheap.pop();
            
            res.push_back(top1.ch);
            res.push_back(top2.ch);
            
            counts[top1.ch]--;
            counts[top2.ch]--;
            
            if(counts[top1.ch] > 0)
            {
                mxheap.push(ele(top1.ch,counts[top1.ch]));
            }
            if(counts[top2.ch] > 0)
            {
                mxheap.push(ele(top2.ch,counts[top2.ch]));
            }                   
        }
        
        if(mxheap.size() != 0)
        {
            ele c = mxheap.top();
            mxheap.pop();
            if(c.cnt > 1)
            {
                return "";
            }
            res.push_back(c.ch);
        }
        return res;
    }
};
