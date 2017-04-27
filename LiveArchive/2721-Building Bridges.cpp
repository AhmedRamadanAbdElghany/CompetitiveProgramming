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
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0,-1,  1, -1, 1, -1};
/*
the problem consist of some connected town and need to connect all component with minimum number of edges and if there are a tie take the minimum cost .
so lets find the all connected component and find all edges between every two component .
then using kruskal to find sum with minimum cost .
*/




int vis[101][101];
string adj[101];
int n, m ;
int par  [200001];
int rank1[200001];
int find_parent(int a  )
{
    if ( a == par[a] ) return a;
    return par [a] = find_parent(par[a]);
}
void union_(int a, int b )
{
    if ( rank1[a] > rank1[b] )
        swap(a, b );
    par[a] = b ;
    if ( rank1[a] == rank1[b] ) rank1[b]++;
}
bool union_set(int a, int b )
{
    int p1 = find_parent(a), p2 = find_parent(b);
    if (p1 != p2 )
        union_(p1, p2);
    return p1 == p2;
}




bool valid2 (int a, int b )
{
    return a >= 0 && b >= 0 && a < n && b < m ;
}

bool valid (int a, int b )
{
    return a >= 0 && b >= 0 && a < n && b < m && adj[a][b] == '#' && vis[a][b] == 0  ;
}
void dfs(int a, int b, int num )
{
    vis[a][b] = num ;
    rep(i, 8 )
    {
        int x = a + dx[i];
        int y = b + dy[i];
        if (valid (x, y ))    dfs(x, y, num );
    }
}

int main()
{
    int tc = 1 ;

    vector<pair < int,  pair < int, int > > > edges ;
    set < int > SS;
    while( cin >> n >> m )
    {
        if ( n == 0 && m == 0 ) break ;
        if (tc != 1 )
            puts("");

        mem(vis, 0 );
        int cnt = 1,a, b  ;
        rep( i, n )
        cin >> adj[i];
        rep( i, n )
        rep( j, m )
        if (vis[i][j] == 0 && adj[i][j] == '#')
            dfs( i, j, cnt++ );    // mark every connected component with color .

        edges.clear();
        edges.resize(cnt-1);


        rep(i,n)
        rep(j,m)
        if (adj[i][j] == '#')
        {
            rep( k, 4 )
            {
                int  ni = i, nj = j,nni, nnj ;
                while ( valid2(ni + dx[k], nj + dy[k] ) ) // move in a straight line from that cell .
                {
                    ni += dx[k] ;
                    nj += dy[k];
                    if ( adj[ni][nj] == '#' )
                    {
                        if( vis[i][j] != vis[ni][nj] )
                            edges.push_back({abs(i - ni) + abs(j- nj) - 1,{vis[i][j],vis[ni][nj]}});
                    }
                    rep(l, 4 )
                    if ((k%2) != (l%2)) // if you move in x axis move one step in y axis toward and backward .
                    {
                        nni = dx[l] + ni ;
                        nnj = dy[l] + nj ;

                        if (valid2(nni, nnj ))
                        {
                            if ( adj[nni][nnj] == '#')
                            {
                                if(vis[i][j] !=  vis[nni][nnj] )
                                    edges.push_back({abs(i - nni)+ abs(j - nnj) - 2, {(vis[i][j],vis[nni][nnj]}});
                            }
                        }
                    }
                }
            }
        }
        sort(all(edges));






        cout << "City "<<tc++ << endl;
        if (cnt <= 2 )
            cout << "No bridges are needed." << endl;
        else
        {
            rep(i, cnt )
            par[i] = i ;
            int ans = 0 ;
            int sum = 0 ;
            for (auto i : edges )
            {
                int from = i.second.first ;
                int to = i.second.second ;
                int cost = i.first ;
                if (union_set(from, to ) == 0 )
                    sum += cost, ans++ ;
            }


            if(ans == 0 )
                cout << "No bridges are possible." << endl;
            else
            {
                cout << ans ;
                if(ans == 1 )
                    cout << " bridge ";
                else
                    cout << " bridges ";
                cout << "of total length " << sum << endl;
            }
            rep(i, cnt )
            find_parent(i);
            SS.clear();
            REP(i, 1, cnt )
            SS.insert( par[i] );

            if (sz(SS) > 1 )
                cout << sz(SS) << " disconnected groups" << endl;



        }
    }
}
