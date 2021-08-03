// https://www.spoj.com/problems/GCJ101BB/

// allowing the faster chick to move forward by swap is the greedy choice


#include <iostream>
using namespace std;

int main() {
	long long int n;
	cin >> n;
	int j = 1;
	while(n--)
	{
		long long N,K,B,T;
		cin >> N >> K >> B >> T;
		
		long long int pos[N];
		long long int vel[N];
		
		for(int i = 0;i<N;i++)
		{
			cin >> pos[i];
		}

		for(int i = 0;i<N;i++)
		{
			cin >> vel[i];
		}
		
		long long int swaps = 0;
		long long int count = 0;
		long long int not_possible = 0;
		
		for(int i = N-1;i>=0;i--)
		{
			long long int dist_needed = B-pos[i];
			long long int dist_poss = vel[i]*T;
			
			if(dist_poss >= dist_needed)
			{
				count++;
				swaps += not_possible;
			}
			else
			{
				not_possible++;
			}
			
			if(count >= K) break;
		}
		
		if(count >= K)
		{
			cout << "Case #" << j << ": " << swaps << endl;
		}
		else
		{
			cout << "Case #" << j << ": " << "IMPOSSIBLE" << endl;
		}
        j++;
		
	}

	return 0;
}
