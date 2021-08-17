// https://leetcode.com/problems/number-of-provinces/

// Using DFS(Connected components)


class Solution {
public:
    void dfs(int i,vector<bool>&visited,vector<vector<int>>& isConnected)
    {
        if(visited[i] == true)
        {
            return;
        }
        visited[i] = true;
        int n = isConnected.size();
        for(int j = 0;j<n;j++)
        {
            if(isConnected[i][j] == 1)
            {
                if(visited[j] == false)
                {
                    dfs(j,visited,isConnected);
                }
            }
        }
    }
    
    
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        
        int cc = 0;
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == false)
            {
                dfs(i,visited,isConnected);
                cc++;
            }
        }
        return cc;
        
    }
};
