// https://leetcode.com/problems/decode-string/


class Solution {
public:
    string repeat(string s,int n)
    {
        if(n == 1)return s;
        string res = "";
        while(n)
        {
            res += s;
            n--;
        }
        return res;
    }
    
    
    string decodeString(string s) {
        string res = "";
        int n = s.length();
        if(n == 1)
        {
            return s;
        }
        int i = 0;
        int num = 0;
        int open = 0;
        int close = 0;
        while(i<n)
        {
            if(isalpha(s[i]))
            {
                res += s[i];
                i++;
            }
            else if(isdigit(s[i]))
            {
                num = 0;
                while(i < n && s[i] != '[')
                {
                    num = num*10 +(s[i]-'0');
                    i++;
                }
            }
            else if(s[i] == '[')
            {
                //cout << s[i]<<" " << i << endl;
                open++;
                int j = i+1;
                while(j < n && open != close)
                {
                    if(s[j] == '[')
                    {
                        open++;
                    }
                    else if(s[j] == ']')
                    {
                        close++;
                    }
                    j++;
                }
                j--;
                //cout << i << " " << j << endl;
                string temp = s.substr(i+1,j-i-1);
                string ans = decodeString(temp);
                //cout << temp << endl;
                res += repeat(ans,num);
                i = j+1;
            }
        }
        return res;
    }
};
