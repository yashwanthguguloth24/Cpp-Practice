// https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/
// https://leetcode.com/problems/palindrome-partitioning/

/*
Using backtracking steps where decision is to add substring to vector if substring is a palindrome.
*/


class Solution {
public:
    bool isPalindrome(string a,int i,int j)
    {
        if(i == j) return 1;
        while(i < j)
        {
            if(a[i] != a[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    
    vector<vector<string>> ans;
    void PP(string s,vector<string> v1,int i)
    {
        // base case
        if(i >= s.length())
        {
            ans.push_back(v1);
            return ;
        }

        
        int j;
        for(j = i;j<s.length();j++)
        {
            if(isPalindrome(s,i,j))
            {
                v1.push_back(s.substr(i,j-i+1)); //take decision
                PP(s,v1,j+1); // recurr
                v1.pop_back(); // undo
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        PP(s,v,0);
        return ans;
    }
};
