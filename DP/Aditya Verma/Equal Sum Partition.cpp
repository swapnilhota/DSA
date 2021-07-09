/*
Given an array, determine whether we can partition the array into two subsets with equal sum.
return true or false
*/

//recursive code->

bool solve(vector<int> nums, int n, int target_sum) 
{
	if(n==0)
	{
	    if(target_sum==0)
	    {
		return true;
	    }
	    return false;
	}
	if(target_sum==0)
	{
	    return true;
	}

	if(nums[n-1]<=target_sum)
	{
	    return solve(nums, n-1, target_sum-nums[n-1]) || solve(nums, n-1, target_sum);
	}
	else
	{
	    return solve(nums, n-1, target_sum);
	}
}

//iterative code->
bool canPartition(vector<int>& nums) {
	int sum=0;
	for(auto i: nums) {
		sum+=i;
	}

	if(sum%2!=0) {
		return false;
	}

	bool dp[sum/2+1][nums.size()+1];
	for(int i=0; i<sum/2+1; i++)
	{
		for(int j=0; j<nums.size()+1; j++)
		{
			if(j==0)
			{
				if(i==0)
				{
					dp[i][j]=true;
				}
				else
				{
					dp[i][j]=false;
				}
			}
		}
	}

	for(int j=0; j<nums.size()+1; j++)
	{
		dp[0][j]=true;
	}

	for(int i=1; i<=sum/2; i++)
	{
		for(int j=1; j<=nums.size(); j++)
		{
			if(nums[j-1]<=i)
			{
				dp[i][j] = dp[i-nums[j-1]][j-1] || dp[i][j-1];
			}
			else
			{
				dp[i][j] = dp[i][j-1];
			}
		}
	}

	return dp[sum/2][nums.size()];
}
