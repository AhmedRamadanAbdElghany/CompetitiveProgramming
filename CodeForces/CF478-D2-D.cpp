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
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
 there are r red and g green blocks and we want to buid a tower from these blocks , the first level of the tower is 1 block and 
 the second have 2 blocks, the third 3 blocks and so on , every level consist of blocks of the same color .
 we want number of ways to construct the tower .
 
 we want to find the number of levels :
 we need to find a closest number of blocks which less than or equal to ( r + g ).
 and this number will be sum from 1 to number of level but these sum must <= r+g.
 first thinking in dp to take the current level of the green blocks or red ones
 with three paramater the (current level , number of red blocks taken , number of green blocks taken )  but this will not fit
 but we can make use of knowing sum of all blocks in the levels and drop one parameter of the last two parameters .
 and have two choices take the current level of green blocks only or leave it and at last determine if the levels you leaved 
 can be colored with red blocks if (sum - green blocks used ) <= number of red blocks I have .
 and this will fit in time with O(level * number of green blocks ) level <= 600 , number of green blocks <= 1e5.
 but will not fit in memory so as levels go sequential we can using rolling technique.
*/



int r,g, h, sum ;
ll dp[2][200006];
/*
int fun(int i, int a )
{

    if (a > g ) return 0 ;


    if ( i > h )
    {
        if (sum - a <= r  )
            return 1 ;
        return 0 ;
    }

    int &ret = dp[i][a] ;
    if (ret != -1 ) return ret ;

    return ret = fun(i+1, a + i ) +
                 fun(i+1, a );

}
*/


int main()
{
    cin >> g >> r ;
    h = 1 ;
    int su = g + r ;
    // 1 + 2 + 3 + 4 + 5 + ... = ( n * ( n + 1 ) / 2 ). 
    while((h*(h+1)) / 2 <= su )   h++;
    
    h--;                          // maximum number of level 
    sum = (h*(h+1)) / 2;        // maximum number of blocks we can used 
    
    rep( i, g+1 )
    if (sum  <= r + i )       // base case 
        dp[1][i] = 1 ;
    
    int p =1 ;
    for (int i = h ; i > 0  ; i -- )
    {
        p = !p;
        for (int j = g ; j >=0 ; j -- )
        {
            dp[p][j]=0;
            if (j + i <= g ) // take the current level of green blocks 
                dp[p][j] += dp[!p][j+i];
            dp[p][j] += dp[!p][j]; // leave it 
            dp[p][j] %= pi;
        }
    }
    cout << dp[p][0] << endl;
}


