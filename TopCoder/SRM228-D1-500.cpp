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
the problem is a game consist of line of number and two player will play and each one can take from either end of line .
find the differnce between score of the first and second palyer .
it is a minimax game .  
so the first palyer need to add the chocen number to the second player score and then maximize the value returned to the second player   
and in the second turn it will subtract chosen number from the first score and then minimize the value returned to the first player 
*/


int dp[51][51] ; // state declared only by start and end not turn as every (s , e) contain only one value for turn . 
vi bags ;
int fun(int s, int e, bool turn )
{

    if (s > e  )
        return 0 ;
    if (dp[s][e] != -1000000000)return dp[s][e];
    if (turn) // first palyer turn 
    {
        return dp[s][e] = max( 
                              fun(s+1,e, !turn) + bags[s],
                              fun(s, e - 1, !turn ) + bags[e]
                          );
    }
    else
    {
        return dp[s][e] = min(
                              fun(s+1,e, !turn) - bags[s],
                              fun(s, e - 1, !turn ) - bags[e]
                          );
    }

}
class BagsOfGold
{
public :
    int netGain(vector <int> bags)
    {
        ::bags = bags;
        rep( i, 51 )
        rep( j, 51 )
        dp[i][j] = -1000000000;
        return fun(0,sz(bags)-1,1);
    }

};

/*

int main()
{

    //cout << fun(0,sz(bags)-1,1);
//freopen("b.txt", "wt", stdout);
}
*/

