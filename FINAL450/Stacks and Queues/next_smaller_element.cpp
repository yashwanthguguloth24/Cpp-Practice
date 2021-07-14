// https://www.interviewbit.com/problems/nearest-smaller-element/#

// Use of stacks to keep track of minimum element.

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    vector<int> ans;
    for(int i = 0;i<A.size();i++)
    {
        if(stk.size() == 0)
        {
            ans.push_back(-1);
            stk.push(A[i]);
        }
        else if(A[i] > stk.top())
        {
            ans.push_back(stk.top());
            stk.push(A[i]);
        }
        else
        {
            while(stk.size() != 0 && stk.top()>=A[i])
            {
                stk.pop();
            }
            if(stk.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(stk.top());
            }
            stk.push(A[i]);
        }
    }
    return ans;
}

