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
/*
for every query find the LCA node then find the minimum and maximum values .
*/



const int MAX = 100099;
const int LOGMAX = 30;
ll maxAns, minAns ;
ll minn[MAX][LOGMAX];
ll maxx[MAX][LOGMAX];



int P[MAX][LOGMAX], parent[MAX], depth[MAX];
vector<vector<pair <int, int > > > tree;

void tree_dfs(int i, int p = -1, int d = 0)
{
    parent[i] = p, depth[i] = d;
    rep(j, sz(tree[i]))
    if (tree[i][j].first != p)
    {
        tree_dfs(tree[i][j].first, i, d + 1);
        maxx[tree[i][j].first][0] =tree[i][j].second;
        minn[tree[i][j].first][0] =tree[i][j].second;
    }
}

void preprocessing(int n) // O(nlog(n)) // P[i][j] is 2^j ancestor of i
{
    memset(parent, -1, n*sizeof(int));

    rep(i, n)
    {
        rep(j, 1 << j)
        {
            P[i][j] = -1;
            maxx[i][j] = -1e16;
            minn[i][j] =  1e16;
        }
//		P[i][0] = parent[i]; // the first ancestor of node
    }
    
    rep(i, n)
    {
        if(parent[i] == -1)
        {
            tree_dfs(i, -1,0);
        }
        P[i][0] = parent[i];
    }

    for (int j = 1; (1 << j) < n; j++)
        rep(i, n)
        if (P[i][j - 1] != -1)
        {
            P[i][j] = P[P[i][j - 1]][j - 1];
            maxx[i][j] = max ( maxx[i][j-1], maxx[P[i][j-1]][j-1]);
            minn[i][j] = min ( minn[i][j-1], minn[P[i][j-1]][j-1]);
        }
}

void LCA(int n, int p, int q) //O(log(n))
{
    if (depth[p] < depth[q])		swap(p, q);
    int log;
    for (log = 1; 1 << log <= depth[p] ; log++);
    log--;
    maxAns = -( 1e16 ), minAns = ( 1e16) ;
    for ( int i = log ; i >= 0 ; i-- ) //find ancestor of p on the same level with q
        if (depth[p] - (1 << i) >= depth[q])
        {
            minAns = min(minAns, minn[p][i]);
            maxAns = max(maxAns, maxx[p][i]);
            p = P[p][i];
        }
    if (p == q)
        return ; //one of them parent of another
    // cout << p << "  " << q << "  " << log << endl;
    for ( int i = log ; i >= 0 ; i-- ) //we compute LCA(p, q) using the values in P
        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {

            minAns = min( minAns, min(minn[q][i],minn[p][i]));
            maxAns = max( maxAns, max(maxx[q][i],maxx[p][i]));

            p = P[p][i], q = P[q][i];
        }
    minAns = min(minAns, min(minn[q][0],minn[p][0]));
    maxAns = max(maxAns, max(maxx[q][0],maxx[p][0]));
    return ;
}





int main()
{
    int n, a, b,c ;
    while(cin >> n )
    {
        tree.clear();
        tree.resize(n+2);
        rep( i, n -1 )
        {
            cin >> a>> b >> c ;
            a--;
            b--;
            tree[a].pb({b,c});
            tree[b].pb({a,c});

        }
        preprocessing(n);
        int k ;
        cin >> k ;
        rep( i, k )
        {
            cin >> a >> b ;
            a -- ;
            b-- ;
            LCA(n,a,b);

            cout << minAns << " " << maxAns << endl;
        }
    }
}
