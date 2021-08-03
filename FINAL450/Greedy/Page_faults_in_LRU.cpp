// https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1#

// Use Queue to get mostly recently used value and set for constant time check

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int page_faults = 0;
        set<int> curr_pages;
        queue<int> Q;
        queue<int> Q1;
        for(int i = 0;i<N;i++)
        {
            if(curr_pages.find(pages[i]) == curr_pages.end())
            {
                page_faults++;
                if(curr_pages.size() >= C)
                {
                    curr_pages.erase(Q.front());
                    Q.pop();
                }
                curr_pages.insert(pages[i]);
                Q.push(pages[i]);
            }
            else
            {
                while(Q.size() != 0)
                {
                    if(Q.front() != pages[i])
                    {
                        Q1.push(Q.front());
                    }
                    Q.pop();
                }
                
                while(Q1.size() != 0)
                {
                    Q.push(Q1.front());
                    Q1.pop();
                }
                Q.push(pages[i]);
            }
            
        }
        return page_faults;
    }
};
