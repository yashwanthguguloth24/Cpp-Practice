// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

// USING INDEX TRICK i.e (ELEMENTS FROM 0 TO N,SO CAN USE INDICES TO STORE COUNT)


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        for(int i = 0;i<n;i++)
        {
            // cout << arr[i] << endl;
            arr[(arr[i]-1)%(n+1)] = arr[(arr[i]-1)%(n+1)] + (n+1);
        }
        // cout << "**" << endl;
        int miss = -1;
        int repeat = -1;
        for(int i = 0;i<n;i++)
        {
            // cout << arr[i] << endl;
            if((arr[i]/(n+1)) == 2)
            {
                repeat = i+1;
            }
            
            if((arr[i]/(n+1)) == 0)
            {
                miss = i+1;
            }
        }
        int *res = new int[2];
        res[0] = repeat;
        res[1] = miss;
        return res;
    }
};
