// https://practice.geeksforgeeks.org/problems/common-elements1132/1#


class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector <int> common_ele;
            int i = 0,j = 0,k = 0;
            while(i < n1 && j < n2 && k < n3)
            {
                // taking care of duplicates
                while(i>0 && i < n1 && A[i-1] == A[i])
                {
                    i++;
                }

                while(j>0 && j< n2 && B[j-1] == B[j])
                {
                    j++;
                }

                while(k>0 && k<n3 && C[k-1] == C[k])
                {
                    k++;
                }
                
                //check if equal
                if((A[i] == B[j]) && (B[j] == C[k]))
                {
                    common_ele.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                else
                {
                    // moving right the smallest element present
                    if(A[i] < B[j])
                    {
                        i++;
                    }
                    else if(B[j] < C[k])
                    {
                        j++;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
            return common_ele;
            
        }

};
