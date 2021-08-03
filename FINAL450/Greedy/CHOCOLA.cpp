// https://www.spoj.com/problems/CHOCOLA/

// greedy choice is to consider the higher cost cuts when we have low number of pieces


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int m,n;
		cin >> m >> n;
		
		int x[m-1];
		int y[n-1];
		vector<pair<int,int>> cuts;
		
		for(int i = 0;i<m-1;i++)
		{
			cin >> x[i];
			cuts.push_back(make_pair(x[i],0));
		}
		
		for(int i = 0;i<n-1;i++)
		{
			cin >> y[i];
			cuts.push_back(make_pair(y[i],1));
		}
		
		sort(cuts.begin(),cuts.end());
		
		long long int xcuts = 0;
		long long int ycuts = 0;
		long long int ans = 0;
		
		for(int i = cuts.size()-1;i>=0;i--)
		{
			if(cuts[i].second == 0)
			{
				ans += cuts[i].first*(ycuts+1);
				xcuts++;
			}
			else
			{
				ans += cuts[i].first*(xcuts+1);
				ycuts++;				
			}
		}
		cout << ans << endl;
	}

	return 0;
}
