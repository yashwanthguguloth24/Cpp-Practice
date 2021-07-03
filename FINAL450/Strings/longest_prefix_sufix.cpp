// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#

// Using KMP Algorithm preprocessing procedure to get the answer.

// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
    	int m = s.size();
        // creating longest prefix sufix array
        int lp[m] = {0};
        int index = 0;
        int i = 1;
        while(i<m)
        {
            if(s[index] == s[i])
            {
                lp[i] = index+1;
                index++;
                i++;
            }
            else
            {
                if(index != 0)
                {
                    index = lp[index-1];
                }
                else
                {
                    lp[i] = 0;
                    i++;
                }
            }
        }
        int max_val = lp[m-1];
        return max_val;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends
