// https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems#

#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	unordered_map<char,int> umap;
    	int n = str.length();
    	for(int i = 0;i<str.length();i++)
    	{
    	    umap[str[i]]++;
    	}
    	int highest_freq = -1;
    	for(auto x:umap)
    	{
    	    highest_freq = max(highest_freq,x.second);
    	}
    	if(highest_freq > (n/2))
    	{
    	    cout << 0 << endl;
    	}
    	else
    	{
    	    cout << 1 << endl;
    	}
    }
	return 0;
}
