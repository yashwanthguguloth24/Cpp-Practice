// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#


// sort by profit and fill the positions on the array if there is any element is not filled


/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool sortbydeadline(Job j1,Job j2)
    {
        return (j1.dead < j2.dead);
    }
    static bool sortbyprofit(Job j1,Job j2)
    {
        return (j1.profit > j2.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans;
        // sort(arr,arr+n,sortbyprofit);
        sort(arr,arr+n,sortbyprofit);
        // vector<Job> v(arr,arr+n);
        // int i = 0;
        // while(i<n)
        // {
        //     int j = i+1;
        //     while(arr[j].dead == arr[j-1].dead)
        //     {
        //         j++;
        //     }
        //     sort(v.begin()+i,v.begin()+(i)+(j-i),sortbyprofit);
        //     i = j+1;
        // }
        
        // vector<int> isbooked((1+v[n-1].dead),-1);
        bool isbooked[n] = {false};
        int num_jobs = 0;
        int max_profit = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = min(n,arr[i].dead-1);j>=0;j--)
            {
                if(isbooked[j] == false)
                {
                    num_jobs++;
                    max_profit += arr[i].profit;
                    isbooked[j] = true;
                    break;
                }
            }
            // cout << isbooked[v[i].dead] << endl;
            // if(isbooked[v[i].dead] != -1)
            // {
            //     // cout << v[i].dead<< endl;
            //     for(int k = v[i].dead-1;k>=1;k--)
            //     {
            //         if(isbooked[k] == -1)
            //         {
            //             isbooked[k] = v[i].profit;
            //             num_jobs++;
            //             max_profit += v[i].profit;
            //             break;
            //         }
            //         else
            //         {
            //             if(isbooked[k] < v[i].profit)
            //             {
            //                 // cout << "executed" <<endl;
            //                 max_profit -= isbooked[k];
            //                 isbooked[k] = v[i].profit;
            //                 max_profit += v[i].profit;
                            
            //             }
            //         }
            //     }
            // }
            // else
            // {
            //     isbooked[v[i].dead] = v[i].profit;
            //     num_jobs++;
            //     max_profit += v[i].profit;
            // }
        }
        
        // for(int i = 0;i<n;i++)
        // {
        //     cout << v[i].dead << "   " << v[i].profit << endl;
        // }
        ans.push_back(num_jobs);
        ans.push_back(max_profit);
        return ans;
        
    } 
};
