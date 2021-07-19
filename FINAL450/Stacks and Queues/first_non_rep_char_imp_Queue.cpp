// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// https://www.youtube.com/watch?v=2Z--YYbzigU

// Using Hash,Queue . Hash for frquency of characters and Queue to keep track non repeating char , updating it if frequency of char exceeds 1
// This problem is also solved using Queue.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> freq(26,0);
		    queue<char> q;
		    string ans = "";
		    for(int i = 0;i<A.length();i++)
		    {
		        freq[A[i]-'a']++;
		        if(freq[A[i]-'a'] <= 1)
		        {
		            q.push(A[i]);
		        }
		        while(q.size() != 0 && freq[q.front()-'a'] > 1)
		        {
		            q.pop();
		        }
		        if(q.size() == 0)
		        {
		            ans += "#";
		        }
		        else
		        {
		            ans.push_back(q.front());
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
