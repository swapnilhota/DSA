#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define vi vector<int>
#define si set<int>
#define pb push_back
//#define mp make_pair
#define F first
#define S second
#define nline '\n'
#define mod 1000000007

#define fr(n)           for(__typeof(n) i=0; i<n; i++)
#define rep(i, a, b)    for(__typeof(b) i=a; i<b; i++)
#define repi(i, a, b)   for(__typeof(b) i=a; i>=b; i--)

#define deb(x)			cout<<#x<<" -> "<<x<<nline;
#define println(x)		cout<<x<<nline;
#define print(x)		cout<<x;

#define time_passed     1.0*clock()/CLOCKS_PER_SEC

string multiply(string a, string b)
{
    if(a.length() < b.length())
    {
        return multiply(b, a);
    }

    vector<int> prod(a.length()+b.length(), 0);
    int prod_carry=0;

    int idx;

    for(int i=b.length()-1; i>=0; i--)
    {
        int carry=0;
        idx = b.length()-i-1;
        for(int j=a.length()-1; j>=0; j--)
        {
            int x = b[i]-'0';
            int y = a[j]-'0';
            int z = x*y+carry;
            carry = z/10;
            z = z%10;
            int temp = prod[idx]+z+prod_carry;
            prod_carry = temp/10;
            temp = temp%10;
            prod[idx] = temp;
            idx++;
        }
        if(carry!=0)
        {
            int temp = prod[idx]+carry+prod_carry;
            prod_carry = temp/10;
            temp = temp%10;
            prod[idx]=temp;
            idx++;
        }
    }

    while(prod_carry!=0)
    {
        int temp = prod[idx]+prod_carry;
        prod_carry = temp/10;
        temp = temp%10;
        prod[idx]=temp;
        idx++;
    }

    reverse(prod.begin(), prod.end());

    string res="";

    int flag=0;

    for(auto i: prod)
    {
        if(flag)
        {
            res += to_string(i);
        }
        else if(i!=0)
        {
            res+=to_string(i);
            flag=1;
        }
    }

    return res;
}

string powerof2(int n)
{
    if(n==0)
    {
        return "1";
    }

    string res = "1";

    for(int i=0; i<n; i++)
    {
        res = multiply(res, "2");
    }

    return res;
}

void solve(int cnt) 
{ 
    string res = powerof2(1000);

    cout<<res<<nline;
}

int32_t main() 
{
    #ifndef swapnilhota
   	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test=1;    
    //cin>>test;
    int cnt=0;
    while(test--)
    {
        cnt++;
        solve(cnt);
    }
    cerr<<endl<<"Time elapsed: "<<time_passed<<endl;
    return 0;
}
