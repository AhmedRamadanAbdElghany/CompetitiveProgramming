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
it is a string matching problem but here we need to match grid of char not only one string .
we can solve the problem with kmp or Z or brute force .
I solved here using brute force from every start try to match all the grid if all the grid mathced take the first matched character position
*/



vector < pair < int, int > > v ;
int main()
{
    int n1, n2, m1, m2 ;

    scanf("%d %d",&n1,&n2) ;

    char board[302][302] ;

    rep(i, n1)
    scanf("%s",board[i]) ;

    scanf("%d %d",&m1,&m2) ;
    vector<	vector < char > >  matched (m1,vector < char >(m2) );
    char tt[2008];
    rep(i, m1 )
    {
        scanf("%s",tt ) ;
        rep( j, m2 )
        matched[i][j] = tt[j];
    }


    int fl = 0 ;
    rep(i,m1 - n1+1)
    rep(j, m2 - n2+1)
    {
        if( matched[i][j] == board[0][0] )
        {
            fl = 1 ;
            int  a = i ;
            rep(k, n1)
            {
                int b = j;
                rep(p, n2 )
                {
                    if( matched[a][b] != board[k][p] )
                    {
                        fl = 0 ;
                        break ;
                    }
                    b++;
                }
                a++;
                if (fl == 0 ) break;
            }

            if( fl )
                v.pb({ i + 1, j + 1} ) ;
        }
    }
    if( v.empty() )
        printf("NO MATCH FOUND...\n") ;
    else
    {
        sort( v.begin( ), v.end( ) ) ;
        for (auto i : v )
            printf("(%d,%d)\n",i.first,i.second) ;
    }

}
