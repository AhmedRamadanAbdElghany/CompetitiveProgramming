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
int dx[] = {1, 0,-1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0,-1,  1, -1, 1, -1};
/*

we have 2d grid of two types of cell [block'#' , monster'^' ] and I can fill any row or column with blocks ('#').
we want to choose one monester from all monester that can't go to out of the grid and minimize the number of barrier of blocks  .
we know that any monster at most has 4 barrier .
so if we try from every monster cell and try all masks of 4 barrier and minimize answer .

*/


vector < string > v ;
vector  <string > u;
int val[100][100];
bool valid (int a, int b )
{
    return a >=0 && a < sz(v) && b >= 0 && b < sz(v[0]) && u[a][b] != '#' && val[a][b] == 0 ;
}
bool boarder (int a, int b )
{
    return a == 0 || b == 0 || a == sz(v)-1 || b == sz(v[0]) -1 ;
}

int dfs(int a, int b  )
{
    val[a][b] = 1 ;
    if (boarder(a, b)) return 1 ;

    rep( i, 4 )
    {
        int na = a + dx[i];
        int nb = b + dy[i];
        if (valid (na, nb ) )
        {
            int ret =  dfs(na, nb );
            if (ret != -1 ) return ret ;
        }
    }
    return -1 ;
}

void  buildWall(int a, int b, int k )
{
    if ( k% 2 == 0 )
        rep (l, sz(v[0]))
        u[a][l] = '#';
    else
        rep (l, sz(v))
        u[l][b] = '#';

}

class CageTheMonster
{
public :

    int capture(vector <string> data)
    {
        v = data ;
        int mn = 1000000 ;
        rep(i, sz(v) )
        rep( j, sz(v[0]))
        if (v[i][j] == '^' && !boarder(i, j ) )
            rep ( mask, 1 << 4 )
        {
            u = v ;
            int cnt = 0 ;
            rep ( k, 4)
            if ( (1 << k )& mask )
            {
                int na = i + dx[k], nb = j + dy[k];
                buildWall(na, nb, k );
                cnt ++;
            }
            mem(val, 0 );
            if (dfs(i, j ) == -1 )
                mn = min (mn, cnt );
        }
        if (mn > 4 )
            mn = -1;
        return mn ;
    }
};
/*
int main()
{
int y ;
}
*/


