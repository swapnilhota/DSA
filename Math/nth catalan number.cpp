/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long binomialCoeff(long long n, long long k)
{
    long long res=1LL;
    
    if(k>n-k)
    {
        k=n-k;
    }
    
    for(long long i=0; i<k; i++)
    {
        res *= (n-i);
        res /= (i+1LL);
    }
    
    return res;
}

int main()
{
    long long n;
    cin>>n;
    
    //calculate nth catalan number
    
    long long coeff = binomialCoeff(2LL*n, n);
    long long catalan = coeff/(n+1LL);
    cout<<catalan<<endl;

    return 0;
}
