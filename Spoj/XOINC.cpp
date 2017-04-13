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
typedef complex<int> point;
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
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
/*
given n numbers in a stack and the first player can take 1 or 2 number from top of the stack , the second player can take double number 
of taken number of the first one and so one every one take double number of the previous one.
so  you should try all state and take the best .
Both players have same  terminal condition , optimality playing .

the state defined by [ i >>> the index in the array , last ->> the number of element can take start from i ].
so for at every state we have two choices :
the first to try to take less items than available.
the second to take the all available items and find the score of the other player to determine the score of the current player .
as the score of the current player = sum of all bottom items - returned score of the other player .

*/

int n ;
int sum [2009];
int dp[2009][2009];
int fun(int i, int last )     // 0 , 2 ;
{

    if ( i == n || last == 0) return 0;

    int &ret = dp[i][last] ;
    if (ret != -1 ) return ret ;

    int ch1 = fun(i, last - 1 );    // try less items to take start from i .
    int ch2 = 0 ;
// score of the current player = sum of bottom i - score of the other player
    if (i + last <= n ) // valid position
        ch2 = sum[i] - fun( i + last, min( 2 * last, n - ( i + last )));   // enough interval and let's find score of the current player .

    return ret =  max(ch1, ch2) ;
}

int main()
{
    int a[2008];
    scanf("%d", &n);
    rep( i, n )
    scanf("%d", &a[i]);
    mem(dp, - 1 );
    sum[n-1] = a[n-1];
    for (int i =n-2 ;  i>= 0 ; i -- )
        sum[i] =sum[i+1]+a[i] ;
    printf("%d\n", fun(0, 2 ));
}


