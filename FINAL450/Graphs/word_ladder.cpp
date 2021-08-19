// https://leetcode.com/problems/word-ladder/

// Tried using Backtracking got TLE ,then applied BFS because SHORTEST PATH!!
// leetcode HARD Question

class Solution {
public:
    bool ans = false;
    int finalAns = 10000;

    
    bool isDiffByOne(string a,string b)
    {
        if(a.length() != b.length())
        {
            return false;
        }
        int cnt = 0;
        for(int i = 0;i<a.length();i++)
        {
            if(a[i] != b[i])
            {
                cnt++;
            }
        }
        if(cnt == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void dfs(int i,string endWord,vector<string>& wordList,vector<bool>&visited,int res,vector<vector<int>>&adj)
    {
        if(wordList[i] == endWord)
        {
            ans = true;
            res++;
            finalAns = min(finalAns,res);
            return;
        }
        if(visited[i]) return;
        
        visited[i] = true;
        for(int j = 0;j<adj[i].size();j++)
        {
            if(visited[adj[i][j]] == false)
            {
                dfs(adj[i][j],endWord,wordList,visited,res+1,adj);
            }
            // if(ans == true) return;
        }
        visited[i] = false;
        
        
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // base case
        bool flag = false;
        for(auto words:wordList)
        {
            if(words == endWord)
            {
                flag = true;
            }
        }
        if(!flag)
        {
            return 0;
        }
        // main code
        flag = false;
        int N = wordList.size();
        int n = N;
        int temp = -1;
        for(int i = 0;i<N;i++)
        {
            if(wordList[i] == beginWord)
            {
                temp = i;
            }
        }
        if(temp != -1)
        {
            wordList.erase(wordList.begin()+temp);
        }
        
        wordList.insert(wordList.begin(),beginWord); 
        n = wordList.size();


        vector<bool>visited(n,false);
        vector<vector<int>> adj(n);
        vector<string> res;
        for(int i = 0;i<n-1;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(isDiffByOne(wordList[i],wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        queue<pair<int,int>> q;
        q.push(make_pair(0,1));
        while(!q.empty())
        {
            pair<int,int> tp = q.front();
            q.pop();
            if(wordList[tp.first] == endWord)
            {
                return tp.second;
            }
            if(visited[tp.first]) continue;
            visited[tp.first] = true;
            for(int i = 0;i<adj[tp.first].size();i++)
            {
                int u = adj[tp.first][i];
                if(visited[u] == false)
                {
                    q.push(make_pair(u,tp.second+1));
                }
            }
        }
        return 0;
        
    }
};
