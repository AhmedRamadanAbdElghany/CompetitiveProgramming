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
/*
we have 3 points only of the regular polygon.
every regular polygon is covered by circle .
so we can make a circle from the 3 vertex and from the center of the circle
rotate by (2PI/n) and find the border of the rectangle .
*/


int dcmp(db a, db b )
{
    return fabs( a - b ) <= EPS ? 0 : a < b ? -1 : 1 ;
}

bool isPointOnSegment(point a, point b, point c)
{
    double acb = length(a-b), ac = length(a-c), cb = length(b-c);

    return dcmp(acb-(ac+cb), 0) == 0;
}

bool intersectSegments(point a, point b, point c, point d, point &intersect )
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
    {

        double w =  length(a-b), q = length(c - d );
        if (w < q )
            swap(a, c ), swap(b, d );
        if(isPointOnSegment(a, b, c ) || isPointOnSegment(a, b, d ))
            return 1 ;
        return false;
    }
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;

    if ( t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;
    return true;
}

pair<double, point> findCircle(point a, point b, point c)
{
    //create median, vector, its prependicular
    point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
    point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
    point end1 = m1+pv1, end2 = m2+pv2, center;
    intersectSegments(m1, end1, m2, end2, center);
    return make_pair( length(a-center), center );
}
int main ()
{
    db n ;
    int tc = 0 ;
    while(cin >> n )
    {
        tc++;
        if ( n == 0 )
            break ;
        double x, y, e, r, q,w ;
        cin >> x >> y >> e >> r >> q >> w ;
        point a(x,y), b(e,r), c(q,w);
        pair<double, point> an = findCircle(a, b, c );
        double angle = 2*PI/ n;
        db maxX = a.X, maxY = a.Y ;
        db minX = a.X, minY = a.Y ;
        rep(k, n-1 )
        {
            point uu  = rotateA ( a, angle * (k+1), an.second );
            maxX = max(maxX, uu.X);
            maxY = max(maxY, uu.Y);
            minX = min(minX, uu.X);
            minY = min(minY, uu .Y);
        }
        cout <<"Polygon "<<tc<<": "<< fixed << setprecision(3) << (maxX - minX) * (maxY - minY) << endl;
    }
}
