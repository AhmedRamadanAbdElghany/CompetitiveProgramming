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
given n cells with white color and two player take turns to choose 1 white cell and color it to {red , blue } the game end with no white cell .
the first player need to maximize score and the second one need to minimize it and the score is the distance
between every two cells with different colors.

sol description :
as two player have different target the first need to max and second need mini so it is minimax problem .
as n is <= 12 we have two masks to every palyers but we will not call all value of every maske we need half values of every mask 
so we use map as array will not fit in memory 
*/



int n  ;
vi x,y ;
db dist(int a, int b )
{
    int ret = (abs(x[a] - x[b]) * abs(x[a] - x[b]) + abs(y[a] - y[b]) * abs(y[a] - y[b]));
    return sqrt(ret);
}
map < pair < int, int >, db > dp ;

db fun(int mask, int mask2,  int turn )
{
    if ( (mask | mask2 ) == (1 << n) - 1 )
        return 0 ;
    if (dp.count({mask, mask2}))
        return dp[ {mask,mask2}] ;

    db ret;
    if (turn == 0 )  // max
    {
        ret = 0 ;
        rep( i, n )
        {
            if ( (1<<i) & mask ||(1<<i) & mask2 )
                continue ;

            db sum = 0 ;
            for (int k = 0 ; k < n ; k++)
                if (mask2 & (1 << k ))
                    sum += dist(i, k );
            ret = max(ret, fun(mask | (1<< i ), mask2, 1 ) + sum ) ;
        }
    }

    else
    {
        ret = 100000000 ;
        rep( i, n )
        {
            if ( (1<<i) & mask ||(1<<i) & mask2 )
                continue ;

            db sum = 0 ;
            for (int k = 0 ; k < n ; k++)
                if (mask & (1 << k ))
                    sum += dist(i, k );

            ret = min(ret,  fun(mask, mask2 | ( 1<< i ), 0 )+ sum ) ;
        }
    }
    return dp[ {mask, mask2}] = ret  ;
}
class PointsGame
{
public:
    double gameValue(vector <int> pointsX, vector <int> pointsY)
    {
        x= pointsX, y = pointsY;
        n = sz(x);
        db mx = 0 ;
        rep( i, n )
        mx = max(mx, fun(1 << i, 0, 1 ));
        //cout << mx << endl;
        return mx ;
    }

};

/*
int main()
{

//#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    PointsGame pp ;
    cout << pp.gameValue({0,0,1,1},
    {0,5,0,5});

}
*/
