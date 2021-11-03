// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap = (n+m);
            int i = 0;
            while(gap>0)
            {
                for(i = 0;i+gap<n;i++)
                {
                    if(arr1[i+gap] < arr1[i])
                    {
                        long long temp = arr1[i];
                        arr1[i] = arr1[i+gap];
                        arr1[i+gap] = temp;
                    }
                }
                
                int j;
                for(j = i+gap-n;i<n && j<m;i++,j++)
                {
                    if(arr2[j] < arr1[i])
                    {
                        long long temp = arr1[i];
                        arr1[i] = arr2[j];
                        arr2[j] = temp;                
                    }
                }
                
                if(j < m)
                {
                    for(j=0;j+gap<m;j++)
                    {
                        if(arr2[j+gap] < arr2[j])
                        {
                            long long temp = arr2[j];
                            arr2[j] = arr2[j+gap];
                            arr2[j+gap] = temp;
                        }            
                    }
                }
                
                if(gap == 1) return;
                
                //int k = ((gap%2 == 0)?(0):(1));
                
                gap = (gap/2) + (gap%2);
            }
        } 
};
