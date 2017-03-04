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
The problem need to find if there is cycle that cover all edges in an undirected graph .
so the Required is : to find if there is an Euler cycle or not .
Euler cycle Exist if every node has even degree and the graph is 1 connect component . 
*/
int adjMax[209][209];
int n, m ;
int vis[209];
int degree[209];
void dfs(int node )
{
    if (vis[node]) return ;
    vis[node] = 1 ;
    rep( i, n )
    if (adjMax[node][i])
        dfs(i);
}
int main ()
{
    int  a,b ;
    while(cin >> n >> m )
    {
        mem(vis, 0 );
        mem(adjMax, 0 );
        mem(degree, 0 );
        rep( i, m )
        {
            cin >> a >> b ;
            adjMax[a][b] =adjMax[b][a]= 1 ;
            degree[a]++,degree[b]++;
        }
        int fl = 0 ;
        rep( i, n )
        if( degree[i] & 1 )
            fl = 1  ;

        if (fl )
        {
            puts("Not Possible");
            continue;
        }
        rep( i, n )
        if (degree[i])
        {
            dfs(i);
            break;
        }
        rep( i, n )
        if (degree[i] && vis[i] == 0 )
            fl=1;
        if (fl == 0 && m )
            puts("Possible");
        else
            puts("Not Possible");
    }

}
