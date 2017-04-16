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

/*
the problem give you two number in base b1 , b2 and need to sum two numbers in each base and compare results if similar print yes else no.
*/


string addInBaseB(string a1, string a2, int base )
{
    int cnt1 = sz(a1)-1,cnt2= sz(a2)-1, last = 0 ;
    string ret = "";
    while( cnt1 >= 0 && cnt2 >=0 )
    {
        int temp = ((a1[cnt1]-'0') + (a2[cnt2]-'0') + last)%base ;
        last = ((a1[cnt1]-'0') + (a2[cnt2]-'0') + last)/base;
        ret.push_back(temp+'0');
        cnt1--,cnt2--;
    }

    while( cnt1 >= 0|| cnt2>=0 )
    {
        int temp;
        if ( cnt2 >=0)
        {
            temp = ((a2[cnt2]-'0') + last)%base ;
            last = ((a2[cnt2]-'0') + last)/base;
        }
        else
        {
            temp =  ((a1[cnt1]-'0') + last)%base ;
            last =  ((a1[cnt1]-'0') + last)/base;
        }
        ret.push_back(temp+'0');
        cnt1--,cnt2--;
    }
    if (last)
        ret.pb(last+'0');

    int u = sz(ret) - 1;
    while(ret[u] == '0')
        u--;
    string f (ret.begin(), ret.begin()+(u+1));
    reverse(all(f));
    return ret ;
}

int main()
{
    string a1, a2 ;
    int b1, b2 ;
    int tc ;
    cin >> tc;
    while( tc-- )
    {
        cin >> a1 >> a2 >> b1 >> b2 ;
        string a = addInBaseB( a1, a2, b1 );
        string b = addInBaseB(a1, a2, b2 );
        if (a == b ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
