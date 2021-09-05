// https://leetcode.com/problems/orderly-queue/ 


// using observation, for k>1 least lexographical is always possible


class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1)
        {
            string ans = s;
            for(int i = 0;i<s.length();i++)
            {
                s.push_back(s[0]);
                s.erase(s.begin());
                if(s < ans)
                {
                    ans = s;
                }
            }
            return ans;
//             char min_char = '|';
//             for(int i = 0;i<s.length();i++)
//             {
//                 if((min_char-'a') > (s[i]-'a'))
//                 {
//                     min_char = s[i];
//                 }
//             }
//             queue<char> q;
//             for(int i = 0;i<s.length();i++)
//             {
//                 q.push(s[i]);
//             }
            
//             while(q.front() != min_char)
//             {
//                 char ch = q.front();
//                 q.pop();
//                 q.push(ch);
//             }
            
//             string res = "";
//             while(!q.empty())
//             {
//                 res += q.front();
//                 q.pop();
//             }
//             return res;
            
        }
        else
        {
            sort(s.begin(),s.end());
            return s;
        }
    }
};
