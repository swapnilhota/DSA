/*

credits:- Aditya Verma YouTube Channel

01 Knapsack Problem
wt[] -> weight array of items
val[] -> value array of items
W -> knapsack capacity
n -> array size

*/

int knapsack(int wt[], int val[], int W, int n)
{
  //normal recursive solution
  
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
