// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

// https://www.youtube.com/watch?v=bWowdBPkidw&t=1455s

// Initially push all start elements,then pop min val compute range, if range is less update low , high and push next val of min val popped


class ele
{
    public:
        int val;
        int row;
        int col;
        ele(int a,int b,int c)
        {
            val = a;
            row = b;
            col = c;
        }
};

class minmyComparator
{
public:
    bool operator()(ele e1,ele e2)
    {
        return (e1.val > e2.val);
    }
};

class maxmyComparator
{
public:
    bool operator()(ele e1,ele e2)
    {
        return (e1.val < e2.val);
    }
};




class Solution{
    public:
    // priority_queue<ele, vector<ele>,maxmyComparator> mxheap;
    priority_queue<ele, vector<ele>,minmyComparator> mnheap;
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        int mx = INT_MIN;
        pair<int,int> ans;
        int mn = INT_MAX;
        int range = INT_MAX;
        int low,high;
        for(int i = 0;i<k;i++)
        {
            mnheap.push(ele(arr[i][0],i,0));
            // mxheap.push(ele(arr[i][0],i,0));
            if(arr[i][0] > mx)
            {
                mx = arr[i][0];
            }
        }
        
        while(!mnheap.empty())
        {
            ele start = mnheap.top();
            mnheap.pop();

            
            if(range > (mx-start.val))
            {
                mn = start.val;
                range = mx-start.val;
                low = mn;
                high = mx;
            }
            
            
            if(start.col == n-1)
            {
                break;
            }
            
            if(start.col < n-1)
            {
                mnheap.push(ele(arr[start.row][start.col+1],start.row,start.col+1));
                // mxheap.push(ele(arr[start.row][start.col+1],start.row,start.col+1));
                if(arr[start.row][start.col+1] > mx)
                {
                    mx = arr[start.row][start.col+1];
                }
            }


        }
        
        ans.first = low;
        ans.second = high;
        return ans;
        
        
    }
};
