// https://practice.geeksforgeeks.org/problems/power-set4302/1

// generate counter and consider char in the string if counter[i][j] = 1


class Solution{
	public:

	

	vector<string> AllPossibleStrings(string s){
	    vector<string>ans;
	    int n = s.length();
	    int n_s = pow(2,n);
	    for(int cntr = 1;cntr < n_s;cntr++)
	    {
	        string temp = "";
	        for(int i = 0;i<=n-1;i++)
	        {
	            if(((1<<i)&cntr))
	            {
	                temp += s[i];
	            }
	        }
	        ans.push_back(temp);
	    }
	    sort(ans.begin(),ans.end());
	   // cout << ans.size()<< endl;
	    return ans;
	    
	}
};
