/*
Given an array, determine whether we can partition the array into two subsets with equal sum.
return true or false
*/

int main()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++) cin>>a[i];

	int sum=0;
	for(auto i: arr)
	{
		sum+=i;
	}

	if(sum%2!=0)
	{
		cout<<0<<endl;
		return 0;
	}

	solve(arr, n, sum);

	return 0;

}
