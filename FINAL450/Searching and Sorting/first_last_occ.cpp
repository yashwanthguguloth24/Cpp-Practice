// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#


vector<int> find(int arr[], int n , int x )
{
    int i,j;
    int start = -1;
    int end = -1;
    for(i = 0;i<n;i++)
    {
        if(arr[i] == x)
        {
            start = i;
            for(j = i+1;j<n;j++)
            {
                if(arr[j] != x) break;
            }
            end = j-1;
            break;
        }
    }
    vector<int> ans = {start,end};
    return ans;
}
