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
#define OO ((ll)1e9)
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
typedef  vector < ll > row ;
typedef vector < row > matrix ;
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
#define mod 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;

/*
we have n points and line with length L start from (0 , 0) every point must have an exit at most at the distance D 
and we have to minimize exits.

don't put in mind the line itself (angle).
for every point find the length of lower point in the line with at most at distance D and the length of upper point in the line with at most D.
then the exit must be between them and the other points will determine the place if the exit if the share points between two segments.
then sort all segments upon upper point.
for set of segments that share points to some of them put exits point to the segment that share to all of the set .
*/


int main()
{
    vector < pair < db, db > > v ;  // lower and upper points .

    ios::sync_with_stdio(false);
    db l, d, a, b ;
    int n  ;
    while(cin >> l)
    {
        cin >> d >> n ;
        v.clear();
        rep( i, n )
        {
            cin >> a >> b ;
            v.push_back({ min( l,a + sqrt(d*d-b*b)), max(0.0, a - sqrt(d*d-b*b) )});
        }
        db minr =-100; // can't be 0 as d can be 0 and there is a point (0, 0) then the answer will be 0 
        int cnt = 0 ;
        sort(all(v));
        for (auto i : v )
            if (i.second > minr  )
            {
                cnt++;
                minr = i.first ;
            }

        cout << cnt << endl;
    }
}
