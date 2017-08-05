#include <bits/stdc++.h>
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
//std::ios_base::sync_with_stdio(false); means  i will not deal with c lang that will speed
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};



/*
problem description :
given range [1,n] and some points that you can split range in it .
when you split some range in some point the answer will be the length of range .

sol :
it is clear that it is dp (nested ranges) with start and end range parameter and loop to get position to split range
and it is complexity is known (n^3). 
start and end range can be between [1 , 10000]. so we can not make array of 10000*10000 but we have only 100 points to split from 
so a and b will call with at most 100 so n will be 100 .
so we can use map to store answer .
*/





int p[200], q;
map< pair < int , int > , int > dp;
int Solve(int a, int b)
{
pair<int, int> cur ={a , b };
if (dp.count(cur)) return dp[cur];

    int r = INT_MAX;
    rep( i , q )
    {
        if(p[i] >= a && p[i] <= b)
        {
            r  = min ( r, ( b - a )
                       + Solve( a, p[i] - 1 )
                       + Solve( p[i] + 1, b ));
        }
    }

    if (r == INT_MAX ) r = 0 ;
        dp[cur] = r;
    return r;
}

int main()
{

#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc , n ;
    cin >> tc ;
    rep( t , tc ){
    dp.clear();
    cin >> n >> q ;
    rep(i, q )
    cin >> p[i];
    cout << "Case #"<<t+1<<": ";
    cout << Solve(1, n ) << endl;
}
}
