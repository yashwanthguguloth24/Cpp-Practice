// https://practice.geeksforgeeks.org/problems/common-elements1132/1#

// If subarray sum is zero, then there will be an element in set already store which is same as of arr[i]
// set contains all continous sum
// if sum = 0
// then prevSum_in_set+sum = prevSum_in_set(which is already present).

class Solution{
    public:
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int cont_sum = 0;
        set <int> lookup;
        for(int i = 0;i<n;i++)
        {
            cont_sum += arr[i];
            if(cont_sum == 0 || lookup.find(cont_sum) != lookup.end())
            {
                return 1;
            }
            else
            {
                lookup.insert(cont_sum);
            }
        }
        return 0;
      
    }
};
