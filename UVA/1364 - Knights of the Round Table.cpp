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

the problem is tricky in understanding the needs and determine canceled nodes
you need to trace many EX to understand need  .


problem description :
- we have n node and m edges each edge describe two node hates each other.
- we need to delete people which if they sit in table the meeting is canceled .
- meeting canceled if the number of nodes sit in the table is even or if some node hate it's adjacent .


Concerns :
- we need to delete some node that if they set in the table the meeting is canceled .
- It is not necessary that all people sit down .
- the nodes in the same cycle can sit only in the table to make nodes adjacent .
- as we need to delete some node use BCC as if I delete some node it can be SCC
  and have some nodes which each node like adjacent nodes .
- some node can sit in the table and other may work outside .


solution description :
- so we build complement graph which nodes of each edge like each other .
- I think in articulation point and BinaryConnectedComponents as we need to delete some node and the remainder can sit together .
- so find each BICC which contain all node that can sit together in the table
- and for each BICC if you find cycle of odd nodes then these nodes can sit together ( cycle of odd nodes can be found using Bibartite )
  and number of other nodes in the same BICC can be odd and they can be sit together
  and may be even then they can sit together with nodes of odd cycle (as sum will be odd ).

- if there is no cycle of odd nodes then then all nodes in the cycle must set together and the number is even so the meeting canceled 
  so delete all nodes in BICC but if some nodes valid in other BICC so don't delete it . 

*/




int n,m,dfn[1002],low[1001],idx,idxBicc[1001],color[1001];
bool arr[1001][1001];
vector<vector<int> >graph,Bic;
stack<pair<int,int> > s;
pair<int,int> edge ;
void bcc(int node,int par )
{
    dfn[node]=low[node]=idx++;
    int ch;
    for(int i=0; i<graph[node].size(); i++)
    {
        ch=graph[node][i];
        if(dfn[node]>dfn[ch])
            s.push(make_pair(node,ch));
        if(dfn[ch]==-1)
        {
            bcc(ch, node );
            low[node]=min(low[node],low[ch]);
            if(dfn[node]<=low[ch])
            {
                Bic.push_back(vector<int>());
                do
                {
                    edge=s.top();
                    s.pop();
                    Bic[Bic.size()-1].pb(edge.second);
                }
                while(edge != make_pair(node,ch));
            }
        }

        else if(ch != par) low[node] = min( low[node] , dfn[ch] );
    }
}

bool findBibartiteSubset(int node)
{
    int ret = 1;
    rep( i, sz(graph[node]))
    {
        if(idxBicc[node] != idxBicc[graph[node][i]]) // two not in the same BICC
            continue;
        if( color[graph[node][i]] == -1 )
        {
            color[graph[node][i]] =! color[node];
            ret =(ret && findBibartiteSubset(graph[node][i]));
        }
        else if(color[node]==color[graph[node][i]])
            return 0;
    }
    return ret ;
}
int main()
{
    int ans,vis[1001], a, b ;
    while(scanf("%d%d", &n, &m ) )
    {
        if ( n == 0 && m == 0 ) break ;

        ans = 0 ;
        memset(arr,0,sizeof arr);
        memset(vis,0,sizeof vis);
        memset(dfn,-1,sizeof dfn);
        graph.clear();
        graph.resize(n);
        Bic.clear();
        rep( i, m )
        {
            scanf("%d%d",&a, &b );
            a--, b--;
            arr[a][b]=arr[b][a] = 1;
        }
        rep( i, n )
        rep( j, n )
        if( i != j && arr[i][j] == 0 )
            graph[i].pb(j);

        idx = 1;
        bcc( 0, -1 );

        rep( i, Bic.size())
        {
            memset(color,-1,sizeof color);
            memset(idxBicc,-1,sizeof idxBicc);
            rep( j, sz(Bic[i]))
           //cout << Bic[i][j] << "  ",
            idxBicc[Bic[i][j]] = i ; // each node in which Bicc
            color[Bic[i][0]]=0;
//cout << endl;
            int ret = findBibartiteSubset(Bic[i][0]);
  //          cout << ret << endl;
            if( ret == 0)// even
                rep( j, sz(Bic[i]))
                vis[Bic[i][j]]=1;

        }
        rep(i, n)
        if(vis[i]) ans++;
        printf("%d\n",n-ans);

    }
}
