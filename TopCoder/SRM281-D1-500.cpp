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
given n holes and a ball start at (X , Y ) the ball can go diagonally with angle 45 then reflect with the same angle to the next Axis
and so on until falling in a hole .

so if we are in posistion (a,b) and want to go up so the Xdirection(dx) will be 1 .
else it will be -1 and the same for Ydirection(dy). 
so to get the next point we will move the minimum between Xsteps and Ysteps that the ball can move towered .

to check if there are no ball in the line:
every cell can exsist in two diagonals:
- X-axis and Y-axis both increase or both decrease[x-y+mx].
- X-axis increase but Y-axis decrease and vice versa [x+y].

so depend on direction check the diagonal if there are balls in that or not .
but if we are in the first move there can be ball in the same diagonla but not in the same segment so we check if there are holes
in the segment or not . 
*/




vector < point > holes;
bool diag1[2*1000005];
bool diag2[2*1000005];

bool fall(int s, int e, int a, int b, int dx, int dy, int ans   )
{

    if (ans == 0 )
    {
        rep( i, sz(holes))
        {
            int cross = (a - s)*(holes[i].Y - e )-(b - e ) * (holes[i].X - s );
            if (cross != 0 ) continue ;
//cout << holes[i] << endl;
            if (min(s, a ) <= holes[i].X && holes[i].X <= max(s, a )
                    && min(e, b ) <= holes[i].Y && holes[i].Y<= max(e, b )) return 0;

        }
        return 1;
    }
    else
    {
        if( dx== dy )
            return diag1[s- e +1000005]==0;
        else
            return diag2[s+e]==0;
    }
}


class BallBouncing
{
public:
    int bounces(int rows, int columns, int startrow, int startcol,  vector <string> hole)
    {
        int x, y ;
        rep( i, sz(hole))
        {
            istringstream iss(hole[i]);
            iss >> x >> y ;
            diag2[x + y ] = 1 ;
            diag1[x - y + 1000005] = 1 ;
            holes.pb(point(x, y ));
        }

        int dx = 1, dy = 1 ;
        int nextdx, nextdy ;
        int sx = startrow, sy = startcol, ans = 0 ;
        while(ans < 99000000 )
        {
            int mx, my ;
            if (dx > 0 )
                mx = rows - 1 - sx ;
            else
                mx = sx ;
            if (dy > 0 )
                my = columns - 1 - sy ;
            else
                my = sy ;

            nextdx = dx, nextdy = dy ;

            int mn = min(mx, my );

            if (mn == mx )
                nextdx *=-1;

            if (mn == my )
                nextdy *=-1;
            int endx, endy ;
            endx = sx + dx * mn;
            endy = sy + dy * mn;
            // cout << sx << "  " << sy << "  " << endx << "  " << endy << endl;
            if (fall(sx, sy, endx, endy, dx, dy, ans  )==0)
                return ans ;
            ans++;

            sx = endx + (dx + nextdx ) / 2 ;
            sy = endy + (dy + nextdy ) / 2 ;

            dx=nextdx;
            dy = nextdy;

        }
        return -1 ;
    }
};
/*
int main()
{

    BallBouncing hh;
    cout << hh.bounces(8,
                       11,
                       2,
                       1,
    { "1 5", "5 3", "4 4" });
}
*/
