// https://practice.geeksforgeeks.org/problems/minimum-swaps/1#


// converting the prob into graphs and finding the sum of (length-1) of all cycles.


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<int> dup = nums;
	    sort(dup.begin(),dup.end());
	    int cnt = 0;
	    map<int,int> mp;
	    for(int i = 0;i<n;i++)
	    {
	        mp[dup[i]] = i;
	    }
	    
	    vector<bool> visited(n,false);
	    for(int i = 0;i<n;i++)
	    {
	        if(visited[i] == true || mp[nums[i]] == i)
	        {
	            continue;
	        }
	        int temp_cnt = 0;
	        while(visited[i] == false)
	        {
	            visited[i] = true;
	            temp_cnt++;
	            i = mp[nums[i]];
	        }
	        if(temp_cnt > 0)
	        {
	            cnt += temp_cnt-1;
	        }
	        
	    }
	    return cnt;
	}
};
