#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
//#define MAX 5000000


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
#define cross(a,b)  ((conj(a) * (b)).imag())
// Reflect around p0
int x[8] = {-1,1,-2,2,-2,2,-1,1};
int y[8] = {-2,-2,-1,-1,1,1,2,2};
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
/*
we have convex polygon of n points we want to move every vertex at most distance d that make polygon still convex .
in the convex polygon the angle between two consecutive segments is > 180 anticlockwise .
so the pattern for any point movement will be TTTTTTTFFF so we need the last true .
so we can do binary search and find the last true .
but how about first false it is the minimum distance make the polygon concave .
so if we have three consecutive points in convex polygon and move the middle point indoor and move the other outdoor
with some distance it may convert to concave polygon so find first value that make the polygon concave and it will be so close to answer .
so the first value to make polygon concave is the mid distance between the middle point and the segment between two other's points .

*/
double pointLineDist(const point& a, const point& b, const point& p) {
  return fabs( cross(vec(a, b), vec(a, p)) / length(vec(a, b)));
}
int main()
{
db ret = 100000000000;
  point p[1009];
int n  ,a , b ;
   cin >> n ;
	rep( i , n ){
	cin >> a >> b;
	p[i] = point (a , b );
	}

for (int i = 0; i < n; ++i) {
    int next = (i + 1) % n, last = (i - 1 + n) % n;
    ret = min(ret, pointLineDist(p[next], p[last], p[i]) / 2.0);
  }
  cout << fixed << setprecision(10) << ret-(1e-50) << endl;
    return 0;
}
