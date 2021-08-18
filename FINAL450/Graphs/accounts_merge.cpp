// https://leetcode.com/problems/accounts-merge/

//Converting the given mails to graphs smartly and using DFS on it

class Solution {
public:
    
    void dfs(int i,set<string>& emails,vector<vector<string>>& accounts,map<string,vector<int>> &email_map,vector<bool>&visited)
    {
        if(visited[i] == true)
        {
            return;
        }
        visited[i] = true;
        for(int j = 1;j<accounts[i].size();j++)
        {
            emails.insert(accounts[i][j]);
            for(int k = 0;k<email_map[accounts[i][j]].size();k++)
            {
                if(visited[email_map[accounts[i][j]][k]] == false)
                {
                    dfs(email_map[accounts[i][j]][k],emails,accounts,email_map,visited);
                }
            }
        }
            
    }
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<bool>visited(n,false);
        map<string,vector<int>> email_map;
        vector<vector<string>> ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                email_map[accounts[i][j]].push_back(i);
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == false)
            {
                set<string> emails;
                dfs(i,emails,accounts,email_map,visited);
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                for(auto it:emails)
                {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
            
        }
        return ans;
        
        
    }
};
