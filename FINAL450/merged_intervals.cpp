// https://leetcode.com/problems/merge-intervals


class Solution {
public:
    bool sortbysec(const vector<int> &a,const vector<int> &b)
    {
        return (a[0] < b[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_interval;
        for(auto interval : intervals)
        {
            if(merged_interval.empty() || merged_interval.back()[1] < interval[0])
            {
                // not an overlap
                merged_interval.push_back(interval);
            }
            else
            {
                // overlap
                merged_interval.back()[1] = max(merged_interval.back()[1],interval[1]);
            }
        }
//         int n = intervals.size();
//         int mark[n];
//         int marker = 1;
//         mark[0] = marker;
//         int i = 1;
//         while(i<n)
//         {
//             if(intervals[i-1][1] >= intervals[i][0])
//             {
//                 while(i<n && intervals[i-1][1] >= intervals[i][1])
//                 {
//                     mark[i] = marker;
//                     i++;
//                 }
//                 i++;
//             }
//             else
//             {
//                 marker++;
//                 mark[i] = marker;
//                 i++;
//             }
//         }
//         int j = 0;
//         while(j<n)
//         {
//             int start = j;
//             int val = mark[j];
//             j++;
//             while(j<n && mark[j] == val)
//             {
//                 j++;  
//             }
//             int end = j-1;
//             res.push_back({intervals[start][0],max(intervals[end][1],intervals[start][1])});
//         }
        
        
        
        // while(i<intervals.size())
        // {
        //     if(i<intervals.size()-1 && intervals[i][1] >= intervals[i+1][0])
        //     {
        //         int start = i;
        //         int temp = intervals[i][1];
        //         i++;
        //         while(i+1 <intervals.size() && (temp >= intervals[i][1] || intervals[i+1][0] <= intervals[i][1]))
        //         {
        //             i++;
        //         }
        //         int end = i;
        //         res.push_back({intervals[start][0],max(intervals[end][1],intervals[start][1])});
        //         i++;
        //     }
        //     else
        //     {
        //         res.push_back(intervals[i]);
        //         i++;
        //     }
        // }
//         cout << "[";
//         for (int i=0; i<res.size(); i++)
//         {
//         // "first" and "second" are used to access
//         // 1st and 2nd element of pair respectively
//             cout << "[" << intervals[i][0] << "," <<  intervals[i][1] << "]" << endl;
    
//         }
//         cout 
        return merged_interval;
    };
};    
