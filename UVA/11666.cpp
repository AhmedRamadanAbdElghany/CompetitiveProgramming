#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
//#define MAX 5000000

int x[8] = {-1,1,-2,2,-2,2,-1,1};
int y[8] = {-2,-2,-1,-1,1,1,2,2};
/*
first equation :
ln(1 - x ) = -x - x^2/2 - x^3/3 - x^4/4 ..
second equation :
ln( x ) = L - x - x^2/2 - x^3/3 - x^4/4 ..
 
substitute first equation in the second one  :  
ln(n) = L + ln(1-x) .  
take (e) to two sides :
e ^ ln(n) = e ( L + ln(1-x)) .
e ^ ln(n) = ( e ^ L) * (e ^ ln(1-x)) .
n = e^L * (1-x) .
x = 1 - (n / e^L)      x < 1 .
*/


int main(void)
{

    int n ;
    while(cin >> n && n )
    {
        rep( i, 22 )
        {
            int L = i ;
            db e = exp(L);

            db x = 1 - (n / e ) ;
                    if (fabs(x) < 1.0){
                printf("%d %.8f\n", L, x);
                break;
            }
        }
    }
    return 0;
}
