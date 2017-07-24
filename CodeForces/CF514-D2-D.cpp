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
#include <iostream>
#include <cstring>
/*
binary search to get maximum length 
valid function as m is <= 5 .
build tree in each column .
find maximum value between i and mid and store it in cnt[i][j]
if (sum of all columns of i position <= k ) then this is valid position 

*/
int arr[100009][6];
int  tree[2*131072];
int le, ri;
int query(int s, int e, int  p)
{
    if ( s >= le && e <= ri  )
        return tree[p];
    int mid = (s + e ) >> 1;

    if(ri <= mid )
        return query(s,mid, 2 * p ); 

    else if( le > mid )
        return query(mid+1,e, 2 * p + 1 ) ; 

    int  p1 = query(s,mid, 2 * p );
    int  p2 = query(mid + 1, e, 2 * p + 1 );

    return max(p1, p2);
}

int cnt[100009][6];
void build (int s, int e, int p, int col )
{
    if (s == e )
    {
        tree[p] = arr[s][col];
        return ;
    }
    build( s, (s + e ) / 2, p * 2, col );
    build(  (s + e ) / 2+1,e, p * 2+1, col );
    tree[p] = max(tree[2*p], tree[2*p+1]);
}
int n, m, k ;

bool valid (int val )
{
    if (val == 0 ) return 0 ;
    mem(cnt, 0 );
    rep( j, m )
    {
        build(0, n - 1, 1, j );
        for ( int i = 0 ; int(i + val - 1) < n ; i++ )
        {
            le = i, ri = i + val -1;
            cnt[i][j]= query(0, n - 1, 1 );
        }
    }

    for ( int i = 0 ; i + val - 1 < n ; i++ )
    {
        int sum = 0 ;
        rep( j, m )
        sum += cnt[i][j];
        if (sum <= k )
            return 1 ;
    }
    return 0 ;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k ;
    rep( i, n )
    rep( j, m )
    cin >> arr[i][j];

    int s = 0, e = n ;

    while (s < e)
    {
        int mid = s + (e - s + 1) / 2;
        if (valid(mid))
            s = mid;
        else
            e = mid - 1;
    }
    valid(s);
    if(s)
    for ( int i = 0 ; i + s - 1 < n ; i++ )
    {
        int sum = 0 ;
        rep( j, m )
        sum += cnt[i][j];
        if (sum <= k )
        {
            rep( j, m )
            cout << cnt[i][j] << " ";
            return 0 ;
        }
    }
    rep(i, m )
    cout << 0 <<" " ;
}
