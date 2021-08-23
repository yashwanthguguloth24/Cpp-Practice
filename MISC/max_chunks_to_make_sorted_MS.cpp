// https://leetcode.com/problems/max-chunks-to-make-sorted/


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0;
        int max_val = -1;
        
        for(int i = 0;i<n;i++)
        {
            if(arr[i] > max_val)
            {
                max_val = arr[i];
            }
            if(max_val <= i)
            {
                chunks++;
            }
        }
        return chunks;
        
        
    }
};
