// https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1/#

// ref -- https://www.youtube.com/watch?v=X2TufR5vY98


// elements can be negative

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int,int>> poss_ele;
        vector<int> visited(n);
        for(int i = 0;i<n;i++)
        {
            poss_ele.push_back({arr[i]-k,i});
            poss_ele.push_back({arr[i]+k,i});
        }
        sort(poss_ele.begin(),poss_ele.end());
        int num_ele = 0;
        int right = 0;
        int left = 0;
        while(num_ele < n && right < poss_ele.size())
        {
            if(visited[poss_ele[right].second] == 0)
            {
                num_ele += 1;
            }
            visited[poss_ele[right].second]++;
            right++;
        }
        int res = poss_ele[right-1].first-poss_ele[left].first;
        // moving window to right
        while(right < poss_ele.size())
        {
            if(visited[poss_ele[left].second] == 1)
            {
                num_ele--;
            }
            visited[poss_ele[left].second]--;
            left++;
            while(num_ele < n && right < poss_ele.size())
            {
                if(visited[poss_ele[right].second] == 0)
                {
                    num_ele += 1;
                }
                visited[poss_ele[right].second]++;
                right++;
            }
            if(num_ele == n)
            {
                res = min(res,poss_ele[right-1].first-poss_ele[left].first);
            }
            else
            {
                break;
            }
        }
        return res;
    
    }
};
