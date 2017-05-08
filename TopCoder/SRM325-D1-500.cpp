/*

given n element and p val count number of x that will satisfy abs(v[i] - x) + abs (v[i+1] - x ) + ... <= p .
so we see that the limits of the answer has two boundry max val and min val and all the element between it are valid .
so we can find these two boundry using binary search or ternary search .
notice that if middle value of the array can't be valid then all the element  before and after it will not be valid as it 
give me value greater than p .
so first find two boundry in the array and find if there are element after upper bound that can be valid and element before lower bound 
that can be valid .
 
*/


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
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0,-1,  1, -1, 1, -1};
vi v 	;
ll p 	;
bool valid (ll val )
{
    ll sum = 0 ;
    rep( j, sz(v))
    sum += abs((ll)v[j] - val );
    return sum <= p;
}


class ModularInequality
{
public :
    int countSolutions(vector <int> A, int P)
    {
        v = A, p = P ;
        sort(all(v));
        int fir = -1, sec = -1;
        rep( i, sz(v) )
        if(valid(v[i]))
        {
            fir = i ;
            break;
        }


        for (int j = sz(v) -1 ; j >= 0 ; j -- )
            if (valid(v[j]))
            {
                sec = j ;
                break ;
            }
        if (fir == -1 )
            return 0;
        else
        {
            int ans = v[sec] - v[fir] + 1 ;

            ll s = v[sec], e = 10000000000000 ;
            while (s < e)   // last
            {
                ll mid = s + (e - s + 1) / 2;
                if (valid(mid))
                    s = mid;
                else
                    e = mid - 1;
            }
            ans += s - v[sec] ;
            e = v[fir] ;
            s =-10000000000000;
            while (s < e)  // first
            {
                ll mid = (s + (e - s) / 2);
                if (valid(mid))
                    e = mid;
                else
                    s = mid + 1;
            }
            return  ans + v[fir] - s;
        }
    }
};
/*
int main() {
}

}


*/

