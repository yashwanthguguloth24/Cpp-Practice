// https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/

// using backtracking

#include<bits/stdc++.h>
using namespace std;

vector<string> res;

int genNum(string s,int i1,int i2)
{
    int ans;
    if(s[i1] == '0')
    {
        return -1;
    }
    string num = "";
    for(int i = i1;i<=i2;i++)
    {
        num += s[i];
    }
    ans = stoi(num);

    return ans;
}

bool isvalid(int x)
{
    // static int h = 0;
    // h++;
    // cout << h << " : " << x << endl;
    if(x < 0  || x > 255)
    {
        return false;
    }
    // cout << h << " : " << x << endl;
    return true;
}


void snapshotIP(string s,int seg,int ind,vector<int> path)
{
    // cout << seg << endl;
    if(seg == 4 && (ind == s.length()))
    {
        string temp = to_string(path[0]) + "." + to_string(path[1]) + "." + to_string(path[2]) + "." + to_string(path[3]);
        // cout << temp << endl;
        res.push_back(temp);
        return ;
    }

    if(seg == 4 || ind == s.length())
    {
        return;
    }

    for(int i = ind;i<= min((int)(s.length()-1),ind+2);i++)
    {
        if(isvalid(genNum(s,ind,i)))
        {
            path[seg] = genNum(s,ind,i);
            snapshotIP(s,seg+1,i+1,path);
            path[seg] = 0;
        }
    }
}





void GenerateIPs(string s)
{
    vector<int> path(4,0);
    snapshotIP(s,0,0,path);
}


int main()
{
    string a;
    cin >> a;
    GenerateIPs(a);
    if(res.size() == 0)
    {
        cout << -1 << endl;
    }
    for(int i = 0;i<res.size();i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
