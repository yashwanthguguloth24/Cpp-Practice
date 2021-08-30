// https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/

// if str[i][j] = target[0],take this as starting point and check for remaining characters


#include<bits/stdc++.h>
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))
using namespace std;


vector<int> rd = {-1,0,1,0};
vector<int> cd = {0,1,0,-1};

int ans = 0;
bool isvalid(int i,int j,int n,int m)
{
    if(i<0 || i > n-1 || j<0 || j>m-1)
    {
        return false;
    }
    return true;
}

void searchOcc(int r,int c,int n,int m,int str_ind,string needle,string input[])
{
    //base case
    // cout << "(" << r << "," << c << ")" << " : " <<  str_ind  << endl;
    if(str_ind == needle.length())
    {
        ans++;
        // cout << "(" << r << "," << c << ")" << endl;
        return;
    }
    for(int i = 0;i<4;i++)
    {
        int nr = r+rd[i];
        int nc = c+cd[i];
        if(isvalid(nr,nc,n,m) && input[nr][nc] == needle[str_ind])
        {
            searchOcc(nr,nc,n,m,str_ind+1,needle,input);
        }
    }
}



void count_occurances(string input[],string needle,int n,int m)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(input[i][j] == needle[0])
            {
                searchOcc(i,j,n,m,1,needle,input);
            }
        }
    }
}



int main()
{
    // string needle = "MAGIC";
    // string input[] = { "BBABBM",
    //                    "CBMBBA",
    //                    "IBABBG",
    //                    "GOZBBI",
    //                    "ABBBBC",
    //                    "MCIGAM" };
    string input[] ={
            {"DDDGDD"},
            {"BBDEBS"},
            {"BSKEBK"},
            {"DDDDDE"},
            {"DDDDDE"},
            {"DDDDDG"}
           };
    string needle = "GEEKS";
    int n = 6;
    int m = input[0].length();
    count_occurances(input,needle,n,m);
    cout << ans << endl;
    return 0;
}
