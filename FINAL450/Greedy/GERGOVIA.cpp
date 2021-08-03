// https://www.spoj.com/problems/GERGOVIA/

// https://www.youtube.com/watch?v=PJdOUDWYstY

// considering nearest possible buy to a sell is a greedy choice


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(1)
	{
		int a[n];
		for(int i = 0;i<n;i++)
		{
			cin>>a[i];
		}
		vector<pair<int,int>> buy;
		vector<pair<int,int>> sell;
		for(int i = 0;i<n;i++)
		{
			if(a[i] > 0)
			{
				buy.push_back(make_pair(a[i],i));
			}
			else
			{
				sell.push_back(make_pair(a[i],i));
			}
		}
		
		int i = 0;
		int j = 0;
		int work = 0;
		while(i<buy.size() && j<sell.size())
		{
			int min_val = min(buy[i].first,-sell[j].first);
			buy[i].first -= min_val;
			sell[i].first += min_val;
			
			int dist = abs(buy[i].second-sell[j].second);
			work += min_val*dist;
			
			if(buy[i].first == 0) i++;
			
			if(sell[j].first == 0) j++;
			
			
		}
		cout << work << endl;
		cin >> n;
		if(n == 0) 
        {
            break;
        }
	}
	return 0;
}
