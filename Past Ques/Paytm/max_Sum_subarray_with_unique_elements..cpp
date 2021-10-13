#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> arr = {1,2,3,1,5};
    int n = arr.size();
    int max_sum = arr[0];
    int curr_sum = arr[0];
    set<int> s;
    s.insert(arr[0]);
    int i=0;
    int j = 1;
    while(i < j && j < n)
    {
        if(s.find(arr[j]) == s.end())
        {
            curr_sum += arr[j];
            s.insert(arr[j]);
            max_sum = max(max_sum,curr_sum);
            j++;
        }
        else
        {
            curr_sum -= arr[i];
            s.erase(arr[i]);
            i++;
        }
    }
    
    cout << max_sum << endl;
    return 0;
}
