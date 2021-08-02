// https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1

// put elements in set(has sorted order) then look for least character on right if found update(insert O(logn))


class Solution{
public:
    string chooseandswap(string a){
        int n = a.length();
        
        set<int> st;
        for(int i = 0;i<n;i++)
        {
            st.insert(a[i]);
        }
        
        for(int i =0;i<n;i++)
        {
            st.erase(a[i]);
            
            if(st.empty()) 
            {
                
                break;
            }
            char ch = *st.begin();
            // cout << ch << endl;
            
            if(int(a[i]) > int(ch))
            {
                // cout << "executed" << endl;
                char ch2 = a[i];
                // cout << ch << " " << ch2 << endl;
                for(int j = 0;j<n;j++)
                {
                    if(a[j] == ch)
                    {
                        a[j] = ch2;
                    }
                    else if(a[j] == ch2)
                    {
                        a[j] = ch;
                    }
                }
                break;
            }
            
        }
        return a;
    }
    
};
