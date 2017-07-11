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
we have two n , m and need to find number of values that have last two significant bits are equal .
number of values between any of these numbers 100 ,200,300,400,500,600,700,800,900,1000,1100,1200 ,..
is 10 so find close values of these two n , m << nn , mm . 
and number of values between two close  values will be ( mm - nn ) / 10 . 

*/

bool valid (ll a )
{
    int u = a%10 ;
    a/=10;
    if (a==0)return 0;
    return a%10 == u ;
}


bool lastTwoZero (ll a )
{
    int u = a%10 ;
    a/=10;
    if (a==0)return 0;
    return (a%10 == u)&& u == 0 ;
}


class Dubs
{

public :
    long long count(long long n, long long m)
    {
        int cnt = 0 ;
        while( n <= m && ! lastTwoZero(n))
        {
            if (valid(n))
                cnt++ ;
            n++;
        }

        if ( n <= m )
            cnt++; // second condition

        while( n <= m && ! lastTwoZero(m))
        {
            if (valid(m))
                cnt++ ;
            m--;
        }
        cout << cnt + (m-n) / 10 ;

    }
};

int main(void)
{

}
