// the code get presentation error 



///________________In THE NAME OF ALLAH________________\\\
//#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <string.h>
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<m;i++)
#define REP(i,k,m)      for(int i=k;i<m;i++)
#define repd(i,m)        for(int i=m;i>=0;i--)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define SORT(ptr , k )  sort ( ptr , ptr + k );
#define OO ((ll)1e12)
#define ooo -100000000
#define small  INT_MIN;
#define big  INT_MAX;
// #undef to remove macro
#include <cmath>
#include <complex>

using namespace std;
typedef long long ll;
typedef double db;
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<bool>       vb;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef bitset<20> MASK;
//typedef  pair < int, string > point ;
#define mo 1000000009
#define INF 10000
#define sz(v)          ((int)((v).size()))
//std::ios_base::sync_with_stdio(false); means  i will not deal with c lang that will speed
const int oo = (int) 1e9;
const double eps = 1e-7;
#define md 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};


const double PI  = acos(-1.0);

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
const double EPS = 1e-9;


/*

every string consist of another node .
so get path of the folder and put in the trie .
then dfs to get answer.
*/


struct node
{
    map <string, node>m;
    node() {}
    void inser(vector < string > v )
    {
        if (sz(v) == 0 ) return ;
        string u = v.back();
        v.pop_back();
        m[u].inser(v);
    }
    void dfs(string e )
    {
        for(auto i : m )
        {
            cout << e <<i.first  << endl;
            m[i.first].dfs( e + " ");
        }
    }
};

int main()
{
    //    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    char s[1500];
    string ts;
    while (scanf("%d", &n) == 1)
    {
        node root ;
        rep(i , n ){
            scanf("%s", s);
            for (int j = 0; s[j] ; j++)
                if (s[j] == '\\')
                    s[j] = ' ';
            stringstream cin(s);
            vector<string> data;
            while (cin >> ts)
                data.push_back(ts);
            reverse(all(data));
            root.inser(data);
        }
        root.dfs("");
        puts("");
    }
    return 0;
}
