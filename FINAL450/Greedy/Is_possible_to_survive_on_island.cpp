// https://www.geeksforgeeks.org/survival/

// Greedy approach to take consecutive days to buy food.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Survival(int S,int N,int M)
{
    // if(((6*N < S*M) && S>6) || M>N)
    // {
    //     cout << "No" << endl;
    // }
    // else
    // {
    //     int days = (S*M/N);
    //     if((S*M)%N != 0)
    //     {
    //         days++;
    //     }
    //     cout << "yes" << days << endl;
    // }
    int sundays = S/7;
    int non_sundays = S-sundays;

    int num_days = (S*M/N);
    if((S*M)%N != 0)
    {
        num_days++;
    }
    if(num_days > non_sundays)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "yes : " << num_days << endl;
    }
}






int main()
{
    int S = 10, N = 20, M = 30;
    Survival(S, N, M);
    return 0;
}
