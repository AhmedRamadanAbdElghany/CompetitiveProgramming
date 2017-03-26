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
the problem need to go from node 0 to node n -1 twice using edge only one with minimum cost .
two nodes can have multiple edges with same or different cost .
at the beginning every edge with flow 1 .
make cost as a distinct between edges so if an edge beween two nodes with the same cost add only capacity to the existing edge 
else create new edge .
make super sorce with edge with flow 2 .
then get min cost max flow and put in mind how to deal with multiple edges between two nodes with different cost .
*/







int n, m ;
struct Edge
{
    int to, from, cap;
    ll cost;

    Edge(int v, int cap, ll cost, int from  = 0 )
    {
        this->from = from ;
        this->to = v;
        this->cap = cap;
        this->cost = cost;
    }
};
vector < vector<Edge> > graph;

bool BellmanPrcoessing(vector<Edge> & edgeList, int n, vector < ll > &dist, vi &prev, vi &pos)
{
    if(sz(edgeList) == 0)	return false;

    for (int it = 0, r = 0; it < n+1; ++it, r = 0)
    {
        for (int j = 0; j < sz(edgeList) ; ++j)
        {
            Edge ne = edgeList[j];
            if(dist[ne.from] >= OO || ne.cost >= OO)	continue;
            if( dist[ne.to] > dist[ne.from] + ne.cost )
            {
                dist[ne.to] = dist[ne.from] + ne.cost;
                prev[ ne.to ] = ne.from, pos[ ne.to ] = ne.cap, r++ ;
                if(it == n)		return true;
            }
        }
        if(!r)	break;
    }
    return false;
}


vi buildPath(vi prev, int src)
{
    vi path;
    for (int i = src; i > -1 && sz(path) <= sz(prev); i = prev[i])
        path.push_back(i);
    reverse( all(path) );
    return path;
}


pair<  vi, pair < vector < ll >, vi > > BellmanFord(vector<Edge> & edgeList, int n, int src, int dest)	// O(NE)
{
    vector < ll >  dist(n, OO);
    vi prev(n, -1), path,pos(n) ;
    dist[src] = 0;
    bool cycle = BellmanPrcoessing(edgeList, n, dist, prev,pos);
    path = buildPath(prev, dest);
    return {pos, {dist, path}};
}


int mcmf( int src, int dest, int flow )
{
    ll minCost = 0 ;
    vector<Edge> edgeList;
    while(flow > 0 )
    {
        edgeList.clear();
        rep(i, sz(graph))
        rep(j, sz(graph[i]))
        if (graph[i][j].cap > 0 ) // if edge with positive cost
            edgeList.pb(Edge(graph[i][j].to, graph[i][j].cap, graph[i][j].cost, i) );

        pair<vi, pair < vector < ll >, vi > > p = BellmanFord(edgeList, sz(graph), src, dest);

        if(p.second.first[dest] <= -OO || p.second.first[dest] >= +OO)	return -1 ; // if no other flow

        int bottleNeck = OO ;
        rep( i, sz(p.second.second) - 1 )
        {
            int f = p.second.second[i], t = p.second.second[i+1];
            bottleNeck = min(bottleNeck, p.first[t] );
        }

        flow -= bottleNeck;
        rep( i, sz(p.second.second)-1 )
        {
            int f = p.second.second[i], t = p.second.second[i+1];
            minCost += bottleNeck * ( p.second.first[t] - p.second.first[f] );// find cost between these two nodes
        }
        int lastCost ;
        rep( i, sz(p.second.second)-1 )
        {
            int f = p.second.second[i], t = p.second.second[i+1];

            int flag = 0 ;
            rep( j, sz(graph[f]) )
            if( graph[f][j].to == t &&  graph[f][j].cost == ( p.second.first[t] - p.second.first[f] ) ) // find edge and subtract bottleNeck
            {
                graph[f][j].cap -= bottleNeck ;
                lastCost = graph[f][j].cost ;
                break;
            }

            rep( j, sz(graph[t])) // add reverse edge
            if( graph[t][j].to == f && graph[t][j].cost == ( p.second.first[f] - p.second.first[t] ) )
            {
                graph[t][j].cap += bottleNeck ;
                flag = 1 ;
                break;
            }

            if (flag == 0 )
                graph[t].pb(Edge( f, bottleNeck, -lastCost ));
        }
    }
    return  minCost;
}


int main()
{
    int a, b, c,tc =1 ;
    while(cin >> n >> m )
    {
        if ( n == 0 && m == 0 )
            break ;
        graph.clear();
        graph.resize(n+1);

        rep( i, m )
        {
            cin >> a >> b >> c ;
            a++,b++;
            bool flag = 0 ;

            rep ( i, sz(graph[a]))  // if this edge existing before with the same cost so you add capacity only not another edge .
            if (graph[a][i].to == b && graph[a][i].cost == c )
            {
                graph[a][i].cap++ ;
                flag = 1 ;
                break;
            }
            if (!flag ) // if not exist with the same cost add a new edge
                graph[a].pb( Edge(b, 1, c ));
        }
        graph[0].pb( Edge(1, 2, 0 ));   // make super source
        ll ans = mcmf(0, n, 2 );
        cout << "Instance #" << tc++ << ":  " ;
        if (ans == -1 )
            puts("Not possible");
        else
            cout << ans << endl;
    }
}
