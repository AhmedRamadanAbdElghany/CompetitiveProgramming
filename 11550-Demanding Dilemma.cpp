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

int adj[20][100];
int main()
{

    int tc;
    scanf ("%d", &tc);
    while ( tc-- )
    {
        int n, m;
        scanf ("%d%d", &n, &m);

        rep( i, n )
        rep( j, m )
        scanf ("%d", &adj[i][j]);

        bool fl = 1 ;
        int  board[20][100] ;
        mem(board, 0 );
        rep( i, m)
        {
            int cnt = 0, first = -1, second = -1 ;
            rep( j, n )
            {
                cnt += adj[j][i] ;

                if ( cnt > 2 )
                {
                    fl = 0;
                    break;
                }

                if (adj[j][i]){
                    if (first == -1 )
                        first = j ;
                    else second = j ;
            }
        }
        if (cnt != 2 )
            fl = 0 ;
            if  (fl == 0 ) break;
            //cout << first << "  " << second << endl;

            if (board[first][second] == 0 )
                board[first][second] = board[second][first]=1 ;
            else
            {
                fl = 0 ;
                break ;
            }
        }



        if ( fl ) puts("Yes");
        else puts ("No");
    }

    return 0;


}

