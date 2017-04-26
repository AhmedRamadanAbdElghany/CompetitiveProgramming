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
/*
you given i row of pascal triangle and and need to count how many element is divisable by d [2 , 6].
so you will need to generate all all element of the i row then check if every element is divisable by d or not 
but i up to 5000000 and generating all element will fit in time but there will be an overflow .
as d is very small for every element count number of primes that is divide d .
6 (2,3) , 4(2) , 5(5) , 3(3).
and count number of these primes in every element .
*/

int FactN_PrimePower(int n, int p) {
    int pow = 0;
    for(int i = p; i <= n ; i = i * p)
    	pow += n/i;

    return pow;
}
class PascalCount{
public :
    
int howMany(int n, int d){
int cnt = 0 ;
rep( i , n )

    if (d == 2 || d == 4 ){
        int a = FactN_PrimePower(n , 2 );
        a -= FactN_PrimePower(i , 2 );
        a -= FactN_PrimePower(n-i , 2 );
        if (d == 2 && a > 0 )
            cnt ++ ;
        else if ( d == 4 && a > 1 )
            cnt ++ ;
    }

    else  if (d == 6 ){
        int a = FactN_PrimePower(n , 2 );
        a -= FactN_PrimePower(i , 2 );
        a -= FactN_PrimePower(n-i , 2 );
        int b = FactN_PrimePower(n , 3 );
        b -= FactN_PrimePower(i , 3);
        b -= FactN_PrimePower(n-i , 3 );

        if ( a > 0 && b > 0 )
            cnt ++ ;
    }

    else if (d == 3 ){

        int b = FactN_PrimePower(n , 3 );
        b -= FactN_PrimePower(i , 3);
        b -= FactN_PrimePower(n-i , 3 );
        if (  b > 0 )
            cnt ++ ;
    }
    else if (d == 5 ){

          int b = FactN_PrimePower(n , 5 );
        b -= FactN_PrimePower(i , 5);
        b -= FactN_PrimePower(n-i , 5 );
        if (  b > 0 )
            cnt ++ ;

    }
return cnt ;

}

};
/*int main()
{
    int n , d  , cnt = 0 ;
cin >> n >> d ;
cout << cnt << endl;
}

*/
