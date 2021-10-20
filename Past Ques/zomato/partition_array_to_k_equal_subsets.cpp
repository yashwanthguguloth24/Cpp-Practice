// https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1


class Solution{
  public:
    
    
    bool flag = false;
    void solve(int i,int a[],int n,int k,vector<int> &sums,int target)
    {
        if(i >= n)
        {
            for(int l = 1;l<k;l++)
            {
                if(sums[l] != sums[l-1])
                {
                    return;
                }
            }
            flag = true;
            return;
        }
        
        if(flag == true)
        {
            return;
        }
        
        for(int j = 0;j<k;j++)
        {
            if(sums[j] == 0)
            {
                sums[j] += a[i];
                solve(i+1,a,n,k,sums,target);
                sums[j] -= a[i];
                break;
            }
            
            if(sums[j]+a[i] <= target)
            {
                sums[j] += a[i];
                solve(i+1,a,n,k,sums,target);
                sums[j] -= a[i];                
            }
        
            if(flag == true)
            {
                return;
            }        
        }
        
        
    }
  
  
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sm = 0;
        for(int i = 0;i<n;i++)
        {
            sm += a[i];
        }
        
        if(k == 1)
        {
            return true;
        }
        
        if(k>n || sm%k != 0)
        {
            return false;
        }
        int target = sm/k;
        vector<int> sums(k,0);
        solve(0,a,n,k,sums,target);
        return flag;
        
         
    }
};
