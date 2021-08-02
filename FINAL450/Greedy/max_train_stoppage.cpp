// https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

// sorting by departure and updating 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Trains
{
    public:
    int arrival;
    int depart;
    int platform;

    Trains(int a,int b,int c)
    {   
        arrival = a;
        depart = b;
        platform = c;
    }
};

class Solution
{
    public:
    static bool compare(Trains &T1,Trains &T2)
    {
        return (T1.depart < T2.depart);
    }

    int TrainStoppage(Trains arr[],int n)
    {
        int platforms[n+1] = {-1};
        int max_stops = 0;
        sort(arr,arr+n,compare);
        for(int i = 0;i<n;i++)
        {
            if(platforms[arr[i].platform] == -1)
            {
                max_stops++;
                platforms[arr[i].platform] = arr[i].depart;
            }
            else
            {
                if(arr[i].arrival > platforms[arr[i].platform])
                {
                    max_stops++;
                    platforms[arr[i].platform] = arr[i].depart;
                }
            }
        }
        return max_stops; 
    }

};







int main()
{
    Solution s;
    // Trains arr[] = {Trains(1000, 1030, 1),Trains(1010, 1020, 1),Trains(1025, 1040, 1),Trains(1130, 1145, 2),Trains(1130, 1140, 2)};
    
    Trains arr[] = {Trains(1000, 1030, 1),Trains(1010, 1030, 1),Trains(1000, 1020, 2),Trains(1030, 1230, 2),Trains(1200,1230, 3),Trains(900, 1005, 1)};
    cout << s.TrainStoppage(arr,6) << endl;

    return 0;
}
