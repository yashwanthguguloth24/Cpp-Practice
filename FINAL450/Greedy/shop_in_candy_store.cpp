// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

// Sorting and iteratiing using 2 pointer method

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int i = 0;
        int j = N;
        int min_buy = 0;
        while(i<j)
        {
            int k = K;
            min_buy += candies[i];
            while(j>=0 && j>i && k>0)
            {
                j--;
                k--;
            }
            i++;
        }
        
        
        i = -1;
        j = N-1;
        int max_buy = 0;
        while(i<j)
        {
            int k = K;
            max_buy += candies[j];
            while(i<=N-1 && j>i && k>0)
            {
                i++;
                k--;
            }
            j--;
        }
        
        
        
        vector<int>ans;
        ans.push_back(min_buy);
        ans.push_back(max_buy);
        return ans;
    }
};
