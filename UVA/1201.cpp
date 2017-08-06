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
//std::ios_base::sync_with_stdio(false); means  i will not deal with c lang that will speed
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
problem description :
given n taxi order every order must leave at time h:m from position (a,b) to position (x,y) we need minimum number of taxi to do all orders 
taxi can do another order if it's arrival time > leave time of the other order .

solution description : 
take every two orders that can be done with the same taxi 
we need minimum num of taxi to do all orders = minium num of taxi to cover all tast = minimum path coverage = N - maximum mathching .

*/


int  N;
vector< vector < int >  > adj_list;
int  prevv[600];
bool mark[600];

bool find_match(int node)
{
    if (node == -1) return true;
    for (int i = 0; i < sz(adj_list[node]); i++)
    {
        int match = adj_list[node][i];
        if (mark[match]) continue;
        mark[match] = true;
        if (find_match(prevv[match]))
        {
            prevv[match] = node;
            return true;
        }
    }
    return false;
}

int max_matching()
{
    memset(prevv, -1, sizeof(prevv));
    int matching = 0;
    for (int i = 0; i < N; i++)
    {
        memset(mark, 0, sizeof(mark));
        if (find_match(i)) matching++;
    }
    return matching;
}



int main()
{

//#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
// freopen("a.txt", "wt", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, a, b,tc, c, d, h ;
    cin >> tc ;
    vi fromx, tox, fromy,toy;
    vector < pair < int, int > > time ;
    char ch;
    while(tc--)
    {
        time.clear();
        fromx.clear();
        fromy.clear();
        tox.clear();
        toy.clear();
        adj_list.clear();
        cin >> N ;
        adj_list.resize(N);
        rep( i, N )
        {
            cin >> h >> ch >> m >> a >> b >> c >> d  ;
            fromx.pb(a);
            fromy.pb(b);
            tox.pb(c);
            toy.pb(d);
            int alltime = h * 60 + m ;
            int diff = abs(a - c ) +abs(b - d );
            time.pb({alltime, diff} );
        }
        
        rep(i, N ) // move from i to j 
        rep( j, N )
        {
            int dist = abs(tox[i] - fromx[j] ) + abs(toy[i] - fromy[j]);
        
            if (time[j].first >
                 time[i].first+
                 time[i].second+dist )
                adj_list[i].pb(j);
        }
        cout << N - max_matching() << endl;
    }
}
