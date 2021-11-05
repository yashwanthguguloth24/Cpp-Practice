// https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1

// 1 based
class Solution {
  public:
    int safePos(int n, int k) {
        if(n == 1) return 1;
        int x = safePos(n-1,k);
        int y = ((x+k-1)%n)+1;
        return y;
    }
};


// 0 based
long long solve(long long n,long long k)
{
    if(n == 0)
    {
        return 0;
    }
    long long x = solve(n-1,k);
    long long y = (x+k)%n;
    return y;
}


int main()
{
    cout << solve(10,1) << endl;
    return 0;
}
