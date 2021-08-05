// https://www.geeksforgeeks.org/tug-of-war/

// considering the 2 possibilities for a element, be in set1 or set2


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int min_diff = INT_MAX;
vector<int> ans1;
vector<int> ans2;
vector<int> s1;
vector<int> s2;
void Rec(vector<int> vec,int i,int s1_sum,int s2_sum,int s1_cnt,int s2_cnt)
{
    int n = vec.size();
    if(i > n-1)
    {
        cout << s1_cnt << " " << s2_cnt << endl;
        if(abs(s1_sum-s2_sum) < min_diff)
        {
            ans1 = s1;
            ans2 = s2;
        }
        min_diff = min(min_diff,abs(s1_sum-s2_sum));
        
        return;
    }

    if(s1_cnt < ((n+1)/2))
    {
        s1.push_back(vec[i]);
        s1_sum += vec[i];
        Rec(vec,i+1,s1_sum,s2_sum,s1_cnt+1,s2_cnt);
        s1_sum -= vec[i];
        s1.pop_back();
    }
    if(s2_cnt < (n/2))
    {
        s2.push_back(vec[i]);
        s2_sum += vec[i];
        Rec(vec,i+1,s1_sum,s2_sum,s1_cnt,s2_cnt+1);
        s2_sum -= vec[i];
        s2.pop_back();        
    }
}







int main()
{
    vector<int> vec = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    // vector<int> vec = {1,2,3,4,5,6};
    Rec(vec,0,0,0,0,0);
    cout << min_diff << endl;
    for(int i = 0;i<ans1.size();i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
    for(int i = 0;i<ans2.size();i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;    
    
    return 0;
}
