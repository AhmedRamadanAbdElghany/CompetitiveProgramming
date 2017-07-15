#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<m;i++)
#define REP(i,k,m)      for(int i=k;i<m;i++)
#define repd(i,m)        for(int i=m;i>=0;i--)
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define OO ((ll)1e12)
#define ooo -100000000
#define small  INT_MIN;
#define big  INT_MAX;
using namespace std;
typedef long long ll;
typedef double db;
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<bool>       vb;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef bitset<20> MASK;
#define INF 10000
#define sz(v)          ((int)((v).size()))
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;

/*
http://codeforces.com/blog/entry/20692
some notes :
- it may be repeating of some numbers .
- repeating any number of n numbers is the same so repeate only one number .
- repeate the number in the middle of the subsequence and then find best subsequence befor and after you depend one  
  repeated element .
- you have maximum n distinct elements you can take minimum 1 element at every step 
  so you have n * n step befor you and n * n step after you . 
*/

int cnt[305];
vector<int>a, c;
int n, t;
int num1, num2;
int dp[10005][305];
int dp2[10005][305];
int solve2(int idx, int last )
{
    if(idx == num2)
        return 0;

    int &ret = dp2[idx][last];
    if(ret != -1)
        return ret;

    if(c[idx] >= last )
        ret = 1 + solve2( idx + 1, c[idx] );
    return ret = max( ret, solve2(idx + 1, last ));
}

int solve(int idx, int last )
{
    if(idx == num1)
    {
        return t * cnt[last] + solve2( 0, last );
    }
    int &ret = dp[idx][last];
    if(ret != -1)
        return ret;
    ret = 0;

    if(a[idx] >= last )
        ret = 1 + solve( idx + 1, a[idx]);
    return ret = max(ret,solve(idx + 1, last ));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mem(dp, -1 );
    mem(dp2, -1 );  // same values but may be different length .

    cin >> n >> t;
    int arr[109];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    rep( i, min(t, 100 ))
    rep( j, n )
    a.pb(arr[j]);
    num1 = min(t, 100 ) * n ;

    t-= min(t, 100 ) ;
    int  temp = min(t, 100 );
    t-=min(t, 100 );
    rep(i, temp )
    rep( j, n )
    c.pb(arr[j]);
    num2 = temp * n ;

    cout << solve( 0, 0 ) << endl;

    return 0;
}
