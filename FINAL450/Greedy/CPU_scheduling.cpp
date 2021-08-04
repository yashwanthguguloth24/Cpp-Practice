// https://www.geeksforgeeks.org/program-for-shortest-job-first-or-sjf-cpu-scheduling-set-1-non-preemptive/ 

// greedy choice is to consider the task with minima burst time


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1,vector<int> v2)
{
    if(v1[1] == v2[1])
    {
        if(v1[2] == v2[2])
        {
            return v1[0] < v2[0];
        }
        return v1[2] < v2[2];
    }
    return v1[1] < v2[1];
}



void CPU_Scheduling(vector<vector<int>> tasks,int n)
{
    sort(tasks.begin(),tasks.end(),compare);

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> >pq;

    pq.push({tasks[0][2],tasks[0][1],tasks[0][0]});

    int i = 1;
    int curr_time = 0;
    while(pq.size() != 0)
    {
        int burst_time = pq.top()[0];
        int id = pq.top()[2];
        cout << "Task processed with id : " << id << endl;
        pq.pop();
        curr_time += burst_time;
        while(true)
        {
            if(i<n && tasks[i][1] <= curr_time)
            {
                pq.push({tasks[i][2],tasks[i][1],tasks[i][0]});
                i++;
            }
            else
            {
                break;
            }
        }
    }

}




int main()
{
    int n;
    cin >> n;
    int val;
    vector<vector<int>> tasks;
    for(int i = 0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<3;j++)
        {
            cin >> val;
            temp.push_back(val);
        }
        tasks.push_back(temp);
        temp.clear();
    }
    CPU_Scheduling(tasks,n);
    return 0;
}
