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

f(n) = f(n-1) + f(n -2 ) + n -1 .
f(n-1) + f(n -2 )  is the Fibonacci.
so the sequence is : 
0 1 2 5 10 19 34 59 100 167 
you will notice that the 2th term (2) you add the same terms of Fibonacci plus 1 
so this 1 will affect to all other terms before you in the sequence  .
in the 3th term (5)  you add the fib(3)+ 1 of the 2th term + (3-1) .
so the 3th term represent as fib(3) + 1 + 2 .
in the 4th term represent as fib(4) + ( 1 + 2 ) which you add them in th 3th term + (1) you add in the 2th term +( 4 -1 ) which is (n-1)
so it will be fib(4) + (1 + 1) + (2) + 3 .
write many terms and try to get recurrence .
 
f(n) = fib(n) + fib(n-1) * 1 + fib(n -2 )*2+ fib( n - 3 ) *3 + ....+ fib(1) * (n-2). // reach to this then see web hints 
f(n-1) = fib(n-1)+fib(n -2 )*1+fib( n - 3 ) *2+fib(1) * (n-1)
f(n) - f(n-1) = fib(n) + fib(n-2) + fib(n-3) + fib(n-4 ) + .. + f(0).
sum of right is 2*fib(n) - 1.
f(n) = f(n-1) + 2*fib(n)-1 .
using substitution we will get 
f(n) =  4*fib(n) +2*fib(n-1) - (n+2) .
use matrix to get Fibonacci term as n can be 1e9 
*/





int n , m ;
matrix zero (int n, int m )
{
    return matrix (n, row (m, (ll)0 ));
}
matrix identity(int n )
{
    matrix ret = zero(n, n );
    rep( i,sz(ret) )
    ret[i][i] = (ll)1 ;
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
    ret[i][j] = (ret[i][j]%m+(a[i][k]%m  * b[k][j]%m)%m ) % m;
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

ll fibMatrix(int n ){
matrix fibMat = zero(2 , 2 );
fibMat[0][1] = fibMat[1][0] = fibMat[1][1] = 1;
matrix fibMatn = pow(fibMat , n );
return fibMatn[0][1]%m;
}


int main()
{

    int tc ;
    cin >> tc ;
    while(tc-- ){
            cin >> n >> m ;
if ( n == 0 )
    cout << 0 << endl;
else
    cout << (((ll)4*(fibMatrix(n)%m) +((ll)2*(fibMatrix(n-1)%m))-((n+2)%m) + m )%m)%m << endl;
 }
}
