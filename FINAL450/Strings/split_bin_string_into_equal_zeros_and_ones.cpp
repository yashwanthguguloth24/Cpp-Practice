// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/


// set two counter for 1 and 0 and increase counter of split if counters of 1 and 0 are equal.

#include<iostream>
using namespace std;

int SubStringEQualOnesAndZeros(string s)
{
    int count0 = 0;
    int count1 = 0;
    int cntr = 0;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '0')
        {
            count0++;
        }
        else if(s[i] == '1')
        {
            count1++;
        }
        if(count1 == count0)
        {
            cntr++;
        }
    }
    return cntr;
}



int main()
{
    string s1 = "0100110101";
    cout << SubStringEQualOnesAndZeros(s1) << endl;
    return 0;
}
