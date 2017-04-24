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
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
int n,id, m ;
vi dd ;
struct com
{

    string s1 ;
    string s2 ;
    int pri ;
    int q ;
    com(string ss1, string ss2, int ppri, int qq)
    {
        s1 = ss1, s2 = ss2, pri = ppri, q = qq ;
    }
};
map < string, int > M ;
vector < com > v ;
bool valid (int  qaulity )
{
    dd.clear();
    dd.resize(id, -1 );

    rep( i, n)
    if (v[i].q >= qaulity )
    {
        if (dd[M[v[i].s1]] == -1 )
            dd[M[v[i].s1]] = v[i].pri ;
        else
            dd[M[v[i].s1]] = min (  dd[M[v[i].s1]],v[i].pri );
    }
    ll sum = 0 ;
   REP( i, 1,id )

    if (dd[i] == -1 ) return 0 ;
    else
        sum += dd[i];
    return sum <= m ;
}





int main()
{

    int  price, qaul ;
    string s1, s2 ;
    int tc ;
    cin >> tc ;
    while(tc--){
            v.clear();
    M.clear();
    cin >> n >> m ;
    int  mx = 0 ;
    id = 1 ;

   rep( i , n )
    {
        cin >> s1 >> s2 >> price >> qaul;
        if (M[s1] == 0 )
            M[s1] = id++;
        mx = max(mx, qaul);
        v.push_back(com(s1, s2, price, qaul));
    }

    ll s = 0 ;
    ll e = mx ;

    while (s < e)
    {
        ll mid = s + (e - s + 1) / 2;
        if (valid(mid))
            s = mid;
        else
            e = mid - 1;
    }
cout << s << endl;
}

}









