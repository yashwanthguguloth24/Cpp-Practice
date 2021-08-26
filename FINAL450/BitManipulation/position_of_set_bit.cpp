// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

// comparing with 2^k

class Solution {
  public:
    int findPosition(int N) {
        // code here
        bool flag = false;
        int onlypos = -1;
        int x = 1;
        while(x<=N)
        {
            if(N&x)
            {
                if(flag)
                {
                    return -1;
                }
                else
                {
                    flag = true;
                    onlypos = log2(x)+1;
                }
            }
            x = x << 1;
        }
        return onlypos;
    }
};
