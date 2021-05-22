// https://practice.geeksforgeeks.org/problems/count-element-occurences/1#


// Using hashing directly to store the counts.

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int,int> d;
        for(int i = 0;i<n;i++)
        d[arr[i]]++;
        int cnt = 0;
        for(auto x:d)
        {
            if(x.second > (n/k))
            cnt++;
        }
        return cnt;
    }
};
