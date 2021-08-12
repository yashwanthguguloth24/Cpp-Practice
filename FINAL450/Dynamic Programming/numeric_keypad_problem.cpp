// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

// dp[i][j] ==> j=0 to 9 represents possible number of i length starting with integer j. Using i-1 states and possible paths of j to update the value at dp[i][j]


class Solution{


	public:
	
	vector<int> poss_vals(int ind)
	{
	    map<int,vector<int>> m = {{0,{0,8}}, {1,{1,2,4}}, {2,{2,1,3,5}}, {3,{3,2,6}},{4,{4,1,5,7}},{5,{5,2,4,6,8}},{6,{3,6,5,9}},{7,{7,4,8}},{8,{8,0,5,7,9}},{9,{9,6,8}}};
        return m[ind];	    
	}
	
	
	long long getCount(int N)
	{
	    int n = N;
		vector<vector<long long>> dp(n,vector<long long>(10,0));
		
		for(int i = 0;i<10;i++)
		{
		    dp[0][i] = 1;
		}
    		
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<10;j++)
            {
                vector<int> surr = poss_vals(j);
                for(int k = 0;k<surr.size();k++)
                {
                    dp[i][j] += dp[i-1][surr[k]];
                }
    
            }
        }
        
        long long ans = 0;
        
    	for(int i = 0;i<10;i++)
    	{
    	    ans += dp[n-1][i]; 
    	}
    	
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = 0;j<10;j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        /*
        1 1 1 1 1 1 1 1 1 1 
        2 3 4 3 4 5 3 3 5 3 
        35
        
        */
    	
    	return ans;
	}


};
