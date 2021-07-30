// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

// https://www.youtube.com/watch?v=aVR6mn0Ag2I

// Using priority queue for min heap, new class ELE ans we need row,col,val for a point to go its right in a col.

class ele
{
    public:
    int row;
    int col;
    int val;
    ele(int a,int b,int c)
    {
        row = a;
        col = b;
        val = c;
    }
};


class myComparator
{
public:
    bool operator()(ele e1,ele e2)
    {
        return (e1.val > e2.val);
    }
};
 





class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<ele,vector<ele>,myComparator> mnheap;
        for(int i = 0;i<K;i++)
        {
            ele temp(i,0,arr[i][0]);
            mnheap.push(temp);
        }
        
        while(!mnheap.empty())
        {
            ele tp = mnheap.top();
            mnheap.pop();
            ans.push_back(tp.val);
            
            if(tp.col < K-1)
            {
                int row = tp.row;
                int col = tp.col+1;
                ele topush(row,col,arr[row][col]);
                mnheap.push(topush);
            }
        }
        return ans;
        
    }
};
