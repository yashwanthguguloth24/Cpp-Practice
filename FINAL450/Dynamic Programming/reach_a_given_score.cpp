// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

// Coin Change problem..

long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	
	// Your code here
	int scores[3] = {3,5,10};
	
    for(i = 1;i<n+1;i++)
    {
        table[i] = 0;
    }
    
	for(int j = 0;j<3;j++)
	{
	    for(i = 1;i<n+1;i++)
	    {
	        if(i>=scores[j])
	        {
                table[i] += table[i-scores[j]];
	        }
	    }
	}

	
	
	return table[n];
}
