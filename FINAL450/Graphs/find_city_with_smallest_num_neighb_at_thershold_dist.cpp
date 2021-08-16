// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

// using FLOYDD WARSHALL ALGO and checking min no connected cities with dist less than T


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,-1));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == j)
                {
                    distance[i][j] = 0;
                }
                else if(distance[i][j] == -1)
                {
                    distance[i][j] = INT_MAX;
                }
            }
        }
        
        
        for(int i = 0;i<edges.size();i++)
        {
            distance[edges[i][0]][edges[i][1]] = edges[i][2];
            distance[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        for(int k = 0;k<n;k++)
	    {
	        for(int i = 0;i<n;i++)
	        {
	            for(int j = 0;j<n;j++)
	            {
	                if(distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
	                {
	                    continue;
	                }
	                if(distance[i][j] > distance[i][k] + distance[k][j])
	                {
	                    distance[i][j] = distance[i][k] + distance[k][j];
	                }
	            }
	        }
	    }
        
        int min_dist_less_thanT = INT_MAX;
        int min_node = -1;
        for(int i = 0;i<n;i++)
        {
            int temp = 0;
            for(int j = 0;j<n;j++)
            {
                if(distance[i][j] <=  distanceThreshold)
                {
                    temp++;
                }
            }
            if(min_dist_less_thanT >= temp)
            {
                min_node = i;
                min_dist_less_thanT = temp;
            }
        }
        
        return min_node;
        
    }
};
