// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

// Using bfs traversal and keep track of steps


class Solution 
{
    public:
    bool isSafe(int row,int col,vector<vector<bool>> &visited,int N)
    {
        if(row < 0 || col < 0 || row > N-1 || col > N-1 || visited[row][col] == true)
        {
            return false;
        }
        return true;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
	    {
	        return 0;
	    }
	    vector<vector<bool>> visited(N,vector<bool> (N,false));
	    
	    vector<int> row_pos = {-2,-1,1,2,2,1,-1,-2};
	    vector<int> col_pos = {1,2,2,1,-1,-2,-2,-1};
	    
	    queue<pair<pair<int,int>,int>> q;
	    q.push(make_pair(make_pair(KnightPos[0]-1,KnightPos[1]-1),1));
	    visited[KnightPos[0]-1][KnightPos[1]-1] = true;
	    while(!q.empty())
	    {
	        pair<pair<int,int>,int> top_ele = q.front();
	        q.pop();
	        
	        int r = (top_ele.first).first;
	        int c = (top_ele.first).second;
	        
	        for(int i = 0;i<row_pos.size();i++)
	        {
	            if(isSafe(r+row_pos[i],c+col_pos[i],visited,N))
	            {
	                if(r+row_pos[i] == (TargetPos[0]-1) && c+col_pos[i] == (TargetPos[1]-1))
	                {
	                    return top_ele.second;
	                }
	                else
	                {
	                    q.push(make_pair(make_pair(r+row_pos[i],c+col_pos[i]),top_ele.second+1));
	                }
	                visited[r+row_pos[i]][c+col_pos[i]] = true;
	            }
	        }
	        
	        
	    }
	    return -1;
	    
	    
	    
	    
	    
	}
};
