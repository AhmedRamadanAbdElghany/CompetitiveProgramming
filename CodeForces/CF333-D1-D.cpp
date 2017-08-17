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
#define EPS 1e-8

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
problem :
given grid of n*m you can remove the first column or row or last column or row to get maximum of corners .

solution :
let us sort all numbers in the grid then for every cell mark it as visited then this cell is the answer if we can make rectangle 
from visited cells from that point .
at wost case we will make rectangle after max(n + 1 , m+1) .

*/

bool vis[1001][1001];
vector < pair < int , int > > vv;
bool canmove ( int a , int b ){
for (auto i : vv )
    if (vis[i.first][b] && vis[a][i.second])return 1;
return 0;
}

int main()
{
#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
int n , m , a;
cin >> n >> m ;
vector < pair < int , pair < int , int > >  > v ;

rep( i , n )
rep( j , m ){
cin >> a;
v.pb({a , {i , j }});
}
sort(allr(v));
for (auto i : v ){

if (canmove(i.second.first , i.second.second ))
    {
        cout << i.first << endl;
        break ;
    }
    vv.pb({i.second.first , i.second.second});
    //cout << i.second.first << "  " << i.second.second<< endl;
    vis[i.second.first][i.second.second] = 1 ;

}}


