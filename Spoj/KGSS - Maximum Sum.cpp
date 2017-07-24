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
find maximum elemment value and index .
update index of maximum value with negative value
find maximum again 
retrieve the value of the first maximum 
*/


pair < ll, int > seg[2*131072];
ll arr[100009];
void build (int s, int e, int p )
{
    if (s == e )
    {
        seg[p].first = arr[s];
        seg[p].second = s ;
        return;
    }
    build(s, (s + e ) / 2, 2 * p );
    build((s + e ) / 2 + 1, e, 2 * p + 1  );
    seg[p].first = max (seg[2*p].first, seg[2*p+1].first );
    seg[p].second = seg[2*p+1].second ;
    if (seg[p].first == seg[2*p].first )
        seg[p].second = seg[2*p].second ;

}
int le, ri ;
pair < int, int > query(int s, int e, int  p)
{
    if ( s >= le && e <= ri  )
        return seg[p];
    int mid = (s + e ) >> 1;

    if(ri <= mid )
        return query(s,mid, 2 * p ); // whole side is in left

    else if( le > mid )
        return query(mid+1,e, 2 * p + 1 ) ; // whole side is in right

    pair <int, int > p1 = query(s,mid, 2 * p );
    pair <int, int > p2 = query(mid + 1, e, 2 * p + 1 );
    if (max(p1.first, p2.first) == p1.first )

        return {p1.first, p1.second};
    return {p2.first, p2.second};
}


void insert(int s, int e, int p, int idx,int val )
{

    if ( s == e )
    {
        seg[p].first = val;
        //cout << s << "  " << val << endl;
        return;
    }
    int mid = ( s + e )/2;
    if ( mid >= idx )
        insert(s, mid, p * 2, idx,val );
    else
        insert(mid + 1, e, 2 * p + 1, idx,val);
    seg[p].first = max (seg[2*p].first, seg[2*p+1].first );
    seg[p].second = seg[2*p+1].second ;
    if (seg[p].first == seg[2*p].first )
        seg[p].second = seg[2*p].second ;
}


int main(void)
{
        ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    cin >> n ;
    rep( i, n )
    cin >> arr[i];

    build(0, n-1, 1 );
    int tc, a, b ;
    cin >> tc ;
    char ch ;
    while(tc--)
    {
        cin >> ch >>  a >> b ;
        if (ch == 'Q')
        {
            le = a-1, ri = b-1 ;
            pair < int, int > cur = query(0, n-1, 1 );
// cout << cur.first << "  " << cur.second << endl;
            insert(0, n -1, 1, cur.second, -1 );
            pair < int, int > cur2 = query(0, n-1, 1 );
            insert(0, n -1, 1, cur.second, cur.first );
            cout << cur.first + cur2.first << endl;
        }
        else
            insert(0, n -1, 1, a -1, b );
    }
}
