/*

Credits:- Aditya Verma YouTube Channel

Problem:- Is there a subset present in given array whose sum is equal to given target sum.
arr[] -> array of numbers
sum -> target sum
n -> array size

*/

/********* Recursive *********/

bool subsetSum(int arr[], int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
        {
            return true;
        }
        return false;
    }
    if (sum == 0)
    {
        return true;
    }

    if (arr[n - 1] <= sum)
    {
        return subsetSum(arr, n - 1, sum - arr[n - 1]) || subsetSum(arr, n - 1, sum);
    }
    else
    {
        return subsetSum(arr, n - 1, sum);
    }
}

/********* Top-Down approach ***********/

bool subsetSum(int arr[], int n, int sum)
{
    //dp array for storing values
    bool dp[n + 1][sum + 1];

    //initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false; //if n==0 no sum possible
            }
            if (j == 0)
            {
                dp[i][j] = true; //if sum==0 empty array is the ans
            }
        }
    }

    //solving iteratively
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
  
    return dp[n][sum];
}
