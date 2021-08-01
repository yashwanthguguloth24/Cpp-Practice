// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

// sorting based on the end time of meeting and simple iteration


class Solution
{
    public:
    static bool sortbysec(pair<int,int> a,pair<int,int> b)
    {
        return (a.second < b.second);
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetings;
        for(int i = 0;i<n;i++)
        {
            meetings.push_back(make_pair(start[i],end[i]));
        }
        
        sort(meetings.begin(),meetings.end(),sortbysec);
        
        int num_meets = 1;
        pair<int,int> prev_meet = meetings[0];
        for(int i = 1;i<n;i++)
        {
            if(meetings[i].first > prev_meet.second)
            {
                num_meets++;
                prev_meet = meetings[i];
            }
        }
        return num_meets;
    }
};
