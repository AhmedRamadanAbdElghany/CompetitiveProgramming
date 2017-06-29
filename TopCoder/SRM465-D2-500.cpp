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
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;

/*
length between every two points L , lenght of the first square is a and the second b .
if the two points in the same line vertically or horizontally then the sum of the half of each side must equal L <<<-- a / 2 + b / 2 = L .
else the sum < L <<<-- a / 2 + b / 2 < L as a / 2 will be greater than half of the side same for b / 2 .
so 
a / 2 + b / 2 <= L
a + b <= L * 2 .
L is Known so iterating for a and find b values  .

*/


long double dest(int x1, int y1, int x2, int y2)
{
    return sqrt(( x1 - x2 )*( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ));
}

class TurretPlacement
{
public:
    ll count(vector <int> x, vector <int> y)
    {
        ll ans = 0;
        rep( i, sz(x))
        REP(j, i+1, sz(y))
        {
            db s = dest(x[i], y[i], x[j], y[j])*2;
            REP(i, 1, s)
            ans += (s - i);
        }
        return ans;
    }
};
/*
int main()
{
    ios_base::sync_with_stdio(false);
TurretPlacement l;
cout << l.count(	{0, 2}, {0, 2});
}
*/

