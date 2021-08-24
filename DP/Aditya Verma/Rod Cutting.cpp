/*
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. 
Determine the maximum cost obtained by cutting the rod and selling its pieces.
*/

int solve(vector<int> &price, vector<int> &length, int n, int l, vector<vector<int>> &dp)
{
    if(n==0 || l==0)
    {
        return 0;
    }
    if(dp[n][l]!=-1)
    {
        return dp[n][l];
    }
    
    if(length[n-1]<=l)
    {
        int a1 = price[n-1] + solve(price, length, n, l-length[n-1], dp);
        int a2 = solve(price, length, n-1, l, dp);
        return dp[n][l] = max(a1, a2);
    }
    else
    {
        return dp[n][l] = solve(price, length, n-1, l, dp);
    }
}

int cutRod(vector<int> &price, int n)
{
	vector<int> length;
    for(int i=1; i<=n; i++)
    {
        length.push_back(i);
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(price, length, n, n, dp);
}
