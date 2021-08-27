// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

// Using priority Queue


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // using priority queue
    auto cmp = [&](pair<int,int> a,pair<int,int> b){ 
        return (mat[a.first][a.second] > mat[b.first][b.second]);
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i = 0;i<n;i++)
    {
        pq.push(make_pair(0,i));
    }
    
    for(int i = 0;i<k-1;i++)
    {
        pair<int,int>tp = pq.top();
        pq.pop();
        // cout << mat[tp.first][tp.second] << endl;
        if(tp.first+1 < n)
        {
            pq.push(make_pair(tp.first+1,tp.second));
        }
    }
    return mat[pq.top().first][pq.top().second];
}
