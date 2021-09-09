/*
Given a string s, return the length of longest repeating subsequence

Example:-
I/P = "AABEBCDD"
O/P = "ABD"
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    
    string a=s;
    string b=s;
    
    int m=a.length();
    int n=b.length();
    
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i-1]==b[j-1] && i!=j)
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int ans = dp[m][n];
    
    cout<<ans<<endl;
    
    return 0;
}
