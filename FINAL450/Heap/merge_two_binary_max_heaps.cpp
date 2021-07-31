// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// Merge both arrays and build max heap using the merged array


void heapify(vector<int>&arr,int n,int i)
{
    int largest = i;
    int l = 2*i+1; // left child
    int r = 2*i+2;

    if(l<n && arr[l]>arr[largest])
    {
        largest = l;
    } 

    if(r<n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }                      
}

void buildHeap(vector<int>&arr,int n)
{
    int start_ind = (n/2)-1;
    while(start_ind >= 0)
    {
        heapify(arr,n,start_ind);
        start_ind--;
    }

}








class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(int i = 0;i<a.size();i++)
        {
            ans.push_back(a[i]);
        }
        
        for(int i = 0;i<b.size();i++)
        {
            ans.push_back(b[i]);
        }
        
        buildHeap(ans,ans.size());
        // for(int i = 0;i<ans.size();i++)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        return ans;
    }
};
