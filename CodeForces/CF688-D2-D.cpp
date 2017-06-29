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
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
//#define MAX 5000000



/*
given n numbers (ci) and k ;
we can know the answer of (x % ci) .
can you know the answer of ( x % k ) ?
factorizing k :
k = di^a * d(i+1)^b * d(i+2)^c  where di is prime number 
then convert di to co-oprime list .
so if we can know (x % gi) where gi is co-oprime number from the (x%ci) then we can know (x % k)
and if we know the value of (x%ci) we can know x value using Chinese remainder theorem .
*/

int vis[1000009];
vi factorization(ll n)
{
    vi primes;

    for (ll i = 2; i * i <= n; ++i)
    {
        int temp = 1 ;
        while (n % i == 0)
            temp *= i,  n /= i;
        if (temp > 1 )
            primes.pb(temp);
    }
    if (n >  1)
        primes.pb(n) ;
    return vi(all(primes));
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k, a ;
    cin >> n >> k;
    vi fact = factorization(k);
    rep(i, n )
    {
        cin >> a ;
        for (auto j : fact)
            if (a % j == 0 )
                vis[j] = 1 ;
    }


    for (auto j : fact)

        if (vis[j] == 0 )
        {
            puts("No");
            return 0;
        }
    puts("Yes");
}

/*
another solution 
lcm = __lcm(lcm , a ) ;
lcm %= k ;
*/








