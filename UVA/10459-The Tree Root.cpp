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
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
/*
we want to find best nodes to be the root and worst nodes .
so first find the diameter of the tree and if the diameter is odd then we have 2 nodes can be best root else we have one root .
from these best nodes find the furthest nodes and it will be the worst nodes.

*/


int par[6000];
int vis[6000];
vector < vi > adj;
int bfs(int s )
{
    mem(vis, -1 ) ;
    mem(par, -1 );
    vis[s] = 0 ;
    queue < pair < int, int >  > q;
    q.push({0,s});
    vis[s] = 0 ;
    pair < int, int > u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        rep( i, sz(adj[u.second]))
        {
            int child = adj[u.second][i];
            if (vis[child] == -1 )
            {
                vis[child] = u.first + 1 ;
                q.push({vis[child], child});
                par[child] = u.second;
            }
        }
    }

    return u.second;
}


int main()
{
    int n, m, a ;
    while (cin >> n )
    {
        adj.clear();
        adj.resize(n);
        rep( i, n )
        {
            cin >> m ;
            rep( j, m )
            {
                cin >> a ;
                a--;
                adj[i].pb(a);
            }
        }

        int u = bfs(0);
        int v = bfs(u);
        int diameter = vis[v];
     int root1 = -1 , root2= -1;
            int temp = diameter/2;
     while(temp -- ){
        int a = par[v] ;
        v = a ;
     }
      root1 = v ;
     if ( diameter % 2 ) {
          root2 = par[v] ;
      if (root1 > root2)
        swap(root1 , root2);
    }

    vi worsts;
    v = bfs( root1 );
    for (int i = 0; i < n ; i++)
      if (vis[i] == vis[v])
        worsts.push_back(i+1);
    if ( root2 != -1) {
      v = bfs( root2 );
      for (int i = 0; i < n; i++)
        if (vis[i] == vis[v])
          worsts.push_back(i+1);
    }
    sort(worsts.begin(), worsts.end());
    cout << "Best Roots  : " << root1+1;
    if (root2 != -1)
      cout << " " << root2+1;
    cout << "\nWorst Roots :";
    for (size_t i = 0, e = worsts.size(); i < e; i++)
      cout << " " << worsts[i];
    cout << endl;
  }
}
