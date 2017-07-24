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
we have two query 
-  find minimum between i .... j 
-  swap(a[i] , a[i+1] ) ,   swap(a[i+1] , a[i+2] ) ,...
so implement idea with no art 

*/


int  arr[100009];
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

    return min(p1, p2);
}

void build (int s, int e, int p )
{
    if (s == e )
    {
        tree[p] = arr[s];
        return ;
    }
    build( s, (s + e ) / 2, p * 2 );
    build(  (s + e ) / 2+1,e, p * 2+1 );
    tree[p] = min(tree[2*p], tree[2*p+1]);
}



void insert(int s, int e, int p, int idx,int val )
{

    if ( s == e )
    {
        tree[p] = val;
        return;
    }
    int mid = ( s + e )/2;
    if ( mid >= idx )
        insert(s, mid, p * 2, idx,val );
    else
        insert(mid + 1, e, 2 * p + 1, idx,val);
    tree[p] = min(tree[2*p], tree[2*p+1]);
}



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m ;
    cin >> n >> m;
    rep( i, n )
    cin >> arr[i];
    build(0,n-1,1);
    string s, temp ;
    rep( j, m )
    {
        cin >> s ;

        auto it = s.find('(');
        string temp = s.substr(0, it );
        s = s.substr(it + 1 );
        istringstream iss(s);
        int x, y  ;
        char ch ;
        iss >> x ;
        x--;
        if (temp =="query")
        {
            iss >> ch >> y ;
            y--;
            le = x, ri = y  ;
            cout << query(0, n - 1, 1 ) << endl;
        }
        else
        {
            iss >> ch ;
            while(iss >> y )
            {
                y--;
                iss >> ch ;
                int val1 = arr[x];
                int val2 = arr[y];
                insert(0,n-1, 1, x, val2 );
                insert(0, n -1, 1, y, val1 );
                swap(arr[x] , arr[y]);
                x = y ;
            }
        }
    }
}
