// https://www.spoj.com/problems/DIEHARD/
// https://www.youtube.com/watch?v=xOFobtsVIs0

// Greedy choice : 1.alternate air 2.choose water if A>10

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int H,A;
		cin >> H >> A;
		int time_survive = 0;
		
		while(1)
		{
			if(time_survive%2 == 0)
			{
				H = H + 3;
				A = A + 2;
			}
			else
			{
                if(A>10)
                {
                    H = H-5;
                    A = A-10;    
                }
                else
                {
                    H = H-20;
                    A = A+5;                    
                }
		    }

            if(H > 0 && A>0)
            {
                time_survive++;
            }
            else
            {
                break;
            }
        }
        cout << time_survive <<endl;

	}

	return 0;
}
