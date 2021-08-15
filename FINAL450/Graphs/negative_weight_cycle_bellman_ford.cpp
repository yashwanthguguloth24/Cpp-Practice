// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#

// Solved using BellmanFord algorithm


class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>distance(n,INT_MAX);
	    distance[0] = 0;
	    for(int i = 0;i<n-1;i++)
	    {
	        for(int j = 0;j<edges.size();j++)
	        {
	            if(distance[edges[j][0]] != INT_MAX && distance[edges[j][1]] > distance[edges[j][0]] + edges[j][2])
	            {
	                distance[edges[j][1]] = distance[edges[j][0]] + edges[j][2];
	            }
	        }
	    }
	    
	   // bool flag = false;
        for(int j = 0;j<edges.size();j++)
        {
            if(distance[edges[j][0]] != INT_MAX && distance[edges[j][1]] > distance[edges[j][0]] + edges[j][2])
            {
                return 1;
                // distance[edges[j][1]] = distance[edges[j][0]] + edges[j][2];
            }
        }
        return 0;
	}
};
