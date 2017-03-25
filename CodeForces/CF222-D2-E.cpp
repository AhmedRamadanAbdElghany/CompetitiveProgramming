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

the problem need to count number of strings of length n with no specific characters to be adjacent .
so we need sum every string of length n start with any char and end with any char 
but no two characters of the given strings are adjcent .  
I can solve it if n is 1e5 with dp O( n * m * m )  but n is 1e15 .
 
 
so we can think of every char is a node so if two nodes can be adjacent then there is a path between them (adj[i][j] = 1 ).
so  power matrix to n will give me number of paths with length n start from i to j .
so the number of strings will be sum of these paths .

*/



ll n;
int  m, k ;
int get(char ch )
{
    if (ch >= 'a' && ch <= 'z' )
        return ch - 'a'  ;
    return ch -'A' + 26 ;
}
matrix zero (int n, int m )
{
    return matrix (n, row (m, 0 ));
}
matrix identity(int n )
{
    matrix ret = zero(n, n );
    rep( i,sz(ret) )
    ret[i][i] = 1 ;
    return ret ;
}
ll matrixSum(matrix a )
{
    ll ret = 0 ;
    rep( i, sz(a))
    rep( j , sz(a[i]))
    ret += a[i][j];
    ret %= mod ;
    return ret ;
}
matrix multiply (const matrix &a, const matrix &b )
{
  matrix ret= zero(a.size(), b[0].size());
    rep( i, sz(a) ) rep ( k, sz(a[0]))
    {
        if ( a[i][k] != 0 )
        {
            rep( j,sz( b[0]))
            ret[i][j] = (ret[i][j]+a[i][k]  * b[k][j] )%mod;
        }
    }
    return ret ;
}
matrix pow (const matrix &a, ll k )    
{
    if ( k == 0 )
        return identity(a.size());
    if ( k % 2 == 1 )
        return multiply( a , pow ( a , k - 1 ));

    return pow (multiply(a, a ), k / 2 );
}
int main()
{
    char s[100000] ;
    scanf("%I64d" ,&n);
    scanf("%d%d" ,&m , &k);
    matrix adj(m , row (m , 1 ));
    matrix mul(m , row (m , 0 ));
   
   rep( i, k )
    {
        scanf("%s" ,&s);
        rep( j, strlen(s)-1)
        adj[get(s[j])][get(s[j+1])] = 0 ;
    }

matrix ans = pow(adj, n-1);
cout << matrixSum(ans) << endl ;

}
