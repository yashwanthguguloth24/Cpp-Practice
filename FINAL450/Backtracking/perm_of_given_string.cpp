// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

// direct application of backtracking

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    	void permute(string a, int l, int r,vector<string> &v1)
        {
            // Base case
            if (l == r)
                v1.push_back(a);
            else
            {
                // Permutations made
                for (int i = l; i <= r; i++)
                {
                    // Swapping done
                    swap(a[l], a[i]);
                    // Recursion called
                    permute(a, l+1, r,v1);
                    //backtrack
                    swap(a[l], a[i]);
                }
            }
        }
 
		vector<string>find_permutation(string S)
		{
		    vector<string> v;
		    int n = S.size();
		    permute(S,0,n-1,v);
		    sort(v.begin(),v.end());
		    return v;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
