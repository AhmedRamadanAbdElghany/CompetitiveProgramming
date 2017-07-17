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


class TheTower
 {
 public :
    vector <int> count(vector <int> x, vector <int> y){
    int n = sz(x) ;
    vi res(n , 1000000000 );
    rep( i, n )
    rep(j , n ) // x inter
    rep(o , n  ) // y inter
    {
        vi vv ;
        rep( l, n )
        vv.pb(abs(x[j] - x[l]) + abs(y[o] - y[l]));
        sort(all(vv));
        int sum = 0 ;
        rep(l , i + 1 )
        sum += vv[l];
        res[i] = min(res[i], sum );
    }
    return res ;
    }
 };


int main()
{
    ///  freopen("a.txt", "rt", stdin);
    ///  freopen("b.txt", "wt", stdout);

    return 0;
}
