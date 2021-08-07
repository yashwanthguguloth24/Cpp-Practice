// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

// dp[i]-ways to pair first I people, 2 cases 1.indiv--dp[i-],2.can pair with i-1 people so (i-1)*dp[i-2]

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        long long int dp[n+1] = {0};
        long long m = pow(10,9)+7;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<n+1;i++)
        {
            dp[i] = (dp[i-1]%m) + ((i-1)%m)*(dp[i-2]%m);
        }
        return (dp[n]%m);
        
    }
};    
 
