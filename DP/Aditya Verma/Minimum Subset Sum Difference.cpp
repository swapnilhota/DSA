/*
Determine minimum subset sum difference when given array is divided into to subsets
*/

#include<bits/stdc++.h>
using namespace std;

bool subsetPossible(int a[], int n, int sum)
{
    int dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(i==0)
            {
                dp[i][j]=false;
            }
            if(j==0)
            {
                dp[i][j]=true;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int solve(int a[], int n)
{
    int total_sum=0;
    for(int i=0; i<n; i++)
    {
        total_sum += a[i];
    }

    vector<int> possibleSum;
    possibleSum.push_back(0);
    for(int i=1; i<total_sum; i++)
    {
        if(subsetPossible(a, n, i))
        {
            possibleSum.push_back(i);
        }
    }
    possibleSum.push_back(total_sum);

    int ans = INT_MAX;
    for(int i=0; i<possibleSum.size(); i++)
    {
        ans = min(ans, abs(total_sum-2*possibleSum[i]));
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    cout<<solve(a, n)<<endl;

    return 0;
}
