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
// https://github.com/Otrebus/timus/blob/master/1647.cpp

bool solve(point p1, point p2, point p3, point& S, point& T)
{


    double a = length(vec(p1,p2));
    double b = length(vec(p1,p3));
    double c = length(vec(p2,p3));

    double p = a + b + c;
    double t;
    if(std::abs(p*p - 8*a*b) < 1e-9)
        t = p/(4*b);
    else
    {
        t = (p + sqrt(p*p - 8*a*b))/(4*b);
        if(t > 1)
            t = (p- sqrt(p*p - 8*a*b))/(4*b);
    }
    double s = 1/(2*t);
    if(t != t || s > 1 + 1e-9 || s < 0 - 1e-9 || t > 1 + 1e-9 || t < 0 - 1e-9)
        return false;
    S = p1 + (p2-p1)*s;
    T = p1 + (p3-p1)*t;
    return true;
}


int main()
{

point  S, T;
db x , y ;
cin >> x >> y ;
point    p1(x , y);
cin >> x >> y ;
point    p2(x , y);
cin >> x >> y ;
   point p3(x , y);

    if (solve(p1, p2, p3, S, T) || solve(p2 , p3 , p1 , S , T ) ||solve(p3 , p1 , p2 , S , T ) )
cout << "YES\n" << setprecision(20) << S.X << " " << S.Y << "\n" << T.X << " " << T.Y;
else puts("NO");
}
