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
given n point need find minimum enclosing circle that contain all points with minimum radius 
using welzl algorithm for detrminimg MEC using randomization .
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


bool intersectSegments(point a, point b, point c, point d,point &  intersect )
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
    point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
    point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
    point end1 = m1+pv1, end2 = m2+pv2, center;
    intersectSegments(m1, end1, m2, end2, center);
    return make_pair( length(a-center), center );
}


point pnts[100009], r[3], cen;
double rad;



void MEC(int n, int rr )
{
    if(n == 0 && rr == 2)
    {
        cen = (r[0]+r[1])/2.0;
        rad = length(r[0]-cen);
    }
    else if(rr == 3)
    {
        pair<double, point> p = findCircle(r[0], r[1], r[2]);
        cen = p.second;
        rad = p.first;
    }
    else if(n == 0)
    {
        cen = r[0];
        rad = 0;
    }
    else
    {
        MEC(n-1,rr); // find circle enclosing n - 1 points

        if(length ( pnts[n-1] - cen ) > rad)   // if that point out of the return circle of n - 1 points .
        {
            r[rr] = pnts[n-1];                //  if this put this point as a boundary to the circle .
            MEC(n-1,rr + 1);
        }
    }
}

int main()
{
    int tc ;
    scanf("%d", &tc);
    int n  ;
    db a, b ;

    while(tc--)
    {
        scanf("%d", &n);
        rep( i, n )
        {

            scanf("%lf%lf", &a, &b );
            pnts[i] = point (a, b );
        }

        random_shuffle(pnts, pnts + n );
        MEC(n,0);
        printf("%.3f\n", rad );
        printf("%.3f %.3f\n", cen.X, cen.Y );
    }
}


