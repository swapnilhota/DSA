/******************************************************************************

Matrix Chain Multiplication

Que -> Given an array denoting sizes of matrices, find out minimum cost in multiplying all these matrices.
        Cost of multiplying two matrices = no. of operations in multiplying them.
        
        if there are two matrices of sizes a*b and b*c, then two multiply them
        no. of ops = a*b*c;
        
        example arr = [40, 30, 20, 10, 30]
        M1 = 40*30
        M2 = 30*20
        M3 = 20*10
        M4 = 10*30
        
        total 4 matrices

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define nline endl

int solve(int* arr, int i, int j, vector<vector<int>> &dp)
{
    if(i>=j)
    {
        return 0;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int ans=INT_MAX;
    
    for(int k=i; k<=j-1; k++)
    {
        int temp = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, temp);
    }
    
    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    
    int ans = solve(a, 1, n-1, dp);
    
    cout<<ans<<nline;

    return 0;
}
