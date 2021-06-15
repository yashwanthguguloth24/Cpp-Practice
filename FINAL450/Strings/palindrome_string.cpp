// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

int isPlaindrome(char S[])
{
    int n = strlen(S);
    for(int i = 0;i<n/2;i++)
    {
        if(S[i] != S[n-i-1])
        {
            return 0;
        }
    }
    return 1;
}
