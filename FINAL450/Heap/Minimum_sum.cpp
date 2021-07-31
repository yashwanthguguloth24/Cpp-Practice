// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#

// Min heap is giving TLE .solved it by sorting and considering alternate values as numnbers

class myComparator
{
public:
    bool operator()(int e1,int e2)
    {
        return (e1 > e2);
    }
};
 


class Solution{   
public:
    string findSum(string str1, string str2)
    {
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length())
            swap(str1, str2);
     
        // Take an empty string for storing result
        string str = "";
     
        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;
     
        // Initially take carry zero
        int carry = 0;
     
        // Traverse from end of both strings
        for (int i=n1-1; i>=0; i--)
        {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i]-'0') +
                       (str2[i+diff]-'0') +
                       carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
     
        // Add remaining digits of str2[]
        for (int i=n2-n1-1; i>=0; i--)
        {
            int sum = ((str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
     
        // Add remaining carry
        if (carry)
            str.push_back(carry+'0');
     
        // reverse resultant string
        reverse(str.begin(), str.end());
     
        return str;
    }
    
    
    string solve(int arr[], int n) {
        priority_queue<int,vector<int>,myComparator> mnheap;
        for(int i = 0;i<n;i++)
        {
            mnheap.push(arr[i]);
        }
        string num1;
        string num2;
         // MIN HEAP METHOD..
        // while(!mnheap.empty())
        // {
        //     if(mnheap.size() != 0)
        //     {
        //         int top1 = mnheap.top();
        //         mnheap.pop();
        //         // num1 = num1*10+top1;
        //         if(top1 == 0 && num1.length() == 0) continue;

        //         num1 += to_string(top1);                
                
                
                

                
        //     }
        //     if(mnheap.size() != 0)
        //     {
        //         int top2 = mnheap.top();
        //         mnheap.pop();
        //         // num2 = num2*10+top2;
        //         if(top2 == 0 && num2.length() == 0) continue;

        //         num2 += to_string(top2);                 
        //     }
        // }
        sort(arr,arr+n);
        // long long num1 = 0;
        // long long num2 = 0;
        for(int i = 0;i<n;i++)
        {
            if(i%2 == 0)
            {
                if(arr[i] == 0 && num1.length() == 0) continue;

                num1 += to_string(arr[i]);  
            }
            else
            {
                if(arr[i] == 0 && num2.length() == 0) continue;

                num2 += to_string(arr[i]); 
            }
        }


        

        // reverse(res.begin(),res.end());
        return findSum(num1,num2);
        
    }
    
};
