#include <bits/stdc++.h>
#include<string>
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

typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
//#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
#define EPS 1e-8
#define MAX_VAL 500001
typedef vector < ll > row;
typedef vector < row > matrix;

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
every group must trust each other so if some nodes in cycle there will be in the same group 
so find SCC to get all nodes in the same cycle which will be a group . 
*/

int n ;
vector< vector<int> > adj;
vector<int> inStack, lowLink, dfn;
int ndfn ;
int ans ;
stack<int> stk;

void tarjan(int node) {

	lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
	stk.push(node);

	rep(i, sz(adj[node])) {
		int ch = adj[node][i];
		if (dfn[ch] == -1) {
			tarjan(ch);
			lowLink[node] = min(lowLink[node], lowLink[ch]);
		}
		else if (inStack[ch])
			lowLink[node] = min(lowLink[node], dfn[ch]);
	}

	if (lowLink[node] == dfn[node])
        {
            ans++;
            int x = -1;
            while (x != node )
			x = stk.top(), stk.pop(), inStack[x] = 0;
        }
}

void scc() {
	inStack.clear();	inStack.resize(n);
	lowLink.clear();	lowLink.resize(n);
	dfn.clear();		dfn.resize(n, -1);
	ndfn = 0;

	rep(i, n)
	if (dfn[i] == -1)
	tarjan(i);
}


int main()
{
map < string , int > M ;
int  m ;
string s  , s2 ;
while(cin >> n >> m ){
        if (!n)
        break;
getchar();
M.clear();
rep( i , n ){
getline(cin , s );
M[s] = i ;
}
adj.clear();
adj.resize(n);
rep( i , m )
{
    getline(cin , s );
    getline(cin , s2 );
adj[M[s]].pb(M[s2]);
}
ans = 0 ;
scc();
cout << ans << endl;
}
	return 0;
}
