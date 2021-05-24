// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#


// Sorting and using 2 pointer method..

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
            sort(A,A+n);
        for(int i = 0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int s = A[i]+A[j]+A[k];
                if(s == X)
                {
                    return 1;
                }
                else if(s > X)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return 0;
    }

};
