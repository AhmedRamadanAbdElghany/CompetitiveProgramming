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
const double eps = 1e-8;
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
/*
given length of piece of wood and we want to cut it into four pieces to make a rectangle that can hold as many jars as possible .
each in a shape of circle in every row that has a previous every circle must be between two adjcent circles in the previous row.
so we have only two pattern to make the previous condition .
- first row has i circles and the second has i - 1 circles and the third has i  and so on ....
- all rows has i circle as shaped in 2th test case
so we try to maximize number of circles .
we try every row with i columns and find maximum number of rows that can be .
so for 3 circle adjcent from 2 rows the higth between them will be r +sqrt(3) * r + r .
*/



int mx(int columns, int r, int length)
{
    db w = 2 * r * columns + r ;
    db l = length - (2*w) ;
    l /= 2.0;
    int mxx = 0 ;
    l -= 2 * r;
    if (l >= 0 )
    {
        l /= (sqrt(3) * r );
        l+= 1 ;
        int rows = l ;
        mxx = rows * columns ;
    }
    w = 2 * r * columns ;
    l = length - (2*w) ;
    l/=2.0;
    if ( l >= 0 )
    {
        l -= 2 * r;
        l /= (sqrt(3) * r );
        l+= 1 ;
        int rows = l ;
        return max(mxx, ((rows+1)/2 * columns + rows/2*(columns-1) ) );
    }
    return 0;
}
class JarBox
{
public :
    int numJars(int r, int l)
    {
        int mxx = 0 ;
        int i = 1 ;
        while(mx(i, r, l ) )
            mxx = max(mxx, mx( i++, r, l ));
        return mxx;
    }

};


/*
int main()
{
    int r , l , mxx = 0 ;
cin >> r >> l ;
}
*/
