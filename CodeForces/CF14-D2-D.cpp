
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
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
//#define MAX 5000000
/*
problem description :
given tree with n vertices we need to find two seperated pathes each path has distinct nodes which multiplication of 
two lengths is maximum.

solution desciption :
we need to split tree into two seperate components and find the longest path in each component 
so try to delete every edge to get two distinct components then find longest path in every component (finding tree diameter )
and maximize answer .

*/
vector <vi> adj;
vector < pair < int, int > > v ;
pair<int, int> diameter(int i, int par = -1)
{
    int diam = 0;
    int mxHeights[3] = {-1, -1, -1};	// keep 2 highest trees
    vis[i] = 1 ;
    rep(j, sz(adj[i])) if(adj[i][j] != par)
    {
        pair<int, int> p = diameter(adj[i][j], i);
        diam = max(diam, p.first);

        // Keep only the 2 maximum children
        mxHeights[0] = p.second+1;
        sort(mxHeights, mxHeights+3);
    }

    rep(i, 3) if(mxHeights[i] == -1)
        mxHeights[i] = 0;

    diam = max(diam, mxHeights[1] + mxHeights[2]);

    return make_pair(diam, mxHeights[2]);
}



int main()
{
    //auto __startTime = chrono::system_clock::now();
    int n, a, b,mx = 0 ;
    cin >> n ;
    rep( i, n-1 )
    {
        cin >> a >> b ;
        a--, b--;
        v.pb({a, b });
    }

    rep ( i, n-1 )
    {
        adj.clear();
        adj.resize(n);
        mem(vis, 0 );
        rep(j, n-1)
        {
            if ( j == i )
                continue;
            adj[v[j].first].pb(v[j].second);
            adj[v[j].second].pb(v[j].first);
        }

        int ans = 1 ;
        int cc = 0 ;
        rep(j, n )
        if (vis[j] == 0 )
            ans *= diameter(j).first ;

        mx =max(mx, ans );
    }
    cout << mx << endl;
    
    
    
    
/*
    auto __endTime = chrono::system_clock::now();
    chrono::duration<double> __diff = __endTime - __startTime;
    cerr << fixed << setprecision(10);
    cerr << "Time: " << __diff.count() << endl;
*/
    return 0;

}

