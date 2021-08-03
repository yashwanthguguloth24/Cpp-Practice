// https://practice.geeksforgeeks.org/problems/smallest-number5829/1#

// greedly put max value at the units place to get min number

class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string res = "";
        while(S and D)
        {
            if(S>9)
            {
                res += to_string(9);
                S -= 9;
                D--;
            }
            else
            {
                if(D>1)
                {
                    res += to_string(S-1);
                    S = 1;
                    D--;
                }
                else if(D == 1)
                {
                    res += to_string(S);
                    S = 0;
                    D = 0;
                }
            }
        }
        
        if(S>0)
        {
            return "-1";
        }
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};
