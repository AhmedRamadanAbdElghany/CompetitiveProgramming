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
int dx[] = {1, 0,-1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0,-1,  1, -1, 1, -1};
bool  vis[100][100];
vector < string >  v;
int percent = 9 * 8 * 7 * 5 ;

/*
 you are given 2d grid and you want to move from start position and end position .
 every cell you visit cost you  1 / k where k is the number written in the cell and you can go as long as you want Costsum < 1 
 every time Costsum < 1 add 1 to the answer and start with cost equal cost of the cell you are currently in .
 so using dijestra to get from  strat position to end position with minimum answer .
 but using cost of every cell as 1 / k will give us WA because double precision .
 so to get rid of double as k between [ 1 , 9 ] so we can convert every cell cost to integer number 
 so cost of every cell will be (9 * 8 * 7 * 5 / k ) 
 
*/


struct fff
{
    int row;
    int col;
    int  mins;
    int cost;

    bool operator<(const fff &b) const
    {
        if (mins != b.mins ) return mins > b.mins;
        else return cost > b.cost;
    }
};


bool valid (int a, int b )
{
    return a >= 0 && b >= 0 && a < sz(v) && b < sz(v[0]) ;

}

class ExpensiveTravel
{
public:
    int minTime(vector <string> m, int startRow, int startCol, int endRow, int endCol)
    {
    int x, y, a, b ;

        v = m ;
        x = startRow - 1  ;
        y = startCol - 1 ;
        a = endRow - 1 ;
        b = endCol - 1 ;
        priority_queue < fff > q ;

        q.push((fff){x , y , 1 ,percent / (v[x][y]-'0')});
        if ( x == a  && y == b )
        return 0 ;


        while(q.empty() == 0 )
        {
            fff cur = q.top();
            q.pop();
            int t = cur.row ;
            int u = cur.col ;

            if (t == a && u == b ) return cur.mins;

        if ( v[t][u] == '1' || vis[t][u] ) continue;
        vis[t][u] = 1 ;

            //cout << t << " aaa " << u << "  " << cur.cost << "  " <<cur.mins<< endl;
            rep( i, 4 )
            {
                int tx = dx[i] + t ;
                int ty = dy[i] + u ;
                if (valid (tx, ty ) && v[tx][ty] != '1')
                {
                    int temp = cur.cost + percent / (v[tx][ty]-'0') ;
                    int val = cur.mins ;
                    
                    if (temp > percent )
                    {
                        val ++ ;
                        temp = percent/(v[t][u] -'0') + percent/(v[tx][ty] - '0');
                    }

                        q.push((fff){tx, ty ,val, temp });
                }
            }
        }
        return -1 ;
    }



};
/*
int main()
{
    int x=0, y=1, a =0, b=15 ;
    ExpensiveTravel t ;
   cout <<  t.minTime(	{"22334"},
1,
1,
1,
5)  ;
}

*/
