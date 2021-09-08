/******************************************************************************

Shortest Common SuperSequence

Given two strings, return the length of SCS


*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int lcs(string a, string b, int m, int n, vector<vector<int>> &dp)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    if(a[m-1]==b[n-1])
    {
        return dp[m][n] = 1+lcs(a, b, m-1, n-1, dp);
    }
    else
    {
        return dp[m][n] = max(lcs(a, b, m-1, n, dp), lcs(a, b, m, n-1, dp));
    }
}

int main()
{
    string a, b;
    cin>>a>>b;
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));
    int ans = a.length() + b.length() - lcs(a, b, a.length(), b.length(), dp);
    
    cout<<ans<<endl;

    return 0;
}
