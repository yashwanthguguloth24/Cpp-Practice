class Solution{
public:
    int fact(int n)
    {
        if(n == 0 || n == 1)
        {
            return 1;
        }
        return (n*fact(n-1));
    }

    int countLess(string S,int i)
    {
        int cnt = 0;
        for(int j = i+1;j<S.length();j++)
        {
            if(S[j] < S[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
    
    bool isRepeated(string S)
    {
        set<char> st;
        int n = S.length();
        for(int i = 0;i<n;i++)
        {
            st.insert(S[i]);
        }
        int l = st.size();
        // cout << n << "  " << st.size() << endl;
        if(l < n)
        {
            return true;
        }
        return false;
    }

    int rank(string S){
        // code here
        if(isRepeated(S)) return 0;
        int m = 1000003;
        int n = S.length();
        int val = fact(n);
        int ans = 1;
        for(int i = 0;i<n;i++)
        {
            val = val/(n-i);
            // cout << val << endl;
            ans += (countLess(S,i))*val;
        }
        return (ans%m);
    }
};
