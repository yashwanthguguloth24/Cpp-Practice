// https://www.hackerrank.com/challenges/poisonous-plants/problem


int poisonousPlants(vector<int> p) {
    int n = p.size();
    stack<pair<int,int>> stk;
    int ans = -1;
    stk.push({0,-1});
    for(int i = 1;i<n;i++)
    {
        int val = 1;
        while(stk.size() > 0)
        {
            if(p[stk.top().first] >= p[i])
            {
                val = max(val,stk.top().second+1);
                stk.pop();
            }
            else
            {
                break;
            }
        }
        if(stk.size() == 0)
        {
            val = -1;
        }
        ans = max(ans,val);
        stk.push({i,val});
    }
    if(ans < 0)
    {
        return 0;
    }
    return ans;
}
