// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/


#include<iostream>
using namespace std;

bool KMP_SubString(string text,string pattern)
{
    int n = text.size();
    int m = pattern.size();
    // creating longest prefix sufix array
    int lps[m] = {0};
    int index = 0;
    int i = 1;
    while(i<m)
    {
        if(pattern[index] == pattern[i])
        {
            lps[i] = index+1;
            index++;
            i++;
        }
        else
        {
            if(index != 0)
            {
                index = lps[index-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    // Substring search
    i = 0;
    int j = 0;
    
    while(i<n && j<m)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }

    if(j == m)
    {
        //cout << "match" << endl;
        return true;
    }
    else
    {
        //cout << "not match" << endl;
        return false;
    }
}


int main()
{
    string s1 = "ABACD";
    string s2 = "CDABA";
    s1 = s1+s1;
    bool flag = KMP_SubString(s1,s2);
    if(flag)
    {
        cout << "The strings are rotations of each other" << endl;
    }
    else
    {
        cout << "The strings are not the rotations of each other" << endl;
    }
    return 0;
}
