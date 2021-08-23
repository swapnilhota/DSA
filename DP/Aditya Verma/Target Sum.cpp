/*
Given an array of numbers, assign sign to each element such that 
the sum of all the numbers equals given target sum

similar to count of subsets with given diff, since we can put positive 
elements into one subset and negative elements into another
*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int helper(int* a, int n, int sum, vector<vector<int>> &dp)
{
    if(sum==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum)
    {
        return dp[n][sum] = helper(a, n-1, sum-a[n-1], dp)+helper(a, n-1, sum, dp);
    }
    else
    {
        return dp[n][sum] = helper(a, n-1, sum, dp);
    }
}

int main()
{
    int n; cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    
    int target_sum; cin>>target_sum;
    
    int total_sum=0;
    for(int i=0; i<n; i++) total_sum+=a[i];
    
    int req_sum = (total_sum-target_sum)/2;
    
    vector<vector<int>> dp(n+1, vector<int>(req_sum+1, -1));
    
    int ans = helper(a, n, req_sum, dp);
    
    cout<<ans<<endl;

    return 0;
}
