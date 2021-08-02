// https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/

// sort based on value and compute quantity everytime to get the answer

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int maxStocks(int price[],int k,int n)
{
    vector<pair<int,int>> stocks;

    for(int i = 0;i<n;i++)
    {
        stocks.push_back(make_pair(price[i],i+1));
    }
    int ans = 0;
    sort(stocks.begin(),stocks.end());

    for(int i = 0;i<n;i++)
    {
        int quant = min(stocks[i].second,(k/stocks[i].first));
        ans += quant;
        k = k - (quant*(stocks[i].first));

    }

    return ans;
}








int main()
{
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;

    cout << maxStocks(price,k,n) << endl;
 
    return 0;
}
