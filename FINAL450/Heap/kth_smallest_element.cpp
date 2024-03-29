// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// Using priority queue c++ stl for max heap and finding n-k-1th largest ==> kth smallest


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) 
    {
        priority_queue<int> maxheap;
        for(int i = l;i<=r;i++)
        {
            maxheap.push(arr[i]);
        }
        int n = r-l+1;
        int kth = n-k;
        while(kth)
        {
            maxheap.pop();
            kth--;
        }
        return maxheap.top();
    }
};
