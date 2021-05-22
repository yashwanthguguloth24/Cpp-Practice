// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#


// Approach : Store elements in set for O(1) access and iterate through array to check consequent elements of arr[i] exists and update counter . 
// Add If conditon to see if arr[i] start of consecutive subsequence .


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set <int> s;
        int ans = 0;
        for(int i = 0;i<N;i++)
        s.insert(arr[i]);
        

        for(int i = 0;i<N;i++)
        {
            int cnt = 1;
            if(s.find(arr[i]-1) == s.end())
            {
                int temp = arr[i];
                while(s.find(temp+cnt) != s.end())
                {
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
