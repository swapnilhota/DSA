#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    
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
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string ans="";
    
    int i=m;
    int j=n;
    
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans += a[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    cout<<ans<<endl;

    return 0;
}
