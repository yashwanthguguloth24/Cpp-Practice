// https://leetcode.com/problems/gray-code/

// recursively calling n-1 th gray code

class Solution {
public:
    
    vector<int> BinaryStrToDec(vector<string> v1)
    {
        vector<int>vals;
        for(int i = 0;i<v1.size();i++)
        {
            int val = 0;
            for(int j = 0;j<v1[j].size();j++)
            {
                if(v1[i][j] == '0')
                {
                    val = (val*2 + 0);
                }
                else
                {
                    val = (val*2 + 1);
                }
            }
            vals.push_back(val);
        }
        return vals;
    }

    vector<string> GC(int n)
    {
        if(n == 1)
        {
            vector<string> v1;
            v1.push_back("0");
            v1.push_back("1");
            return v1;
        }
        
        vector<string> v2; // for pervious gray code
        v2 = GC(n-1);
        
        vector<string> v3; // to store the required gray sequence 
        for(int i = 0;i<v2.size();i++)
        {
            v3.push_back("0"+v2[i]);
        }
        for(int i = v2.size()-1;i>=0;i--)
        {
            v3.push_back("1"+v2[i]);
        }        
        return v3;
        
    }
    
    vector<int> grayCode(int n) {
        vector<string> bin_strs = GC(n);
        return BinaryStrToDec(bin_strs);
    }
};
