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
typedef complex<int> point;
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
given n points in space find line with maximum number of points .
then for each point find slop with other points then points with the same slopes are considered on the same line .
*/


int n ;
int maxPoint(vector< point > points)
{
    n = sz(points);
    int ans = 0;
    map< pair < int, int >, int > slope;

    rep( i, n )
    {
        int  mx = 0, samePoints = 0, OnVerticalLine = 0;

        REP(j, i + 1, n )
        {
            if (points[i] == points[j]) // special case
                samePoints++;


            else if (points[i].X == points[j].X) // to prevent dividing by zero .
                OnVerticalLine++;

            else
            {
                int dify = points[j].Y - points[i].Y;
                int difx = points[j].X - points[i].X;
                int gcd = __gcd(difx, dify);

                difx /= gcd, dify /= gcd;
                slope[ {dify, difx}]++;
                mx = max(mx, slope[ {dify, difx}]); // find local maximum in the map
            }

        }
        mx = max(mx, OnVerticalLine);
        ans = max ( ans, mx + samePoints + 1 );
        slope.clear();
    }
    return ans;
}

int main()
{
    int tc ;
    cin >> tc ;
    int a, b ;
    string s ;
    getline(cin, s );
    getline(cin, s );
    char ch ;
    vector < point > v ;
    while(tc--)
    {
        v.clear();
        while(getline(cin, s ))
        {
            if (s == "")
                break;
            istringstream iss (s);
            iss >> a ;
            iss >> b ;

            v.pb(point (a, b ));
        }

        cout << maxPoint(v) << endl;
        if ( tc )
            puts("");
    }
}

