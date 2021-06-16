/*

credits:- Aditya Verma YouTube Channel

01 Knapsack Problem
wt[] -> weight array of items
val[] -> value array of items
W -> knapsack capacity
n -> array size

*/

/************************ normal recursive solution ***********************/

int knapsack(int wt[], int val[], int W, int n)
{
  
  
  //Base Case->
  if(n==0 || W==0)
  {
    return 0;
  }
  
  if(wt[n-1]<=W)
  {
    return max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));        
  }
  else
  {
    return knapsack(wt, val, W, n-1);
  }
}

/********************** memoization ************************/

// make dp array for variables which are changing in recursive calls, like in this question, size of array (n) and capacity of knapsack (W)
// declaring a global array according to the constraints of the question i.e. max values of variables which are changing in recursive calls 
// initialize the dp array with -1 using memset() in main function.
int dp[102][1002];

int knapsack(int wt[], int val[], int W, int n)
{
  //Base Case->
  if(n==0 || W==0)
  {
    return 0;
  }
  
  //check dp array
  if(dp[n][W]!=-1)
  {
    return dp[n][W];
  }
  
  if(wt[n-1]<=W)
  {
    // store value before returning
    return dp[n][W] = max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));        
  }
  else
  {
    // store value before returning
    return dp[n][W] = knapsack(wt, val, W, n-1);
  }
}
            
/************** Top-Down Approach *******************/

// need to make same array as in memoization
// step1 = initialize the array
// step2 = change recursive calls to interative calls
