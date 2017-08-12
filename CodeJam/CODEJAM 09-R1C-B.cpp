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
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
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
const double EPS = 1e-9;

/*
given n points in 3d move with constant speed and we are in the origin and need the minimum distance between origin and center of n points 
center of n points is :
xc = x1+x2+.../n
yc = y1+y2+.../n
zc = z1+z2+.../n
so as function in t (time)is [decreasing - increasing] I use ternary search .
in the dist function new center will be :
xc =x1+ vx1*t + x2+vx2*t +.../n .
yc =y1+ vy1*t + y2+vy2*t +.../n .
zc =z1+ vz1*t + z2+vz2*t +.../n .
so 
xc = (x1+x2+x3+t(vx1+vx2+vx3))/n.
and same for yc and zc .
then calculate distance .



*/

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

const double eps = 1e-10;
double xx, yy, zz;
int vx, vy, vz;

double dist(double t)
{
	return sqrt((xx + vx * t)*(xx + vx * t) + (yy + vy * t)*(yy + vy * t) + (zz + vz * t)*(zz + vz * t));
}

int main()
{
  freopen("a.txt", "rt", stdin);
  freopen("b.txt", "wt", stdout);	int t;
	cin >> t;
	cout.precision(12);
	for (int T = 1; T <= t; ++T)
	{
		int n;
		cin >> n;
		int x = 0, y = 0, z = 0;
		vx = 0, vy = 0, vz = 0;
		for (int i = 0; i < n; ++i)
		{
			int xx, yy, zz, vxx, vyy, vzz;
			cin >> xx >> yy >> zz >> vxx >> vyy >> vzz;
			vx += vxx;
			vy += vyy;
			vz += vzz;
			x += xx;
			y += yy;
			z += zz;
		}
		cout << "Case #" << T << ": ";
		xx = (db)x/n;
		yy = (db)y/n;
		zz = (db)z/n;
		if (vx == 0 && vy == 0 && vz == 0)
		{
			cout << dist(0) << " " << 0 << endl;
			continue;
		}
		double l = 0;
		double r = 1e10;

		while (r - l > eps)
		{

         db mid1 = l + (r - l) / 3,
         mid2 = l + 2 * (r - l) / 3;


			double d1 = dist(mid1);
			double d2 = dist(mid2);
			if (d1 < d2)
				r = mid2;
			else
				l = mid1;
		}
		cout << dist(l) << " " << l*n << endl;
	}
	return 0;
}
