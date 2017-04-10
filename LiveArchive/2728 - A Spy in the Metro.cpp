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
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;



/*

the problem has n station and you m1 train start from first to last station and m2 trains from last to first station .
and you have t minute to be in the last station and first you are in the first station and you must as much time as possible in the trains 
so you need to find mimimum wait time in the stations .

you must try everything( brute force ) at every station you have 3 choises go to left from train comes from last station or 
go to right from trains comes from first station or wait .
so do these three choises at every state as long as you have time to waste .
you can make memoization for evey state .  

*/



int accumL[1000];
int reach[1000];
int first[1000];
int last [10000];
int dp[2555][555];
int n, t, m1, m2 ;

int fun(int i, int time )
{
    //cout << i << "  "<<time << endl;
    if (time > t )
        return int(1e9);
    int& ret=dp[i][time];
    if (ret!=-1)
        return ret;
    if ( time == t )
    {
        if (i == n -1) return 0 ;
        return int(1e9);
    }


    ret =  fun(i, time + 1 ) + 1 ;  // wait a minute
    if (i!= n-1&& binary_search(first, first + m1, time - accumL[i]) )   // if there are a train  from left to right .
        ret = min(ret, fun(i+1, time + reach[i]));

    if (i!= 0  && binary_search(last, last + m2, time - (accumL[n-1]-accumL[i]) ))   // if there are a train  from  right to left .
      ret = min( ret , fun(i-1, time + reach[i-1]));
    return ret ;
}

int main()
{
    int tc = 1 ;
    while(cin >> n && n )
    {

        cin >> t ;
        mem(dp, -1);
        rep( i, n - 1 )
        cin >> reach[i] ;

        REP( i,1, n )
        accumL[i] = accumL[i-1] + reach[i-1];
        cin >> m1 ;
        rep( i, m1)
        cin >> first[i];
        cin >> m2 ;
        rep( i, m2)
        cin >> last[i];

        cout << "Case Number "<<tc++<<": ";
        if (first[0] + accumL[n-1] > t )   // if I can't reach from the first train without wasting time .
            cout << " impossible" << endl;
        else
            cout << fun(0, 0) << endl;

    }
}


