// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

// find the potential candidate by cnt and check if potential candidate is the final answer


class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int maj_ind = 0;
        int cnt = 1;
        for(int i = 0;i<size;i++)
        {
            if(a[maj_ind] == a[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt == 0)
                {
                    maj_ind = i;
                    cnt = 1;
                }
            }
        }
        
        int totcnt = 0;
        for(int i = 0;i<size;i++)
        {
            if(a[maj_ind] == a[i]) totcnt++;
        }
        if(totcnt > (size/2))
        {
            return a[maj_ind];
        }
        else
        {
            return -1;
        }
    }
};
