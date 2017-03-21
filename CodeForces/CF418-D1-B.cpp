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
#define OO ((ll)1e7)
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
const double EPS = 1e-9;
typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
#define mod 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;

/*

a boy has some some problems to solve and some friends who can help him in solving them.
every friend can solve specific problems and get k coins and need some monitor .
and every monitor cost b coins so the boy need to mimize the money he will pay .


so we use knapsack to minimize answer with mask parameter that will contain solved problems.
with O (n * 2 ^ m ) time m <= 20 with memory  (n * 2 ^ m ) long long variables .
os it is so big and can not fit so we will use Rolling table technique 
as n is sequential to get rid of n in the memory . 

*/








vector <pair <  pair < int, int >, int > > arr;
int n, m, b, x,y, z ;
ll dp [(1<<20)];
/*

ll fun(int i, int mask )
{
    if (mask == (1 << m)-1)
        return 0;       // start to compute

    if (i == n )
        return ll(1e15);
ll &ret = dp[i][mask];
if (ret != -1 ) return ret ;
// leave
    ll ch = fun( i + 1, mask );
    int temp = mask | arr[i].second;
    ll ch2 = ll(1e15) ;

    if (temp != mask )
    {
        ll re = 0 ;
        if (temp == (1 << m) - 1 )
            re = (ll)b * arr[i].first.first;

        ch2 = fun( i + 1, temp ) + arr[i].first.second + re ;
    }
    return ret = min(ch, ch2 );
}

*/
const ll inf = (ll)5*1e18;
int main()
{
    scanf("%d%d%d", &n, &m, &b );
    arr.resize(n);
    rep( i, n )
    {
        scanf("%d%d%d", &x, &y, &z );
        arr[i].first.second  = x ;
        arr[i].first.first   = y ;
        int mask = 0 ;
        rep( i, z )
        {
            scanf("%d", &x);
            x--;
            mask |=(1 << x);
        }
        // cout << mask << endl;
        arr[i].second = mask ;
    }
    
    sort(all(arr));
    ll ans = inf;
    for (int i = 0 ; i < (1<<m) ; i ++ )
        dp[i]=inf ;
    dp[0] = 0; // start
    for (int i = 0 ; i < n ; i ++ )
        for (int mask = 0 ; mask < ( 1<< m )  ; mask ++ )
        {
            int temp = mask | arr[i].second ;
            if ( temp != mask ) // if the these problem solved before ignore it .
            {
                ll re = 0 ;
                if ( temp == (1 << m) - 1 )
                    re = (ll)b * arr[i].first.first;

                dp[temp]  =  min(dp[temp],  dp[mask] + arr[i].first.second + re) ;
            }
        }
    if ( dp[(1<<m)-1] >= inf )
        puts("-1");
    else printf("%I64d\n", dp[(1<<m)-1] );
}
