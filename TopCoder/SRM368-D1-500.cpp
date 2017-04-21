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
const double eps = 1e-8;
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
given some shapes each of them have some polylines each one consist of start and end and each 2 successive poly line have segment line between them .
if one polyline of one shape intersect with another shape so they will be 1 shape so return minimum number of shapes .
so for every shape try to find if there are two polylines intersect with each other and use DSU to get minimum number of shapes .



*/




struct edge
{
    int fromx, fromy, tox, toy, id;
    edge(int a, int b,int c, int d )
    {
        fromx = a, fromy = b, tox = c, toy = d  ;
    }
};
int par[200001];
int rank1[200001];
int find_parent(int a  )
{
    if ( a == par[a] ) return a;
    return par [a] = find_parent(par[a]);
}
void union_(int a, int b )
{
    if ( rank1[a] > rank1[b] )
        swap(a, b );
    par[a] = b ;
    if ( rank1[a] == rank1[b] ) rank1[b]++;
}
bool union_set(int a, int b )
{
    int p1 = find_parent(a), p2 = find_parent(b);
    if (p1 != p2 )
        union_(p1, p2);
    return p1 == p2;
}




bool isPointOnSegment(point a, point b, point c)
{
//    cout << a << " aa " << b << " aa " << c << " aa " ;

    if (c == a || c == b )
        return 1;
        
    int abdx = (b.X - a.X);
    int abdy = (b.Y - a.Y);
    int bcdx = (c.X - b.X);
    int bcdy = (c.Y - b.Y);

int dd = __gcd(abdx , abdy);
if ( dd != 0 ){
    abdx /= dd;
    abdy /= dd;
}
dd = __gcd(bcdx , bcdy);
if ( dd!= 0 ){
    bcdx /= dd;
    bcdy /= dd ;
}
return (
        abdx == bcdx && abdy == bcdy 
        && c.X >= min(a.X  , b.X) && c.X <= max(a.X  , b.X)
        && c.Y >= min(a.Y  , b.Y) && c.Y <= max(a.Y  , b.Y)
        ) ;
}


bool intersectSegments(point a, point b, point c, point d)
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
    {

        double w =  length(a-b), q = length(c - d );
        if (w < q )
            swap(a, c ), swap(b, d );
        if(isPointOnSegment(a, b, c ) || isPointOnSegment(a, b, d ))
            return 1 ;
        return false;
    }
    double t1 = d2 / d1, t2 = d3 / d1;

    if ( t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;
    return true;
}


class PolylineUnion{
public :
    int countComponents(vector <string> s){

         string f ="";
    rep( i, sz(s))
    f+= s[i];
    istringstream iss(f);
    string t ;
    int l = 0 ;
    s.clear();
    t = f ;

    rep( i, sz(t))
    if (t[i] == ' ')
    {
        string p = t.substr(l, i-l );
        l=i+1;
        s.pb(p);
    }
    else if (t[i] == ',' || t[i] == '-')
        t[i] = ' ';

    if (l!= sz(t))
    {
        string p = t.substr(l, sz(t)-l );
        s.pb(p);
    }

    int x, y,px, py ;
    vector < vector<edge> > edges(sz(s));
    rep( i, sz(s))
    {
        istringstream isss(s[i]);
        isss >> px >>  py;
        while( 1 )
        {
            if(isss >> x && isss >> y )
            {
                edges[i].pb(edge(px, py, x, y  ));
            //  cout << px << " " << py << "   " << x << " " << y << endl;
                px = x, py = y ;
            }
            else
            {
                edges[i].pb(edge(px, py, px, py ));

             // cout << px << " " << py << "   " << px << " " << py << endl;
               break;
            }
        }
     //   cout << endl << endl;
    }


    rep(i, sz(s))
    par[i] = i ;

    rep(i, sz(s))
    REP ( j,i+1, sz(s))
    {
        int a = find_parent(i), b = find_parent(j);
//cout << i << " " << a <<endl;
//cout << j << " " << b <<endl;
        if (a!= b )
        {
            int fl = 0;
            rep(k, sz(edges[i]))
            {
                rep(o, sz(edges[j]))
                if(intersectSegments(point(edges[i][k].fromx,edges[i][k].fromy  ), point(edges[i][k].tox, edges[i][k].toy),
                                     point(edges[j][o].fromx,edges[j][o].fromy ),  point(edges[j][o].tox,edges[j][o].toy )))
                {
       // cout << i << "  cc  "<< j << endl ,
        union_set(i, j);
        fl = 1 ;
                    break;
                }
                if (fl ) break;
            }
        }
    }

    rep(i, sz(s))
    find_parent(i);
    set<int> ss;
    rep(i, sz(s))
    ss.insert( par[i]);
    //cout << sz(ss) << endl;
return sz(ss);

    }
};




