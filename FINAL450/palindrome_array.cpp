// https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1


int PalinArray(int a[], int n)
{  
    bool flag = 1;
    for(int i = 0;i<n;i++)
    {
        string digits = "";
        while(a[i]>0)
        {
            int num = a[i]%10;
            digits += to_string(num);
            a[i] = a[i]/10;
        }
        int l = 0;
        int r = digits.length()-1;
        while(r>l)
        {
            if(digits.at(l) != digits.at(r))
            flag = 0;
            l++;
            r--;
        }
        
    }
    return flag;

}
