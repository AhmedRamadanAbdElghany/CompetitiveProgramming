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

/*
problme description :
given n words and you can learn k letters what is the maximum number of words you can read .
every word start by "anta" and end with "tica" .


sol description :
we have at most 26 charaters to learn and you must learn these chars [a,n,t,i,c] as they exist in all words so the reminder is 21 chars .
you can use brute force to take or leave every char of the 21 chars .
and compare the constructed string the given words .
*/



int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
int vis[26];
bool adj[50][26];
vector < string > v ;
void init() // mark all exist chars in every word.  
{
    rep( i, sz(v))
    rep(j,sz(v[i]) )
    adj[i][v[i][j]-'a'] = 1 ;
}

string f= "antic";
string s =""; // contain remainder chars out od f string .
int fun(string temp , int mask )
{
    rep(j, sz(temp))
    vis[temp[j]-'a'] = mask  ;
    int cnt = 0 ;
    rep( i, sz(v))
    {
        bool fl = 0 ;
        rep(j,26 )
        if (adj[i][j]== 0 )
            continue ;
        else if ( adj[i][j] == 1 &&  vis[j]!=mask )
        {
            fl = 1 ;
            break ;
        }
        if (fl == 0 )
            cnt++;
    }
    return cnt ;
}
class Teaching{
public :
    int count(vector <string> words, int k){
    k-= 5;
    if (k < 0 ) return 0 ;
    v = words ;
    
    rep( i, 26 )
    if (f.find(i+'a') == -1 )
        s.pb(i+'a');
    init();

    int mx = 0 ;
    for (int mask = 0; mask < (1<<21); mask++)
    {
        string temp="";
        for (int k = 0; k < 21 ; k++)
            if ((mask & (1<<k)))
                temp.pb(s[k]);
        if (sz(temp) != k )
            continue;
        mx = max(mx, fun(f+temp, mask +1));
    }
return mx ;

    }
};
/*
int main()
{

//#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
// freopen("a.txt", "wt", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

}
*/
