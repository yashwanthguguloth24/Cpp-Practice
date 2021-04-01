// https://www.codechef.com/COOK127C/problems/PAWRI


#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    int k = s.length();
	    for(int i = 0;i<(k-4);i++)
	    {
	        string temp = s.substr(i,5);
	        //cout << temp << endl;
	        if(temp == "party")
	        {
	            s.replace(i,5,"pawri");
	        }
	    }
	    cout << s << endl;
	    
	}
	return 0;
}
