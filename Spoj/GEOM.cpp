// WA

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


struct line
{
    db a, b, c ;
    line (point p, point q  )
    {
        a = p.Y - q.Y ;
        b = q.X - p.X ;
        c = -a*p.X - b * p.Y ;
    }
};

//const double EPS = 1e-9;

double det (double a, double b, double c, double d)
{
    return a * d - b * c;
}

bool intersect (line m, line n, point & res)
{
    double zn = det (m.a, m.b, n.a, n.b);
    if (abs (zn) < EPS)
        return false;

    db fff = - det (m.c, m.b, n.c, n.b) / zn;
    db hh  = - det (m.a, m.c, n.a, n.c) / zn;
    res =point(fff, hh );
    return true;
}

bool parallel (line m, line n)
{
    return abs (det (m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent (line m, line n)
{
    return abs (det (m.a, m.b, n.a, n.b)) < EPS
           && abs (det (m.a, m.c, n.a, n.c)) < EPS
           && abs (det (m.b, m.c, n.b, n.c)) < EPS;
}

point getSpPoint(point A,point B,point C) // find point of perpend
{
    db x1=A.X, y1=A.Y, x2=B.X, y2=B.Y, x3=C.X, y3=C.Y;
    db px = x2-x1, py = y2-y1, dAB = px*px + py*py;
    db u = ((x3 - x1) * px + (y3 - y1) * py) / dAB;
    db x = x1 + u * px;
    db y = y1 + u * py;
    return {point(x, y)}; //this is D
}



int main()
{
    db a, b, c, x, y ;
    cin >> a >> b >> c >> x >> y ;
    point A(a + c / 2.0, b + c / 2.0);
    point B(a + c / 2.0, b - c / 2.0);
    point C(a - c / 2.0, b - c / 2.0);
    point D(a - c / 2.0, b + c / 2.0);
    point p(x, y);
    point F1 = getSpPoint(B, p, A );
    point F2 = getSpPoint(C, p, B );
    point F3 = getSpPoint(D, p, C );
    point F4 = getSpPoint(A, p, D );


    point f, f1, f2;
    line pp (A, F1);
    line qq (B, F2 );
    line qqq(C, F3);
    line qqqq(D, F4 );
    if (intersect(pp, qq,f  ) && intersect(pp, qqq,f1 ) && intersect(pp, qqqq,f2  ))
    {

        if  (fabs(f1.X - f2.X ) <= EPS && fabs(f1.Y - f2.Y ) <= EPS  &&
                fabs(f1.X - f.X ) <= EPS && fabs(f1.Y - f.Y ) <= EPS

            )cout << "YES" << endl <<fixed<<setprecision(1)<< f1.X << " " << fixed<<setprecision(1)<<f1.Y << endl;
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;


}















