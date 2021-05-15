// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// ref -- https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/

class Solution{
  public:
    int minJumps(int arr[], int n){
        // base case
        if(n <= 1)
        {
            return 0;
        }
        if(arr[0] == 0)
        {
            return -1;
        }
        
        int jumps_till_now = 1; // counting 1st step and not counting last step
        int max_index_reach = arr[0]; // max reacheable index at any moment
        int steps_rem = arr[0];  // number of current steps we have so as to consider for a jump or not
        for(int i = 1;i<n;i++)
        {
            if (i == n-1)
            {
                return jumps_till_now;
            }
            max_index_reach = max(max_index_reach,i+arr[i]); // update reach every time
            steps_rem = steps_rem-1; // every time we move one step forward
            if(steps_rem == 0) // jump is required here..
            {
                jumps_till_now = jumps_till_now + 1;
                // if the current index is not reachable
                if (i >= max_index_reach)
                {
                    return -1;
                }
                // prominent as we need to consider effect of previous reaches as well
                // if we use steps_rem = arr[i], we are loosing that effect.
                steps_rem = max_index_reach-i ;
                
            }
        }
        return -1;
    }
};

