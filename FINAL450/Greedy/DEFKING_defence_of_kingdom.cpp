// https://www.spoj.com/problems/DEFKIN/

// Sort the x and y coordinates arrays, then create concecutive diff array for both x and y , pick max from both 2 and multiply to get final answer.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int largest(int arr[], int n)
{
    int i;
     
    int max = arr[0];
 
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}






int main() {
	int t;
	cin >> t;
	while(t--)
	{
        // TAKE INPUT
		int W;
		int H;
		int N;
		cin >> W >> H >> N;
		int x[N+1];
		int y[N+1];
		for(int i = 0;i<N;i++)
		{
			cin >> x[i] >> y[i];
		}
		x[N] = W+1;
		y[N] = H+1;
		
        // sort both x and y coordinates
		sort(x,x+N+1);
		sort(y,y+N+1);
		
        // consecutive diff arrays
		int x_diff[N+1];
        int y_diff[N+1];

        x_diff[0] = x[0]-1;
        y_diff[0] = y[0]-1;
		
        int ans = -1;
        // generating consecutive diff arrrays
		for(int i = 1;i<N+1;i++)
		{
			x_diff[i] = x[i]-x[i-1]-1;
			y_diff[i] = y[i]-y[i-1]-1;
		}

        // largest of both arrays
        int x_max = largest(x_diff,N+1);
        int y_max = largest(y_diff,N+1);

        // area.
        ans = x_max*y_max;
        cout << ans << endl;

		
	}
	return 0;
}
