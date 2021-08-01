// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

/*
struct Item{
    int value;
    int weight;
};
*/
static bool compare(Item I1,Item I2)
{
    double a1 = (double)(I1.value/I1.weight);
    double a2 = (double)(I2.value/I2.weight);
    return a1>a2;
}



class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        sort(arr,arr+n,compare);
        for(int i = 0;i<n;i++)
        {
            if(W >= arr[i].weight)
            {
                ans += (arr[i].value);
                W = W - arr[i].weight;
            }
            else
            {
                ans += arr[i].value*((double)W/arr[i].weight);
                break;
            }
        }
        return ans;
    }
        
};
