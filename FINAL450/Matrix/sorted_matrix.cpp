// https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1

// Basic

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector <int> arr;
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
            {
                arr.push_back(Mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int cntr = 0;
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
            {
                Mat[i][j] = arr[cntr];
                cntr++;
            }
        }
        return Mat;
    }
};
