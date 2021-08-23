/*
Given an array, find number of pair of subsets with given difference
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
    
    int d; cin>>d;
    
    int total_sum = 0;
    for(int i=0; i<n; i++) total_sum+=a[i];
    
    int target_sum = (total_sum-d)/2;
    
    vector<vector<int>> dp(n+1, vector<int>(target_sum+1, -1));
    
    int ans = helper(a, n, target_sum, dp);
    
    cout<<ans<<endl;

    return 0;
}
