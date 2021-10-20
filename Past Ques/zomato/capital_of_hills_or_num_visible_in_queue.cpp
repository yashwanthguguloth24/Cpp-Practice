// https://leetcode.com/problems/number-of-visible-people-in-a-queue/


class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       int n = heights.size();
        vector<int> res(n,0);
        stack<pair<int,int>> stk;
        for(int i = 0;i<n;i++)
        {
            if(stk.size() == 0)
            {
                stk.push({i,0});
            }
            else
            {
                while(stk.size() > 0 && heights[i] > heights[stk.top().first])
                {
                    res[stk.top().first] += stk.top().second+1;
                    stk.pop();
                }
                if(stk.size() != 0)
                {
                    //cout << "here" << " " << stk.top().first << endl;
                    stk.top().second++;
                }
                stk.push({i,0});
            }
        }
        while(stk.size() > 0)
        {
            res[stk.top().first] += stk.top().second;
            stk.pop();
        }
        return res;
    }
};


/// BRUTE****************************

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       int n = heights.size();
        vector<int> res(n,0);
        for(int i = 0;i<n-1;i++)
        {
            res[i]++;
            int mx_val = heights[i+1];
            for(int j = i+2;j<n;j++)
            {
                if(min(heights[i],heights[j]) > mx_val)
                {
                    res[i]++;
                }
                mx_val = max(mx_val,heights[j]);
            }
        }
        return res;
    }
};
