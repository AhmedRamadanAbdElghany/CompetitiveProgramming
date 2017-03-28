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
#define OO ((ll)1e9)
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
typedef  vector < ll > row ;
typedef vector < row > matrix ;
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
#define mod 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;

/*
the problem need to find cycle with minimum mean .
so will binary search in the mean value .
the valid function will subtract every edge with that value and if we find negative cycle then try to get value with less mean .
I used bellman ford to find if there is a cycle with negative value exist or not . 

*/




struct Edge
{
    int from, to ;
    db cost ;
    Edge(int a, int b, db c )
    {
        from = a, to = b, cost = c ;
    }
};

vector < Edge > graph ;

int n, m ;
bool BellmanPrcoessing(vector<Edge> & edgeList, vector < db > &dist)
{
    if(sz(edgeList) == 0 )	return false;

    for (int it = 0, r = 0; it < n+1; ++it, r = 0)
    {
        for (int j = 0; j < sz(edgeList) ; ++j)
        {
            Edge ne = edgeList[j];
            if(dist[ne.from] >= OO || ne.cost >= OO)	continue;
            if( dist[ne.to] > dist[ne.from] + ne.cost )
            {
                dist[ne.to] = dist[ne.from] + ne.cost;
                //prev[ ne.to ] = ne.from, pos[ ne.to ] = j,
                r++;
                if(it == n)		return true;
            }
        }
        if(!r)	break;
    }
    return false;
}
bool valid(db a )
{
    vector < db > dist(n, 0);
  //  dist[0] = 0;
    vector < Edge > edgeList ;
    for (auto i : graph )
edgeList.pb(Edge(i.from, i.to, i.cost - a ) );

    bool cycle = BellmanPrcoessing(edgeList, dist);

    if(cycle)
        return 1;
    return 0;
}






int main()
{
    int tc;
    cin >> tc;

    rep(l, tc)
    {
        graph.clear();
        int a, b ;
        db c, mx = 0 ;
        cin >> n >> m ;
        rep( i, m )
        {
            cin >> a >> b >> c  ;
            a--, b--;
            graph.pb(Edge(a, b, c ));
            mx = max(mx, c );
        }

        db s = 0, e = mx ;
        int flag = 0 ;
         cout << "Case #"<< l+1 <<": ";
         if (valid(mx + 1 ) == 0 )
            printf("No cycle found.\n");
         else {
        double l = 0, r = mx;
			for (int i = 0; i < 100; i++) {
				double mid = (s + e) / 2;
				if (!valid ( mid ) ) s = mid;
				else e = mid;
			}
  printf("%.2f\n", s);
         }
    }
}
