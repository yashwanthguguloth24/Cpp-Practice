// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

// similar to kadane, take care of min_value and check if max_profit changes for that prices[i],in single pass


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int n = prices.size();
        int minprice = 100000;
        for(int i = 0;i<n;i++)
        {
            if(prices[i]<minprice)
            {
                minprice = prices[i];
            }
            else if(prices[i]-minprice>max_profit)
            {
                max_profit = prices[i]-minprice;
            }
        }
        return max_profit;
    }
};
