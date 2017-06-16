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
db dp [100][100];
bool vis [100][100];

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
given n numbers you can add or multiply any two numbers to get maximum ans .
think to try all cases of add and multiply for every range .
in case if you need to add 2 numbers of range greedly add the smallest number with largest one .
then memoize answer . 
*/



  vector<db>  v{1.5, 1.7, 1.6, 1.5};
 db fun(int s , int e ){
if (s == e ) return v[e]; // one element 
if ( s > e ) return 1 ; // invalid 
if (vis[s][e] )
    return dp[s][e];

db ch = fun( s + 1 , e ) * v[s]; 
ch = max(ch  ,  fun( s     , e - 1  ) * v[e]);
ch = max(ch  ,  fun( s + 1 , e-1 )  * (v[s]+v[e]));
vis[s][e] = 1 ;
dp[s][e] = ch;
return ch ;

}
class Nisoku{
public :
    double theMax(vector <double> cards){
    sort(all(cards));
    v = cards ;
    return fun(0 , sz(cards) - 1 );
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

}
*/
