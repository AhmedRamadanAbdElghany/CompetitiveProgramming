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
int dx[] = {0,1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0,0, 1, 0,-1,  1, -1, 1, -1};
/*
it is a brute force problem I have 16 item and every item can take or leave so try all masks of 16 items ( 1 << 16 ) .
and for every mask try to satisfy all friends so for every one find if there is at least one item that your friend need or discard
exists in the mask .  

*/


int main() {
    char s[1000];
    int take[1000]  , cnt = 0;
    int leave  [1000] ;

    while(1) {
            int fl = 1 ;
            mem(take , 0 );
            mem(leave , 0 );
            cnt = 0 ;
        while(gets(s) && s[0] != '.' ) {
                int i = 0 ;
        while(s[i] != ';'){
            if(s[i] == '+')
                    take[cnt] |= 1 << (s[i+1]-'A');
                else
                    leave[cnt] |= 1<<(s[i+1]-'A');
            i+= 2 ;
            }
            cnt++;
        }

        if(cnt == 0)  break;

       rep( i , 1 << 16 ){
           int u = 0 ;
       rep(j , cnt){
                if (( i& take[j] ) == 0  && (((1 << 16 )-i-1) & leave[j]) == 0 ) // can't take or discard any element .
                {
                u = 1 ;
                break ;
                }
        }
    //        cout << i << "  " << u << endl;
            if(u == 0 ) {
                    fl = 0 ;
                cout << "Toppings: ";
             rep( j , 16 )
                    if(( i >> j ) & 1 )
                        cout << char(j+'A');
                puts("");
                break;
            }
        }

        if(fl == 1 )
            puts("No pizza can satisfy these requests.");
    }
    return 0;
}





