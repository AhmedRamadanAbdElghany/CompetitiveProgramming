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
as there are at most 1000 in the top so there will be at most n^2
*/


int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

int dcmp(db a, db b )
{
    return fabs( a - b ) <= EPS ? 0 : a < b ? -1 : 1 ;
}

bool isPointOnSegment(point a, point b, point c)
{
    double acb = length(a-b), ac = length(a-c), cb = length(b-c);

    return dcmp(acb-(ac+cb), 0) == 0;
}


bool intersectSegments(point a, point b, point c, point d)
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

    if ( t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;
    return true;
}


pair < point , point >  p[100009];
int main()
{

//#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

vi ans ;
    int n, i, j, sum;
    while (cin >> n && n)
    {
        db a , b , c , d ;
ans.clear();
      rep( i , n ){
cin >> a >> b >> c >> d ;
      p[i] = {point(a, b) , point(c,d)};
      }

          rep( i , n ){
          bool fl = 1 ;
          REP( j , i + 1 , n )
                if (intersectSegments(p[i].first, p[i].second, p[j].first, p[j].second )){
                 fl = 0 ;
                   break;
                }
                
            if (fl )
            ans.pb(i+1);
        }

        printf("Top sticks: ");
        for (i = 0; i < sz(ans)-1; ++i) printf("%d, ", ans[i]);
        printf("%d.\n", n);
    }
}
