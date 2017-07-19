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
given n photo you can move from any photo to adjacent and have time t find maximum number of photo you can watch .
as you are in the first  photo you have 2 direction go to left or go to right and from every move you can reverse direction 
and take maximum from the reverse direction . 


*/

string s ;
int a, b, n ;
vi v ;
int pre()
{
    v.pb(0);
    for (int i = n -1 ; i >= 0 ; i -- )
    {
        int u = a + 1 ;
        if (s[i] == 'w')
            u += b ;
        v.pb(v.back() + u );
    }
}

int ReverseDirecion (int val, int idx )
{
    return (upper_bound( v.begin(), v.begin()+idx, val ) - v.begin()) - 1 ;
}

int fun(int i, int t )
{

    if (t <= 0 ) return 0 ;
    if ( i == n ) return 0 ;
    int tem = t ;
    if (s[i] == 'w' ) // rotate
        tem -= b ;
    tem -= 1 ; // see

    int ret = 0 ;
    if (tem >= 0 )  // just watch
    {
        ret = 1 ;
        ret += max(fun( i + 1, tem  - a ), ReverseDirecion(tem - i*a, n-i ));    // move to next or reverse direction
    }
    return ret ;
}


int main()
{

    int  t ;
    cin >> n >> a >> b >> t >> s  ;

    pre();
    if (v.back() <= t ) // if I can take all element
    {
        cout << n << endl;
        return 0;
    }
    int mx = fun(0, t) ; // go to left from first position

    string tt = s.substr(1); // go to right from first position
    tt += s[0];
    s = tt ;
    reverse(all(s));
    v.clear();
    pre();
    mx = max(mx,fun(0, t )) ;
    cout <<  mx <<endl;



}
