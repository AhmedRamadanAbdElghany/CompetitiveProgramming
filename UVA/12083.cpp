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

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};



/*
given n pupils each one has height , sex , sport , music if some equality of these occur you can take these two pupils 
find maximum number of pupils you can take .

if all condition is false then you can not take these two puplis .
so find every two that can not be taken and find maximum matching and the reminder will be maximum number you can take .



*/

int  N;
vector< vector < int >  > adj_list;
int  prevv[600];
bool mark[600];

bool find_match(int node)
{
    if (node == -1) return true;
    for (int i = 0; i < sz(adj_list[node]); i++)
    {
        int match = adj_list[node][i];
        if (mark[match]) continue;
        mark[match] = true;
        if (find_match(prevv[match]))
        {
            prevv[match] = node;
            return true;
        }
    }
    return false;
}

int max_matching()
{
    memset(prevv, -1, sizeof(prevv));
    int matching = 0;
    for (int i = 0; i < N; i++)
    {
        memset(mark, 0, sizeof(mark));
        if (find_match(i)) matching++;
    }
    return matching;
}



int main()
{

//#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
// freopen("a.txt", "wt", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, tc ;
    string b,c, d ;
    cin >> tc ;
    vi height;
    vector<string>sex, music,sport;
    vector < pair < int, int > > time ;
    while(tc--)
    {
        height.clear();
        sex.clear();
        music.clear();
        sport.clear();
        adj_list.clear();
        cin >> N ;
        adj_list.resize(N);
        rep( i, N )
        {
            cin >> a >> b >> c >> d ;
            height.pb(a);
            sex.pb(b);
            music.pb(c);
            sport.pb(d);
        }

        rep(i, N ) // move from i to j
        rep( j, N )

        if (abs(height[i]-height[j]) <= 40 &&
                sex[i] != sex[j] &&
                music[i] == music[j] &&
                sport[i] != sport[j]
           )
            if (sex[i] == "M" )
                adj_list[i].pb(j) ;
            else
                adj_list[j].pb(i) ;


        cout << N - max_matching() << endl;
    }
}
