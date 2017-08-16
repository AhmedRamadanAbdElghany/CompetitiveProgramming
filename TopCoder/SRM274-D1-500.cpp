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
#define EPS 1e-8

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
first check if word is not valid (have intial segment with y's equal or more than x's ) or have y's more than x's .
then for every valid string it may contain other valid strings so sort all child then put them with this order .
sorting is true as any child string can be swaped many time with others .
*/
class DyckwordUniformer
{

public :
    string uniform(string dyckword)
    {
        int cnt = 0 ;
        rep( i , sz(dyckword))
        {
            if (dyckword[i] == 'X')
                cnt++ ;
            else
                cnt--;
 
             if (cnt < 0 ) // not valid 
                return "";
        }
        
        if (cnt > 0 ) // not valid 
            return "";
            
        return fun(dyckword);
    }


     string fun(string dyckword ){
        if (dyckword == "")
            return "";
        int cnt = 0;
        int st = 0;
        vector < string > pp;
        
        rep(i, sz(dyckword))
        {
            if (dyckword[i] == 'X')
                ++cnt;
            else
                --cnt;
                
            if ( cnt == 0 )
                pp.pb(dyckword.substr(st, i - st + 1)), st = i + 1;
        }
        
        for (int i = 0; i < sz(pp); ++i)
            pp[i] = 'X' + fun( pp[i].substr(1, sz( pp[i]) - 2)) + 'Y';

        sort(all(pp));
        string ret ="";
        rep(i , sz(pp))
        ret +=(pp[i]);
        return ret;
    }
};

/*
int main()
{
#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    DyckwordUniformer k;
    cout << k.uniform("XXYXXYYY");
}
*/
