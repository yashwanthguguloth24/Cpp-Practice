// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// USING MERGE SORT

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long mergeSort(long long l,long long r,long long arr[],long long N)
    {
        if(l >= r)
        {
            return 0;
        }
        long long mid = (l+r)/2;
        long long left = mergeSort(l,mid,arr,N);
        long long  right = mergeSort(mid+1,r,arr,N);
        long long  invs = merge(l,mid,r,arr,N);
        return (left+right+invs);
 
    }
    
    long long merge(long long l,long long  mid,long long r,long long arr[],long long N)
    {
        long long invs = 0;
        long long temp[r-l+1] = {0};
        long long i = l;
        long long j = mid+1;
        long long k = 0;
        while(i <= mid && j <= r)
        {
            if(arr[i] > arr[j])
            {
                // inversion occur here
                invs += (mid-i+1);
                // cout << "(" << mid << "," << i << "," << j << ")" << " ";
                temp[k] = arr[j];
                k++;
                j++;
            }
            else
            {
                temp[k] = arr[i];
                k++;
                i++;
            }
        }
        
        while(i<=mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        
        while(j <= r)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
        
        for(long long a = l;a<=r;a++)
        {
            arr[a] = temp[a-l];
        }
        
        return invs;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long  inv_cnt = 0;
        long long  n = (int) N;
        inv_cnt = mergeSort(0,n-1,arr,N);
        return inv_cnt;
    }

};
