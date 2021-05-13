// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {

        priority_queue<int> pq;
        for(int i = l;i<=r;i++)
        {
            pq.push(arr[i]);
        }
        for(int j = 1;j<=r-l+1-k;j++)
        {
            pq.pop();
        }
        return pq.top();
    
    }
}
