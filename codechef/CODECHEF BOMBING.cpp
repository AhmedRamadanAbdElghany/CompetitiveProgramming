// WA

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
#define EPS 1e-8
#define MAX_VAL 500001
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

int start[MAX_VAL],endd[MAX_VAL];

void update(int T[], int idx, bool aug){
    for(int x = idx;x<=MAX_VAL;x += (x & -x))
        if(aug) ++T[x];
        else --T[x];
}

int F(int T[], int idx){
    int ret = 0;

    for(int x = idx;x>0;x -= (x & -x))
        ret += T[x];

    return ret;
}

int diff[2000000];

int main()
{
#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m,a, b ;
    char ch ;
    cin >> n >> m ;
    set < int > S;

    vector <pair < pair < int, int >, int> > p;
    vector < pair < char, pair < int, int > > > vv ;
    rep(i, m )
    {
        b = 0 ;
        cin >>ch >> a ;
        if (ch!='B')
            cin >> b ;

        if (ch == 'P')
        {
            S.insert(a);
            S.insert(b);
            p.pb({{a, b}, 0});
        }
        else if (ch == 'B')
            S.insert(a);
        else
        {
            a--;
            p[a].second +=b;
            S.insert(p[a].first.first + p[a].first.second);
            S.insert(p[a].first.second + p[a].first.second);
        }
        vv.pb({ch,{a,  b}});
    }

    rep( i , sz(p) )
    p[i].second = 0 ;
    vi num{all(S)};
    rep( i, sz(vv))
    {
        ch = vv[i].first ;
        a = vv[i].second.first ;
        b = vv[i].second.second;
        if (ch == 'P')
        {
  //          cout << endl << endl;
            int l = lower_bound(all(num), a )-num.begin()+1;
            int r = lower_bound(all(num), b )-num.begin()+1;
            int v = 1 ;
     update(start,l,true);
    update(endd,r,true);
                }
        else if (ch == 'M')
        {

//            cout << endl << endl;

            int aa = lower_bound(all(num), p[a].first.first + p[a].second  )-num.begin()+1;
            int bb = lower_bound(all(num), p[a].first.second+ p[a].second )-num.begin()+1;
            p[a].second += b ;

    update(start,aa,false);
    update(endd,bb,false);
            p[a].second += b;


             aa = lower_bound(all(num), p[a].first.first + p[a].second  )-num.begin()+1;
             bb = lower_bound(all(num), p[a].first.second+ p[a].second )-num.begin()+1;

    update(start,aa,1);
    update(endd,bb,1);

        }
        else
        {
            int l = lower_bound(all(num), a )-num.begin()+1;
          printf("%d\n",F(start,l)-F(endd,l-1));
       }
    }


}
