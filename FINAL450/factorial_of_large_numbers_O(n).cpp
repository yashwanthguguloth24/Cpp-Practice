// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#


// Approach : Storing current result in an array and multiplying it with 'i' every time and updating the array, use carry if the digits are more than one 

class Solution {
public:
    vector<int> factorial(int N){
        vector <int> nums;
        int arr[10000];
        arr[0] = 1;
        int filled = 1;
        long long int carry = 0;
        for(int i = 2;i<= N;i++)
        {
            for(int j = 0;j<filled;j++)
            {
                arr[j] = arr[j]*i;
                arr[j] += carry;
                carry = 0;
                if(arr[j]>9)
                {
                    int temp = arr[j];
                    arr[j] = temp%10;
                    carry = temp/10;
                }
            }
            if(carry != 0)
            {
                while(carry>0)
                {
                    
                    arr[filled] = carry%10;
                    carry = carry/10;
                    filled++;
                }
                carry = 0;
            }
        }
        for(int i = filled-1;i>=0;i--)
        {
            nums.push_back(arr[i]);
        }

        return nums;
    }
};
