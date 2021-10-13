class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        stack<int> stk;
        int i = n-2;
        ans.push_back(a[n-1]);
        stk.push(a[n-1]);
        while(i >= 0)
        {
            if(stk.size() == 0)
            {
                ans.push_back(a[i]);
                i--;
            }
            else
            {
                if(a[i] < stk.top())
                {
                    i--;
                }
                else
                {
                    while(stk.size() > 0 && a[i] >= stk.top())
                    {
                        stk.pop();
                    }
                    if(stk.size() == 0)
                    {
                        ans.push_back(a[i]);
                        stk.push(a[i]);
                    }
                    i--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
