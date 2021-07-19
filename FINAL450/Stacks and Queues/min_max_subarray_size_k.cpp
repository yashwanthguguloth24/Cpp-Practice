// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

// https://www.youtube.com/watch?v=mUeaCLDdtnM

// using min deque and max deque to iterate

#include<iostream>
#include<deque>
using namespace std;

void subarrayMinMax(int arr[],int n,int k)
{
    deque<int> mx_dq;
    deque<int> mn_dq;
    int ans =  0;
    for(int i = 0;i<n;i++)
    {
        if(mx_dq.size() != 0 && mx_dq.front() == i-k)
        {
            mx_dq.pop_front();
        }

        if(mn_dq.size() != 0 && mn_dq.front() == i-k)
        {
            mn_dq.pop_front();
        }

        while(mx_dq.size() != 0 && arr[i] > arr[mx_dq.back()])
        {
            mx_dq.pop_back();
        }
        while(mn_dq.size() != 0 && arr[i] < arr[mn_dq.back()])
        {
            mn_dq.pop_back();
        }

        mx_dq.push_back(i);
        mn_dq.push_back(i);

        if(i>=k-1)
        {
            cout << "max : " << arr[mx_dq.front()] << "  min :" << arr[mn_dq.front()] << "  sum : " << arr[mx_dq.front()]+arr[mn_dq.front()] << endl;
            ans += arr[mx_dq.front()]+arr[mn_dq.front()];
        }

    }
    cout << "ans :" << ans << endl;
}


int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    subarrayMinMax(arr,7,4);
    return 0;
}
