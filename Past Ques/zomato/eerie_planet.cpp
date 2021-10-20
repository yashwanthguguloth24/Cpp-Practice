// https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/weird-planet-2000a170/


#include <bits/stdc++.h>
using namespace std;


class Node
{
	public:
	int qType;
	int timer;
	int isStart;
	int idx;
	Node(int a,int b,int c,int d)
	{
		qType = a;
		timer = b;
		isStart = c;
		idx = d;
	}
};

bool compare(Node x,Node y)
{
	if(x.timer != y.timer)
	{
		return (x.timer < y.timer);
	}
	else
	{
		return (x.qType < y.qType);
	}
}

int main()
{
	int H,C,Q;
	cin >> H >> C >> Q;
	vector<int> crew_heights(C);
	vector<int> expired(C);
	vector<int> query_heights(Q);
	vector<int> ans(Q);
	vector<Node> arr;
	for(int i = 0;i<C;i++)
	{
		int ht,st,end;
		cin >> ht >> st >> end;
		crew_heights[i] = ht;
		arr.push_back(Node(0,st,1,i));
		arr.push_back(Node(0,end+1,0,i));
	}

	for(int i = 0;i<Q;i++)
	{
		int h,t;
		cin >> h >> t;
		query_heights[i] = h;
		arr.push_back(Node(1,t,0,i));
	}

	priority_queue<pair<int,int>> pq;
	sort(arr.begin(),arr.end(),compare);

	for(int i = 0;i<arr.size();i++)
	{
		Node node = arr[i];
		if(node.qType == 0)
		{
			if(node.isStart == 1)
			{
				pq.push({crew_heights[node.idx],node.idx});
			}
			else
			{
				expired[node.idx] = 1;
			}
		}
		else
		{
			int mx_height = 0;
			while(pq.size() > 0)
			{
				pair<int,int> tp = pq.top();
				if(expired[tp.second] == 0)
				{
					mx_height = tp.first;
					break;
				}
				else
				{
					pq.pop();
				}
			}
			ans[node.idx] = (query_heights[node.idx] > mx_height)?1:0;
		}
	}

	for(int i = 0;i<Q;i++)
	{
		if(ans[i] == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}


	return 0;
}
