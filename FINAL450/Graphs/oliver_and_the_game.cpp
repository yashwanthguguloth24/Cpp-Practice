// https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/

// https://www.youtube.com/watch?v=5h1JYjin_4o

// using EULER PATH..


/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
// categorize the edges to move in a direction

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void dfs(int i,int par,int &cntr,vector<int>&intime,vector<int>&outime,vector<vector<int>>&adj)
{
	// if(visited[i]) return;
	// visited[i] = true;
	intime[i] = cntr;
	for(int j = 0;j<adj[i].size();j++)
	{
		int u = adj[i][j];
		if(u != par)
		{
			cntr++;
			dfs(u,i,cntr,intime,outime,adj);
		}
	}
	cntr++;
	outime[i] = cntr;
}

bool isSub(int x,int y,vector<int>&intime,vector<int>&outime)
{
	// y is subtree of x
	if(intime[x] < intime[y] && outime[x] > outime[y])
	{
		return true;
	}
	return false;
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> adj(N+1);
	int t = N-1;
	while(t--)
	{
		int a;
		int b;
		cin >> a;
		cin >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> intime(N+1,0);
	vector<int> outime(N+1,0);
	// vector<bool> visited(N+1,false);
	int cntr = 1;
	// visited[1] = true;
	dfs(1,0,cntr,intime,outime,adj);

	int Q;
	cin >> Q;
	while(Q--)
	{
		int is_away;
		int hid;
		int st;
		cin >> is_away;
		cin >> hid;
		cin >> st;
		if(isSub(hid,st,intime,outime)==false && isSub(st,hid,intime,outime)==false)
		{
			cout << "NO" << endl;
		}
		else if(is_away == 1)
		{
			if(isSub(st,hid,intime,outime))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else if(is_away == 0)
		{
			if(isSub(hid,st,intime,outime))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}			
		}
	}

	return 0;
}




