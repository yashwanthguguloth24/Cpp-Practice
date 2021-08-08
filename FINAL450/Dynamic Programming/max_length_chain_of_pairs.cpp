// https://practice.geeksforgeeks.org/problems/max-length-chain/1#

// sort and LIS

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool compare(val v1,val v2)
{
    return v1.first<v2.first;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,compare);
    vector<int> dp(n,1);
    
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(p[i].first > p[j].second && dp[i] < 1+dp[j])
            {
                dp[i] = 1+dp[j];
            }
        }
    }
    return dp[n-1];
}
