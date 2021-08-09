// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

// using kadanes algo by replacing 1 with -1 and 0 with 1.Refer this for kadane https://www.youtube.com/watch?v=VMtyGnNcdPw


class Solution{
public:	
	int maxSubstring(string S)
	{
	    int curr_sum = (S[0] == '1')?-1:1;
	    int overall_sum = curr_sum;
	    
	    for(int i = 1;i<S.length();i++)
	    {
	        if(curr_sum >= 0)
	        {
	            curr_sum += (S[i] == '1')?-1:1;
	        }
	        else
	        {
	            curr_sum = (S[i] == '1')?-1:1;
	        }
	        overall_sum = max(curr_sum,overall_sum);
	    }
	    return overall_sum;
	}
};
