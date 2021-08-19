// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

// Based on TOPOLOGICAL SORT because higher priority characters should come first,trick is to convert given input to graph and compute


class Solution{
    public:
    void topologicalSort(int i,int K,string dict[],string &ans,vector<vector<int>> &adj,vector<bool>&visited)
    {
        if(visited[i]) return;
        visited[i] = true;
        for(int j = 0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
            {
                topologicalSort(adj[i][j],K,dict,ans,adj,visited);
            }
        }
        ans.push_back(('a'+i));
    }
    
    string findOrder(string dict[], int N, int K) {
        string ans;
        vector<vector<int>> adj(K);
        vector<bool>visited(K,false);
        for(int i = 0;i<N-1;i++)
        {
            for(int j = 0;j<min(dict[i].length(),dict[j].length());j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    adj[dict[i][j]-97].push_back(dict[i+1][j]-97);
                    break;
                }
            }
        }
        
        for(int i = 0;i<K;i++)
        {
            if(!visited[i])
            {
                topologicalSort(i,K,dict,ans,adj,visited);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
