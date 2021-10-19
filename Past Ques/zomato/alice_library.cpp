#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> stk;
	int n = s.length();
	for(int i = 0;i<n-1;i++)
	{
		char ch = s[i];
		if(ch != '\\')
		{
			stk.push(s[i]);
		}
		else
		{
			string temp = "";
			while(stk.size() > 0 && stk.top() != '/')
			{
				temp += stk.top();
				stk.pop();
			}
			stk.pop();
			for(int j = 0;j<temp.length();j++)
			{
				stk.push(temp[j]);
			}
		}
	}
	string res = "";
	while(stk.size() != 1)
	{
		res += stk.top();
		stk.pop();
	}
	cout << res << endl;
	return 0;
}
