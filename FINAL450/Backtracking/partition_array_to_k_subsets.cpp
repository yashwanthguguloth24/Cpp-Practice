// https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

// filling subsets such that,fill in non empty or in empty(if empty fill in it and break)


class Solution{
  public:
  bool flag = false;
  
  void PartitionRec(int arr[],int idx,int n,int k,int ne,vector<vector<int>> pt,vector<int> sums)
  {
      // base cases
      if(idx == n)
      {
          if(ne == k)
          {
              bool s = true;
              for(int i = 0;i<k-1;i++)
              {
                  if(sums[i] != sums[i+1])
                  {
                      s = false;
                      break;
                  }
              }
              if(s)
              {
                  flag = true;
              }
          }
          return;
      }
      
      
      
      for(int i = 0;i<k;i++)
      {
          if(pt[i].size() > 0)
          {
              pt[i].push_back(arr[idx]);
              sums[i] += arr[idx];
              PartitionRec(arr,idx+1,n,k,ne,pt,sums);
              sums[i] -= arr[idx];
              pt[i].pop_back();
          }
          else
          {
              pt[i].push_back(arr[idx]);
              sums[i] += arr[idx];
              PartitionRec(arr,idx+1,n,k,ne+1,pt,sums);
              sums[i] -= arr[idx];
              pt[i].pop_back();
              break;
          }
      }
  }
  
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
        // base cases
        int sm = 0;
        for(int i =0;i<n;i++)
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
        
        vector<vector<int>> pt(k);
        vector<int> sums(k,0);
        PartitionRec(a,0,n,k,0,pt,sums);
        return flag;
    }
};
