// https://leetcode.com/problems/daily-temperatures/

//******APPROACH 1 : Traversing from end to find elements greater on right of that index and reversing the answer.

class Solution {
public:
    // to compute the maximum value on the right
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<int> stk;
        for(int i = temperatures.size()-1;i>=0;i--)
        {
            if(stk.size() == 0)
            {
                ans.push_back(0);
                stk.push(i);
            }
            else if(temperatures[i] >= temperatures[stk.top()])
            {
                while(stk.size() != 0 && temperatures[i] >= temperatures[stk.top()])
                {
                    stk.pop();
                }
                if(stk.size() == 0)
                {
                    ans.push_back(0);
                    stk.push(i);
                }
                else
                {
                    ans.push_back(stk.top()-i);
                    stk.push(i);
                }
            }
            else
            {
                ans.push_back(stk.top()-i);
                stk.push(i);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// APPROACH 2: Traversing from start and removing elements from stack whenever it seems ele greater than it on right.

class Solution {
public:
    // to compute the maximum value on the right
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        The main thing is that if any index is present in stack that implies that it still didnot face an element which is greater on its right.
        */
        vector<int> ans(temperatures.size(),0);
        stack<int> stk;
        for(int i = 0;i<temperatures.size();i++)
        {
            while(stk.size() != 0 && temperatures[i]>temperatures[stk.top()])
            {
                int temp = stk.top();
                stk.pop();
                ans[temp] = i-temp;
            }
            stk.push(i);
        }
        return ans;
    }
};
