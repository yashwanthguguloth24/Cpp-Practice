class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
        int n = N;
        int j = n-1;
        int i = 0;
        while(i<n && i < j)
        {
            if(arr[i]%2 == 0)
            {
                i++;
            }
            else
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j--;
            }
        }
        int l = n-1;
        int k = 0;
        while(k < l)
        {
            if(k%2 == 0)
            {
                k++;
                l--;
            }
            else
            {
                int t = arr[k];
                arr[k] = arr[l];
                arr[l] = t;
                k++;
                l--;
                
            }
        }
    }
};
