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
- given n number and need to find longest consecutive numbers where
  all number is divisible by any of these numbers .

- so find gcd for every consecutive numbers and if this gcd is already exist between
  these number then maximize with the length of these numbers.

-  I will use binary search to eliminate range but for every mid value how to to find gcd of mid numbers with at most O(n).
   I tried to much to find o(n) use sliding window but can't so I use segment tree .


*/

const int MX=3e5+6;
int n,arr[MX],interval[4*MX];
int vis[4*MX];
void build (int s, int e, int p )
{
    if (s == e )
    {
        interval[p] =  arr[s];
        return;
    }
    build(s, (s + e ) / 2, 2 * p );
    build((s + e ) / 2 + 1, e, 2 * p + 1  );
    interval[p] = __gcd(interval[2*p], interval[2*p+1] );
}
int from, to;

int query(int s = 0, int e = n, int p = 1)
{
    if (from <= s && to >= e)
        return interval[p];

    int mid = (s + e) / 2;

    if (to <= mid)
        return query(s, (s + e) / 2, 2 * p);

    if (from > mid)
        return query((s + e) / 2 + 1, e, 2 * p + 1);

    int a = query(s, (s + e) / 2, 2 * p);
    int b = query((s + e) / 2 + 1, e, 2 * p + 1);

    return __gcd(a, b );
}
bool valid (int val )
{
    mem(vis, 0 );
    rep( i, val )
    vis[arr[i]] ++ ;
    from = 0, to = val-1;
    int gcd = query(0, n, 1 );
    if (vis[gcd] )
        return 1 ;

    int l = 0, r = val ;
    while(r < n )
    {
        vis[arr[l++]] --  ;
        vis[arr[r++]] ++;

        from = l, to = r-1;
        int gcd = query(0, n, 1 );
        if (vis[gcd] )
            return 1 ;
    }
    return 0;
}

vi v ;
void print (int val )
{
    mem(vis, 0 );
    rep( i, val )
    vis[arr[i]] ++ ;
    from = 0, to = val-1;
    int gcd = query(0, n, 1 );
    if (vis[gcd] )
        v.pb(1);
    int l = 0, r = val ;
    while(r < n )
    {
        vis[arr[l++]] -- ;
        vis[arr[r++]] ++;
        from = l, to = r-1;
        int gcd = query(0, n, 1 );
        if (vis[gcd] )
            v.pb(from+1);
    }
}



int main()
{

    cin >> n ;
    rep( i, n ) cin >> arr[i];
    build(0, n, 1 );
    int  s= 0, e = n ;
    while (s < e)
    {
        int mid = s + (e - s + 1) / 2;
        if (valid(mid))
            s = mid;
        else
            e = mid - 1;
    }
    print(s);
    cout << sz(v) << " " << s-1<<endl;
    for (auto i : v )
        cout << i << " ";
}
