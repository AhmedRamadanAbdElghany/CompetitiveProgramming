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

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
two players every player can take k cards then every player order there cards and every card compare with it's oposite card .
and if the second palyer card is greater then his score increase with one .
we need max score the second player can get .
solution :
so take the minimum card in the second palyer and match it with the first greater than it from first player cards then next and so on ... 


*/
string aa="0123456789TJQKA";
int num(char ch ){
   return aa.find(ch) ;
   }
string bb="~CDSH";
int suit(char ch ){
   return bb.find(ch) ;
  }
int fun(string a ){
int x , y ;
x = num(a[0]);
y = suit(a[1]);
return x * 100000 + y ;
}

int main()
{
#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , x , tc ;
    string s ;
    int a[50] , b[50];
    cin >> tc ;
    while(tc --){
            mem(vis , 0 );
            cin >> n ;
    rep( i , n )
    cin >>s , a[i] = fun(s);
    rep( i , n )
    cin >>s , b[i] = fun(s);

    int cnt = 0 ;
  sort(a , a + n );
  sort(b , b + n );

int l = 0 , r = 0 ;
while(l < n && r < n ){
    if (b[l] > a[r])
   cnt++, l++ , r++ ;
else
    l++;
}
cout << cnt << endl;
    }
}
